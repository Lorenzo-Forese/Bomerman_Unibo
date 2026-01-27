#include <ncurses/curses.h>
#include "include/lang.h"
#include "include/finestre.h"
#include <cstring>
#include "include/selezioni.h"

using namespace std;


int selezioni::Scelte(finestre finestre, lang lingua){
	int ch;
	noecho();
	for (int i = 3 ; i != -1 ; i--){
		scelta = i;
		evidenziato(finestre , lingua);
	}
	while ( (ch = getch()) != 'j' ){
		switch(ch){
			case 'w':
				scelta--;
				evidenziato( finestre  , lingua );
				refresh();
			break;

			case 's':
				scelta++;
				evidenziato( finestre , lingua );
				refresh();
			break;
		}
	}
	return (scelta);
}

void selezioni::evidenziato(finestre mainwin,lang lingua){

	int newgame_posy = (mainwin.scr_y - mainwin.mainwin_y ) /2 + 19;
	int leaderboard_posy = (mainwin.scr_y - mainwin.mainwin_y ) /2 + 21;
	int settings_posy = (mainwin.scr_y - mainwin.mainwin_y ) /2 + 23;
	int quit_posy = (mainwin.scr_y - mainwin.mainwin_y ) /2 + 25;
	
	
	if (scelta == 4) scelta = 0;
	if (scelta == -1) scelta = 3;	
			switch (scelta){
				case 0:
					mvaddstr( quit_posy , (mainwin.scr_x - strlen(lingua.quit_game.c_str())  ) /2 , lingua.quit_game.c_str());
					mvaddstr( leaderboard_posy , (mainwin.scr_x - strlen(lingua.leaderboard.c_str()) ) /2 , lingua.leaderboard.c_str());
					attron( A_REVERSE | A_BOLD ); 
					mvaddstr( newgame_posy , (mainwin.scr_x - strlen(lingua.newgame.c_str())  ) /2 , lingua.newgame.c_str() );
					attroff( A_REVERSE | A_BOLD );
				break;
				case 1:
					mvaddstr( newgame_posy , (mainwin.scr_x - strlen(lingua.newgame.c_str())  ) /2 , lingua.newgame.c_str() );
					mvaddstr( settings_posy , (mainwin.scr_x - strlen(lingua.settings.c_str())  ) /2 , lingua.settings.c_str() );
					attron( A_REVERSE | A_BOLD );
					mvaddstr( leaderboard_posy , (mainwin.scr_x - strlen(lingua.leaderboard.c_str())  ) /2 , lingua.leaderboard.c_str());
					attroff( A_REVERSE | A_BOLD );
				break;
				case 2:
					mvaddstr( leaderboard_posy , (mainwin.scr_x - strlen(lingua.leaderboard.c_str())  ) /2 , lingua.leaderboard.c_str());
					mvaddstr( quit_posy , (mainwin.scr_x - strlen(lingua.quit_game.c_str())  ) /2 , lingua.quit_game.c_str());
					attron( A_REVERSE | A_BOLD );
					mvaddstr( settings_posy , (mainwin.scr_x - strlen(lingua.settings.c_str())  ) /2 , lingua.settings.c_str() );
					attroff( A_REVERSE | A_BOLD );
				break;
				case 3:
					mvaddstr( newgame_posy , (mainwin.scr_x - strlen(lingua.newgame.c_str())  ) /2 , lingua.newgame.c_str() );
					mvaddstr( settings_posy , (mainwin.scr_x - strlen(lingua.settings.c_str()) ) /2 , lingua.settings.c_str());
					attron( A_REVERSE | A_BOLD ); 
					mvaddstr( quit_posy , (mainwin.scr_x - strlen(lingua.quit_game.c_str()) ) /2 , lingua.quit_game.c_str() );
					attroff( A_REVERSE | A_BOLD );
				break;
				}
		}
	
