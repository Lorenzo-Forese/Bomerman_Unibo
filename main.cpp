#include <ncurses.h>
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

	if (!finestra.initwin()){     
		endwin();
		return 0;
	}

	else{
		int sel;
		lingua.initlang();

		do {
			sel = Selezioni.Scelte(finestra,lingua);
			switch ( sel ){
				case 0:{
					int score = 0;
					if (!game.inGame( finestra , lingua , score )){
						finestra.mainwin_refresh();
						mvaddstr( finestra.mainwin_y / 2 , (finestra.mainwin_x + strlen(lingua.insert_name.c_str())) / 2 , lingua.insert_name.c_str());
						char nome[100] ;
						timeout(-1);
						echo();
						getstr(nome);
						noecho();
						leaderboard.ScriviSuLeaderboard( nome , score );
						wclear(finestra.mainwin);
						wrefresh(finestra.mainwin);
						finestra.initwin();
					}
					
					break;
				}
				case 1:
					leaderboard.print_file_in_window(finestra.mainwin);
					refresh();
					getch();
				break;
				case 2:
					impostazioni.cambiolingua( lingua , finestra );
				break;
			}
			wrefresh(finestra.mainwin);
			finestra.initwin();
		}
		while ( sel != 3);
		endwin();
	}
	
	
	return 0;
	
}
