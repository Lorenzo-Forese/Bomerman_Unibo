#include <ncurses/curses.h>
#include "include/lang.h"
#include "include/mapparandom.h"
#include "include/finestre.h"
#include "include/selezioni.h"
#include "include/impostazioni.h"
#include "include/inGame.h"
#include "include/leaderboard.h"
using namespace std;

int main(){
	// Definizione di tutte le classi necesasrie.
	lang lingua;
	finestre finestra ;
	selezioni Selezioni ;
	impostazioni impostazioni;
	leaderboard leaderboard;
	game game;
	

	noecho(); // No rappresentazione degli input da tastiera 

	if (!finestra.initwin()){  // check delle dimensioni corrette della finestra del terminale
		endwin();
		return 0;
	}

	else{
		int sel;
		lingua.initlang();  //inizializzazione lingua

		do {
			sel = Selezioni.Scelte(finestra,lingua);  //inizializzazione posizione della scelta menu
			switch ( sel ){
				case 0:{
					int score = 0;
					if (!game.inGame( finestra , lingua , score )){ //check se ci si trova in partita, appena ritorna false, inizia ad eseguire ciò che segue:
						finestra.mainwin_refresh(); //refresh totale
						mvaddstr( finestra.mainwin_y / 2 , (finestra.mainwin_x + strlen(lingua.insert_name.c_str())) / 2 , lingua.insert_name.c_str()); //aggiunta della stringa che chiede il nome
						char nome[100] ;
						timeout(-1);
						echo();
						getstr(nome);
						noecho(); // in ordine, definizione della variabile e aspettare finchè l'utente non ha terminato di scrivere, poi inserimento della variabile
						leaderboard.ScriviSuLeaderboard( nome , score );  //scrittura su leaderboard
						wclear(finestra.mainwin); //clear della finestra da gioco
						wrefresh(finestra.mainwin); //refresh come prima
						finestra.initwin(); //inizializzazione finestra nuovamente
					}
					
					break;
				}
				case 1: //opzione leaderboard
					leaderboard.print_file_in_window(finestra.mainwin); // scrittura della leaderboard
					refresh();
					getch();
				break;
				case 2: //opzione impostazioni
					impostazioni.cambiolingua( lingua , finestra );
				break;
			}
			wrefresh(finestra.mainwin);
			finestra.initwin();
		}
		while ( sel != 3); // opzione esci
		endwin();
	}
	
	
	return 0;
	
}
