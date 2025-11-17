#include <ncurses.h>
#include <string>
#include "lang.h"
using namespace std;

lang::lang{
public:
	string lang , newgame , leaderboard , settings , quit_game;
	unsigned int stdlang = 0;
	unsigned int currlang = stdlang;

	
	lang::initlang(){
		lang = langS[ stdlang ];
		newgame = newgame_langs[ stdlang ];
		leaderboard = leaderboard_langs[ stdlang ];
		settings = settings_langs [ stdlang ];
		quit_game = quit_game_langs[ stdlang ];
	}

	lang::changelang(int scelta){
		scelta = scelta %5 ;
		currlang = scelta;
		lang = langS[ currlang ];
		newgame = newgame_langs[ currlang ];
		leaderboard = leaderboard_langs[ currlang ];
		settings = settings_langs [ currlang ];
		quit_game = quit_game_langs[ currlang ];
	}


private:
	
	string langS[5] = { "en" , "it" , "es" ,  "de" , "fr" } ;
	string newgame_langs[5] = {
		"New Game" , "Nuova Partita" , "Nueva Partida" , "Spiel Starten" , "Nouvelle Partie"
	} ;
	string leaderboard_langs[5] = {
		"Leaderboard" , "Classifica" , "Tabla de clasificación" , "Rangliste" , "Tableau de classement"
	};
	string settings_langs[5] = {
		"Settings" , "Impostazioni" , "Configuraciones" , "Einstellungen" , "Paramètres"
	};
	string quit_game_langs[5] = {
		"Quit" , "Esci" , "Salir de juego" , "Verlassen" , "Quitter"
	};
};
