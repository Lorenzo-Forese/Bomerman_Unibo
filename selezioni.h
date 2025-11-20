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

	if (scelta == 4) scelta = 0;
	if (scelta == -1) scelta = 3;	
			switch (scelta){
				case 0:
					mvaddstr( 25, (mainwin.scr_x - strlen(lingua.quit_game.c_str())  ) /2 , lingua.quit_game.c_str());
					mvaddstr( 21, (mainwin.scr_x - strlen(lingua.leaderboard.c_str()) ) /2 , lingua.leaderboard.c_str());
					attron( A_REVERSE | A_BOLD ); 
					mvaddstr( 19, (mainwin.scr_x - strlen(lingua.newgame.c_str())  ) /2 , lingua.newgame.c_str() );
					attroff( A_REVERSE | A_BOLD );
				break;
				case 1:
					mvaddstr( 19, (mainwin.scr_x - strlen(lingua.newgame.c_str())  ) /2 , lingua.newgame.c_str() );
					mvaddstr( 23, (mainwin.scr_x - strlen(lingua.settings.c_str())  ) /2 , lingua.settings.c_str() );
					attron( A_REVERSE | A_BOLD );
					mvaddstr( 21, (mainwin.scr_x - strlen(lingua.leaderboard.c_str())  ) /2 , lingua.leaderboard.c_str());
					attroff( A_REVERSE | A_BOLD );
				break;
				case 2:
					mvaddstr( 21, (mainwin.scr_x - strlen(lingua.leaderboard.c_str())  ) /2 , lingua.leaderboard.c_str());
					mvaddstr( 25, (mainwin.scr_x - strlen(lingua.quit_game.c_str())  ) /2 , lingua.quit_game.c_str());
					attron( A_REVERSE | A_BOLD );
					mvaddstr( 23, (mainwin.scr_x - strlen(lingua.settings.c_str())  ) /2 , lingua.settings.c_str() );
					attroff( A_REVERSE | A_BOLD );
				break;
				case 3:
					mvaddstr( 19, (mainwin.scr_x - strlen(lingua.newgame.c_str())  ) /2 , lingua.newgame.c_str() );
					mvaddstr( 23, (mainwin.scr_x - strlen(lingua.settings.c_str()) ) /2 , lingua.settings.c_str());
					attron( A_REVERSE | A_BOLD ); 
					mvaddstr( 25, (mainwin.scr_x - strlen(lingua.quit_game.c_str()) ) /2 , lingua.quit_game.c_str() );
					attroff( A_REVERSE | A_BOLD );
				break;
				}
		}
	
		
};
#endif
