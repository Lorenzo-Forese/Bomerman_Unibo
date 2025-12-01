#include <random>
#include "include/mapparandom.h"
#include "include/finestre.h"
#include "include/rappresentazione.h"
using namespace std;

enum Caselle{ 
	// corrispondenze numeriche dei valori assegnati a nemici e mappa, ogni rappresentazione sulla mappa ha un valore int ben preciso,
	// ogni valore corrisponde a un corrispondente stampato, alcuni valori al loro interno contengono logica ulteriore.

	mappa_vuota = 0 , //mappa vuota ( rappresentata come erba )
	
	muro_distr = 1, //muro distuttibile
	
	muro_ind = 2, //muro indistruttibile

	protag = 3, //valore del protagonista, ovvero del personaggino che muoveremo nella mappa;

	// definiti anche in Ai.cpp i seguenti sono i valori dei nemici nei 4 stati possibili.

	KamiKaze_Attivo = 4,  //KamiKaze che deve ancora muoversi
	KamiKaze_Disattivo = 6, //KamiKaze che ha fatto la sua mossa del ciclo
	// La distinzione risulta necessaria per il metodo utilizzato nella gestione dei kamikaze, ovvero un check della loro presenza nella mappa,
	// l'esecuzione della mossa di movimento e il cambio di stato da Attivo a Disattivo.

	Bombarolo_Armato = 5, // Bombarolo che ha ancora la bomba da piazzare
	Bombarolo_Disarmato = 7, // Bombarolo "fifone" che ha piazzato la bomba
	// la distinzione risulta necessaria ma per una ragione diversa rispetto alla logica del KamiKaze, in breve il Bombarolo armato cerca il 
	// giocatore all'interno della mappa, mentre il bombarolo disarmato scappa verso un angolo casuale della mappa che cambia ad ogni ciclo.

	//per piu info sulle logiche dei nemici vedi Ai.cpp e include/Ai.h

	// quattro tick della bomba prima dell'esplosione. In questi quattro tick la bomba si alterna tra accesa e spenta:
	bombat1 = 8 , //spenta
	bombat2 = 9 , //accesa
	bombat3 = 10 , //spenta 
	bombat4 = 11 , //accesa

	esplosione = 12 , // se una casella ha questo valore, inizia il controllo dell'esplosione, vedi piu riguardo la logica dell'esplosione
					 // all'interno di printMappa.

	fuoco = 14 , // valore del fuoco generato dall'esplosione, il cambiamento viene effettuato secondo la logica implementata dopo il check
	             // del valore 12 sopra presente, ulteriori informazioni sempre in printMappa.

	oro = 15 , // Valore corrispondente all'oro lasciato sulla mappa su cui il protagonista potra' passare per riscuotere, la logica di questo
	           // check lo si trova all'interno di movimento.cpp

	porta = 16 , // Valore della porta di cambio livello e uscita dallo shop.

	luckyBoxPrezzoMin = 17 , // Valore Prezzo minimo della lucky box, 50$  
	luckyBoxPrezzoMax = 26 , // Valore Prezzo massimo della lucky box, 500$
	// La lucky box ha un valore corrispondente a un'intervallo per poter avere casualita nel prezzo e creare differenza tra una run e l'altra.
	// Il valore corrisponde a : ( luckyBox - 16 ) * 50 , quindi es: 17 - 16 = 1 , 1 * 50 = 50$.

	cuore = 27 , // Nella generazione casuale viene messo in conto anche l'ultimo valore di questo intervallo: il 27.
				 // Quindi corrispondente al prezzo massimo, ovvero 550$, abbiamo la risorsa piu' vitale del gioco.
				 // La scelta di renderlo l'oggetto piu' costoso e' motivata dal voler aumentare il livello di sfida.

				 // Ulteriori informazioni riguardanti alla logica di lucky box e cuore in movimento.cpp e printMappa 
				 //                                                                                  ( per vedere come sono rappresentati i cuori)


};

	// Generatori "casuali" di numeri , richiamati spesso da molte altre funzioni, il primo restituisce un'int compreso tra i due parametri dati,
	// il secondo un Boolean con probabilita' pari all'intervallo 0-1 del float fornito, es: 0.5 = 50% , 0.9 = 90% , 0.1 = 10% etc..

	int mappaRandom::randInt(int a , int b) { 
	
		mt19937 generator(rd()); // Mersenne Twister generator
		
		uniform_int_distribution<int> dist( a , b );
		
		return ( dist (generator) );
		
	}

	bool mappaRandom::randBool(float prob){
	
		mt19937 generator(rd()); // Mersenne Twister generator
		
		bernoulli_distribution distribution(prob); 
		
		return (distribution (generator) );
		
	}


	// Generazione casuale della mappa, con definizione preimpostata della posizione dei muri indistruttibili, ma con casualita' di quelli 
	// distruttibili. La probabilita' di muri aumenta con la difficolta' del gioco, quindi ad ogni livello.
	
	int mappaRandom::randMappa( float prob ){ 
                                             
	for(int i = 1 ; i <= 15 ; i++ ){   // valore max delle ascisse della matrice mappa[][] degli spazi non occupati.
	
		for(int j = 1 ; j<= 7 ; j++){  // valore max delle ordinate della matrice mappa[][] degli spazi non occupati.
		
			if ( i %2 != 0 || j%2 != 0){  // se sia le ascisse che le ordinate sono dispari, la poszione corrispondera' per forza a un muro ind.

				mappa[j][i] = randBool ( prob );  // Decisione casuale di definizione tra muro distr. o spazio vuoto, come spiegato sopra, 
												  // 0 corrisponde a spazio vuoto e 1 a muro distr. quindi non abbiamo bisogno di 
												  // utilizzare il generatore di integer, ci basta quello booleano.

			}
		}
	}
	int spawnCorner = randInt( 0 , 3);  // definizione casuale (stavolta con generatore di integer, da 0 a 3 ) dell'angolo di spawn.

	spawn (spawnCorner); // Check necessario per garantire il corretto spawn all'interno della mappa, vedi funzione sotto.
	
	return spawnCorner; // return dell'angolo di spawn, il motivo viene descritto in inGame.cpp
}
	
		void mappaRandom::spawn(int spawnCorner){  // Creazione dello spazio necessario al player per uscire dallo spawn senza danneggiarsi.
												   // Quando viene definito l'angolo di spawn del player, assieme ad esso viene generata uno
												   // spazio a forma di "L" per lasciargli piazzare la prima bomba senza danneggiarsi da solo.
			if ( spawnCorner == 0){ //alto sx
				
				mappa[1][1] = protag ;
				mappa[1][2] = mappa_vuota ;
				mappa[2][1] = mappa_vuota ;	
						
			}
				
			if ( spawnCorner == 1){ //alto dx
			
				mappa[1][15] = protag ; 
				mappa[1][14] = mappa_vuota ; 
				mappa[2][15] = mappa_vuota ;
		
			}
				
			if ( spawnCorner == 2){ //basso sx
					
				mappa[7][1] = protag ;
				mappa[7][2] = mappa_vuota ; 
				mappa[6][1] = mappa_vuota ;
					
			}
				
			if ( spawnCorner == 3){ //basso dx
					
				mappa[7][15] = protag ;
				mappa[7][14] = mappa_vuota ;
				mappa[6][15] = mappa_vuota ;
		
			}
		}

	void mappaRandom::randShop(){ 
	for(int i = 1 ; i <= 15 ; i++ ){   //**IMPORTANTE** Questo doppio ciclo sara' molto frequente in tantissime funzioni, con piccole variazioni qua' e la'
		for(int j = 1 ; j<= 7 ; j++){  // ma la logica di base rimane la stessa: controllo su tutta la matrice (con alcune esclusioni in base al contesto...)
			if ( i %2 != 0 || j%2 != 0){
			
				mappa[j][i] = 0; //iniziale refresh totale di tutte le caselle che non sono muri ind.
			}
		}
	}
	for (int i = 2; i <= 14 ; i = i + 2){ // questo ciclo ci serve a stampare casualmente in dei punti specifici nella mappa, ovvero sotto le 
		if ( i == 8 ) i = i + 2;		  // prime colonne, evitando quella centrale per migliore estetica
		 								  // e per evitare di comprare per sbaglio mentre si vuole andare all'uscita.
		mappa[3][i] = randInt( luckyBoxPrezzoMin , cuore ); // la logica apparentemente inusuale della gestione delle luckybox 
	}								  						// e cuori ci permette di semplificarne di molto la generazione randomica.
	mappa[1][8] = porta ; //Uscita dallo shop
	mappa[5][8] = protag ; //Posizione del protagonista
}


	void mappaRandom::printMappa( finestre &finestra , int &numNemici ,int &score , int timeLeft){
	//Questa e' la funzione piu complessa di tutto il progetto poiche' si occupa contemporaneamente di moltissima logica e di rappresentazioni
	//della stessa logica implementata. si divide in due parti, la prima in cui vengono stampate informazioni riguardanti il giocatore,
	//la seconda in cui viene fatto un check completo su tutta la matrice per controllarne tutti i valori.

	//PRIMA PARTE:
	
		rappresentazione r; // definizione classe rappresentazione come "r" per comodita'
		
		int pos_soldi_x =  finestra.gamewin_posx + 53 ; //definizione della posizione x e y in cui scrivere il valore dei soldi su schermo.
		int pos_soldi_y =  finestra.gamewin_posy + 3 ;
		
		mvaddstr( finestra.gamewin_posy , finestra.gamewin_posx + 13 , "     "); // creazione dello spazio sulla finestra di gioco per la :
		mvprintw( finestra.gamewin_posy , finestra.gamewin_posx + 13 , "%d" , timeLeft); // scrittura a schermo del tempo rimanente.

		int cuoriDisplayed = 0; //definizione della variabile corrispondente al numero di cuori mostrati a schermo

		init_pair(7 , COLOR_YELLOW , COLOR_BLACK); // definizione colore dei soldi
		init_pair(8 , COLOR_RED , COLOR_BLACK); // definizione colore dei cuori
		
		attron (COLOR_PAIR(7)); // colore soldi - on
		
		mvaddch( pos_soldi_y  , pos_soldi_x , '$'); // aggiunge $all'inizio del valore dei soldi.
		
		for ( int i = 1 ; i <= 4 ; i ++ ){
			mvaddch( pos_soldi_y , pos_soldi_x + i , ' '); // cancella i soldi a ogni iterazione per evitare confusione: quando il valore cambia
														   // rimuove tracce di valori precedenti. Es: 525 - 500, rimrrebbe il 5 finale.
		}
		
		mvprintw( pos_soldi_y , pos_soldi_x  + 1 , "%d" , soldi); // stampa dei soldi
		attroff (COLOR_PAIR(7)); // colore soldi - off

			for(int y = 0 ; y <= 21 && cuoriDisplayed < numVite ; y++){  // finche' i cuori stampati sono inferiori al limite verticale della finestra e
									// condizione utile per uscire prima dal ciclo esterno.					 
				for ( int x = 0 ;  x <= 7  ; x++ ){ //limite orizzontale dei cuori
					if ( cuoriDisplayed < numVite ) {  // numVite sono le vite effettive, cuoriDisplayed quelli rappresentati.

						attron(COLOR_PAIR(8) ); // colore cuori - on

						mvaddch( pos_soldi_y + 3 + y , pos_soldi_x + x, '+'); // per non dover definire un'altra variabile, usiamo la posizione dei soldi e incrementiamo su quella

						attroff(COLOR_PAIR(8) ); // colore cuori - off

						cuoriDisplayed++; //aumento cuori rappresentati.

						}

						else mvaddch( pos_soldi_y + 3 + y , pos_soldi_x + x, ' '); //altrimenti disegna spazi vuoti, cio' serve a mostrare anche quando si perdono vite.
				}
			}

		mvprintw ( pos_soldi_y + 2 , pos_soldi_x, "%d" , score); // Stampa del valore attuale del punteggio ( dato che non diminuisce, 
																 // non dobbiamo crearne lo spazio ogni refresh. )
		
		

		int y = finestra.gamewin_posy + 1;  //inizializzazione della posizione iniziale delle ordinate della mappa
		
		for ( int j = 0 ; j <= 8 ; j++){   // Ciclo delle ascisse 
			int x = finestra.gamewin_posx + 1;
				for ( int i = 0 ; i <= 16 ; i++){  //ciclo delle ordinate
					// I seguenti sono check equivalenti al loro valore numerico all'interno della matrice della mappa, viene richiamata la
					// funzione stampa'nome' della classe rappresentazione ( qui soprannominata come "r" ).
					if ( mappa[j][i] == muro_ind ) r.stampaMuro(x,y) ;  
					
					else if ( mappa[j][i] == protag ) r.stampaProtag(x,y) ;
					
					else if ( mappa[j][i] == KamiKaze_Attivo ) r.stampaKamiKaze(x,y);
					
					else if ( mappa[j][i] == KamiKaze_Disattivo ) r.stampaKamiKaze(x,y);
					
					else if ( mappa[j][i] == Bombarolo_Armato ) r.stampaBombarolo(x,y) ;
					
					else if ( mappa[j][i] == Bombarolo_Disarmato ) {  // Per dare l'apparenza di un'animazione, facciamo un check su ogni casella 
																	  // per alternare la posizione delle braccia.
						if( j % 2 == 0 || i % 2 == 0 ) r.stampaBombaroloDisarmato1(x,y);

						else r.stampaBombaroloDisarmato2(x,y);
					} 

					else if ( mappa[j][i] == mappa_vuota ) r.stampaErba(x,y) ;

					else if ( mappa[j][i] == bombat1 ) { r.stampaBomba_1(x,y) ; mappa[j][i] = bombat2 ; }  // Ad ogni tick del gioco, la bomba
					else if ( mappa[j][i] == bombat2 ) { r.stampaBomba_2(x,y) ; mappa[j][i] = bombat3 ; }  // aumenta di uno stato fino ad 
					else if ( mappa[j][i] == bombat3 ) { r.stampaBomba_1(x,y) ; mappa[j][i] = bombat4 ; }  // esplodere.
					else if ( mappa[j][i] == bombat4 ) { r.stampaBomba_2(x,y) ; mappa[j][i] = esplosione ; }

					// Quella che segue e' la logica della gestione delle esplosioni: per ogni direzione viene fatto un ciclo che controlla
					// diverse cose :
					// 1 : se il muro e' distruttibile, aumenta di 10 il punteggio.
					// 2 : se il muro e' indistruttibile interrompe il ciclo.
					// 3 : se in quella pos. c'e' il protagonista, diminuisce le vite e interrompe il ciclo.
					// 4 : se in quella pos. c'e' un KamiKaze, cambia quel posto in oro, riduce il conteggio dei nemici, aumenta il punteggio di 30 e interrompe il ciclo.
					// 5 : se in quella pos. c'e' un Bombarolo, cambia quel posto in oro, riduce il conteggio dei nemici, aumenta il punteggio di 50 e interrompe il ciclo.
					// 6 : se il ciclo non viene interrotto stampa in quella posizione fuoco e procede in quella direzione.
					
					else if ( mappa[j][i] == esplosione ) { // Direzione verso il basso
					
					for (int b = 1 ; b <= potenzaBombe ; b++){  
					
						if ( mappa[j - b][i] == muro_distr ) score = score + 10;
						
						if ( mappa[j - b][i] == muro_ind ) { break ;}
						
						if ( mappa[j - b][i] == protag ) { numVite -- ; break; }
						
						if ( mappa[j - b][i] == KamiKaze_Attivo || mappa[j - b][i] == KamiKaze_Disattivo ){ mappa [j - b][i] = oro ; numNemici -- ; score = score + 30 ; break;}
						if ( mappa[j - b][i] == Bombarolo_Armato || mappa[j - b][i] == Bombarolo_Disarmato ){ mappa [j - b][i] = oro ; numNemici -- ; score = score + 50 ; break;}

					 	r.stampaFuoco ( x , y - (b*3));

					 	mappa[j - b][i] = fuoco ; 

						}

					for (int b = 1 ; b <= potenzaBombe ; b++){ // Direzione verso l'alto

						if ( mappa[j + b][i] == muro_distr ) score = score + 10;

						if ( mappa[j + b][i] == muro_ind ) { break; };

						if ( mappa[j + b][i] == protag ) { numVite -- ; break; }

						if ( mappa[j + b][i] == KamiKaze_Attivo || mappa[j + b][i] == KamiKaze_Disattivo ){ mappa [j + b][i] = oro ; numNemici -- ; score = score + 30 ; break;}
						if ( mappa[j + b][i] == Bombarolo_Armato || mappa[j + b][i] == Bombarolo_Disarmato ){ mappa [j + b][i] = oro ; numNemici -- ; score = score + 50 ; break;}

						r.stampaFuoco ( x , y + (b*3) );

						mappa[j + b][i] = fuoco ;

						}

					for (int b = 1 ; b <= potenzaBombe ; b++){ // Direzione verso sinistra

						if ( mappa[j][i - b] == muro_distr ) score = score + 10;

						if ( mappa[j][i - b] == muro_ind ) { break;}

						if ( mappa[j][i - b] == protag ) { numVite -- ; break;}

						if ( mappa[j][i - b] == KamiKaze_Attivo || mappa[j][i - b] == KamiKaze_Disattivo ){ mappa [j][i - b] = oro ; numNemici -- ; score = score + 30 ; break;}
						if ( mappa[j][i - b] == Bombarolo_Armato || mappa[j][i - b] == Bombarolo_Disarmato ){ mappa [j][i - b] = oro ; numNemici -- ; score = score + 50 ; break;}

						r.stampaFuoco ( x - (b*3) , y );

						mappa[j][i - b] = fuoco ;

						}

					for (int b = 1 ; b <= potenzaBombe ; b++){ // Direzione verso destra

						if ( mappa[j][i + b] == muro_distr ) score = score + 10;

						if ( mappa[j][i + b] == muro_ind ){ break ; }

						if ( mappa[j][i + b] == protag ){ numVite -- ; break ;}

						if ( mappa[j][i + b] == KamiKaze_Attivo || mappa[j][i + b] == KamiKaze_Disattivo ){ mappa [j][i + b] = oro ; numNemici -- ; score = score + 30 ; break;}
						if ( mappa[j][i + b] == Bombarolo_Armato || mappa[j][i + b] == Bombarolo_Disarmato ){ mappa [j][i + b] = oro ; numNemici -- ; score = score + 50 ; break;}

						r.stampaFuoco ( x + (b*3) , y );

						mappa[j][i + b] = fuoco ;

						}

					mappa[j][i] = fuoco ;

					r.stampaFuoco (x,y); // Caso base ( posizione della bomba iniziale )

					}

					else if(mappa[j][i] == fuoco ){   // Nel tick sucessivo all'esplosione, viene tolto il fuoco dalle posizioni.
						mappa [j][i] = mappa_vuota ;
					}

					else if(mappa[j][i] == oro ){  
						r.stampaOro(x,y);
					}

					else if(mappa[j][i] == porta ){
						r.stampaPorta(x,y);
					}

					else if( mappa[j][i] >= luckyBoxPrezzoMin && mappa[j][i] <= luckyBoxPrezzoMax ){ 
						r.stampaLuckyBox( x , y , mappa[j][i] - 16 );  // il terzo parametro rappresenta il prezzo, come spiegato in enum
					}

					else if( mappa[j][i] == cuore ){
						r.stampaCuore(x,y);
					}

					else r.stampaMuroDistr(x,y);  // Caso base 

					x = x+3;  // Incremento di 3 perche' la matrice di gestione logica e' 9x17, mentre quella rappresentata e' tre volte 
				}			  // piu' grande per una qualita' grafica migliore.	

			y = y + 3;  // uguale per x

		}

	}


