#include <ncurses.h>
#include "lang.cpp"
#include "finestre.cpp"
#include <cstring>
using namespace std;

class Selezioni{

public:	
	int Scelte(finestre mainwin, Lang lingua){
		while (char ch = getch() != KEY_ENTER ){
			switch(ch){
				case 'w':
					evidenziato( mainwin , (scelta - 1) %3 , lingua );
				break;

				case 's':
					evidenziato( mainwin , (scelta + 1) %3 , lingua );
			}
		}
		return (scelta);
	}
	
private:
	int scelta = 0;
	
	
	void evidenziato(finestre mainwin , int scelta, Lang lingua){
	
		switch (scelta){
			case 0:
				mvaddstr( 21, (mainwin.scr_x - strlen(lingua.leaderboard.c_str()) - 8 ) /2 , lingua.leaderboard.c_str());
				attron( A_REVERSE | A_BOLD ); 
				mvaddstr( 19, (mainwin.scr_x - strlen(lingua.newgame.c_str()) - 8 ) /2 , lingua.newgame.c_str() );
				attroff( A_REVERSE | A_BOLD );
			break;
			case 1:
				mvaddstr( 19, (mainwin.scr_x - strlen(lingua.newgame.c_str()) - 8 ) /2 , lingua.newgame.c_str() );
				mvaddstr( 23, (mainwin.scr_x - strlen(lingua.settings.c_str()) - 8 ) /2 , lingua.settings.c_str() );
				attron( A_REVERSE | A_BOLD );
				mvaddstr( 21, (mainwin.scr_x - strlen(lingua.leaderboard.c_str()) - 8 ) /2 , lingua.leaderboard.c_str());
				attroff( A_REVERSE | A_BOLD );
			break;
			case 2:
				mvaddstr( 21, (mainwin.scr_x - strlen(lingua.leaderboard.c_str()) - 8 ) /2 , lingua.leaderboard.c_str());
				mvaddstr( 25, (mainwin.scr_x - strlen(lingua.quit_game.c_str()) - 8 ) /2 , lingua.quit_game.c_str());
				attron( A_REVERSE | A_BOLD );
				mvaddstr( 23, (mainwin.scr_x - strlen(lingua.settings.c_str()) - 8 ) /2 , lingua.settings.c_str() );
				attroff( A_REVERSE | A_BOLD );
			break;
			case 3:
				mvaddstr( 23, (mainwin.scr_x - strlen(lingua.settings.c_str()) - 8 ) /2 , lingua.settings.c_str());
				attron( A_REVERSE | A_BOLD ); 
				mvaddstr( 25, (mainwin.scr_x - strlen(lingua.quit_game.c_str()) - 8 ) /2 , lingua.quit_game.c_str() );
				attroff( A_REVERSE | A_BOLD );
			break;
			}
	}

		
};
