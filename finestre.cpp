#include <ncurses.h>
#include <string>
#include <cstring>
#include "include/finestre.h"
#include "include/lang.h"
using namespace std;



	
	void finestre::mainwin_refresh(){
	
			char menu1[] = "BBBBB   OOOOO  M     M  BBBBB  EEEEE  RRRRR   M     M  AAAAA  N     N"; // definizione del titolo riga per riga
			char menu2[] = "B    B O     O MM   MM  B    B E      R    R  MM   MM  A   A  NN    N"; // fun fact: ogni lettera viene composta
			char menu3[] = "BBBBB  O     O M M M M  BBBBB  EEEE   RRRRR   M M M M  AAAAA  N N   N"; // dal suo corrispettivo maiuscolo.
			char menu4[] = "B    B O     O M  M  M  B    B E      R   R   M  M  M  A   A  N  N  N";
			char menu5[] = "BBBBB   OOOOO  M     M  BBBBB  EEEEE  R    R  M     M  A   A  N    NN";
			
			


			
			box( mainwin , 0 , 0 );  //Creazione della scatola generale di contenimento di tutto cio che verra rappresentato a schermo
			refresh();               //Refresh di tutto lo schermo, essenziale dopo la creazione della scatola perche si possa vedere
	 		
			mvaddstr( (scr_y - mainwin_y ) /2 + 2 , (scr_x - mainwin_x) /2 + 6 , menu1 ); //  Scrittura delle stringhe del titolo su schermo. (parametri: y , x , char*)  
			mvaddstr( (scr_y - mainwin_y ) /2 + 3 , (scr_x - mainwin_x) /2 + 6 , menu2 ); //  Importante il passaggio per puntatore ad un array di char
			mvaddstr( (scr_y - mainwin_y ) /2 + 4 , (scr_x - mainwin_x) /2 + 6 , menu3 ); //  per non imbattersi in problemi di conversione. (es. stringhe) 
			mvaddstr( (scr_y - mainwin_y ) /2 + 5 , (scr_x - mainwin_x) /2 + 6 , menu4 );
			mvaddstr( (scr_y - mainwin_y ) /2 + 6 , (scr_x - mainwin_x) /2 + 6 , menu5 ); 
					
			
			wrefresh (mainwin); // Refresh del contenuto all'interno della finestra principale,
	                            // in assenza del titolo sarebbe sufficiente a rinfrescare tutto cio che viene rappresentato.
	}
		
	bool finestre::initwin(){
		if ( init() ){
			mainwin_refresh();
			return true;
		}
		else return false;
	}

	void finestre::gameWin(lang &lingua ){
		
		gamewin_posy =  (scr_y - mainwin_y )/2 + 9 ; // Definizione delle coordinate della posizione dell'angolo in alto a sx
		gamewin_posx =  (scr_x - mainwin_x) /2 + (mainwin_x /8) ;
		
		finestraGioco = newwin( dim_y , dim_x , gamewin_posy , gamewin_posx ); // Definizione della variabile di tipo win
		box(finestraGioco , 0 ,0 ); // Creazione dei bordi della finestra 
		
		mvaddstr( gamewin_posy , gamewin_posx + 7 , lingua.time.c_str() ); // Stampa della scritta "tempo" in base alla lingua corrente
		mvaddstr( gamewin_posy + 2, gamewin_posx + 54 , lingua.money.c_str() ); // Stampa della scritta "soldi" in base alla lingua corrente
		
		wrefresh (finestraGioco); // Refresh interno della finestra da gioco 
		
	}

	bool finestre::init(){
				
				initscr();  // Inizializzazione schermo di dimensioni della finestra del terminale dal quale lo abbiamo avviato
				refresh();  // Refresh da prassi dello schermo (potenzialmente opzionale ma consigliato per essere sicuri di non avere cross-contamination)
				getmaxyx( stdscr , scr_y , scr_x );  // questa funzione prende come parametro una finestra ( stdscr nel nostro caso ) e due integer nei quali
													 // memorizzera le dimensioni massime di quella finestra 
				
				if (scr_y < mainwin_y || scr_x < mainwin_x ){  // La condizione dice: se le dimensioni del terminale sono inferiori a quelle definite
															   // per la finestra principale, entriamo nella condizione, altrimenti [-vedi else-]
				
					char fin_picc[] = "Finestra troppo piccola!";
					char cambia_dim[] =  "riavvia con dimensioni almeno 80x40";  //soliti array di char al posto di stringhe per un passaggio corretto
					
					mvprintw( scr_y /2 , (scr_x - strlen(fin_picc)) /2 , fin_picc );  // stampa della prima stringa centrata nello schermo del terminale.
					mvprintw( scr_y /2 + 1 , (scr_x - strlen(fin_picc)) /2 , cambia_dim ); // stampa della seconda stringa centrata.
					
					refresh();   // refresh di tutto lo schermo per stamparlo a schermo
					getch();     // attesa di conferma di ricezione da parte dell'utente
					endwin();    // chiusura della finestra principale 
					
					return false; // Restituzione di "false" , poiche all'interno del main questa condizione verra controllata per fare
				}				  // return 0 in caso di errori e poter terminare il programma automaticamente.
				
				else { // Altrimenti definisci la finestra principale e prosegui senza intoppi.
				
					mainwin = newwin(mainwin_y , mainwin_x , (scr_y - mainwin_y) /2 , ( scr_x - mainwin_x ) /2 );
					          // definizione della finestra principale, si occupa di contenere tutto cio che verra scritto a schermo in questo gioco
							  // definizione eseguita grazie alla funzione newwin che prende come parametri in ordine:
							  // Dimensione y , dimensione x della finestra che vogliamo creare
							  // Posizione y , Posizione x del punto in cui vogliamo che parta il puntatore che la disegnera (es: newwin(2,2,0,0) ci dara un quadrato 2x2)										
					return true; // Restituisce True per il check all'interno del main, uguale alla condizione contraria, solo che se 
					             // vero il programma continua nel modo inteso.
		
				}	
				
			}


