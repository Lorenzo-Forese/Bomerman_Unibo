#include <ncurses.h>
#include "mapparandom.h"
#include "finestre.h"
#include "selezioni.h"
#include "lang.h"
#include "impostazioni.cpp"
#include "inGame.cpp"
#include "leaderboard.cpp"
using namespace std;

int main(){
	start_color();
	use_default_colors();
	init_color( COLOR_WHITE, 600, 600, 600);
	lang lingua;
	finestre finestra ;
	selezioni Selezioni ;
	impostazioni impostazioni;
	noecho();
	raw();
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
					if (!inGame( finestra , lingua , score )){
						finestra.mainwin_refresh();
						mvaddstr( finestra.mainwin_y / 2 , (finestra.mainwin_x + strlen(lingua.insert_name.c_str())) / 2 , lingua.insert_name.c_str());
						char nome[100] ;
						timeout(-1);
						echo();
						getstr(nome);
						noecho();
						ScriviSuLeaderboard( nome , score );
						wclear(finestra.mainwin);
						wrefresh(finestra.mainwin);
						finestra.initwin();
					}
					
					break;
				}
				case 1:
					print_file_in_window(finestra.mainwin);
					refresh();
					getch();
				break;
				case 2:
					impostazioni.cambiolingua(lingua , finestra );
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
