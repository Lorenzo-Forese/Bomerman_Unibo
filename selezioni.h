#ifndef SELEZIONI_H
#define SELEZIONI_H
#include "lang.h"
#include <ncurses.h>
#include <cstring>
using namespace std;


class selezioni{
public:
	int Scelte(finestre mainwin, lang lingua);
	int scelta = 0;
private:

	void evidenziato(finestre mainwin,lang lingua){

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
	
		
};
#endif
