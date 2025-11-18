#include <ncurses.h>
#include <string>
#include "lang.h"
using namespace std;


	
void lang::initlang(){
		lingua = langS[ stdlang ];
		newgame = newgame_langs[ stdlang ];
		leaderboard = leaderboard_langs[ stdlang ];
		settings = settings_langs [ stdlang ];
		quit_game = quit_game_langs[ stdlang ];
	}

void lang::changelang(int scelta){
		currlang = scelta;
		lingua = langS[ currlang ];
		newgame = newgame_langs[ currlang ];
		leaderboard = leaderboard_langs[ currlang ];
		settings = settings_langs [ currlang ];
		quit_game = quit_game_langs[ currlang ];
	}


