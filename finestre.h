#ifndef FINESTRE_H
#define FINESTRE_H
#include "lang.h"
#include <ncurses.h>
#include <cstring>
class finestre{

WINDOW *create_newwin(int height, int width , int starty, int startx);

public:
	WINDOW* mainwin;
	WINDOW* finestraGioco;

	int dim_x = 64 , dim_y = 29 ;

	int soldi = 30;
	
	int scr_x , scr_y , mainwin_x = 80 , mainwin_y = 40; // scr_x = larghezza del terminale nel quale viene aperto il gioco													 // scr_y = altezza del termninale nel quale viene aperto il gioco.
															 // mainwin_x e mainwin_y = larghezza e altezza della finestra principale,
															 // maggiori dettagli di cosa tratta in mainwin_refresh().	
	int gamewin_posx , gamewin_posy;
	void mainwin_refresh();

	bool initwin();

	void gameWin(lang &lingua );

private:
	
	
		bool init(){
			
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
};
#endif
