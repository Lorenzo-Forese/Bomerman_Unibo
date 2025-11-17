#include <ncurses.h>
#include <string>
using namespace std;

class Lang{
public:
	string lang , newgame , leaderboard , settings , quit_game;

	void initlang(){
		lang = langS[ stdlang ];
		newgame = newgame_langs[ stdlang ];
		leaderboard = leaderboard_langs[ stdlang ];
		settings = settings_langs [ stdlang ];
		quit_game = quit_game_langs[ stdlang ];
	}

	void changelang(int scelta){
		currlang = scelta;
		lang = langS[ currlang ];
		newgame = newgame_langs[ currlang ];
		leaderboard = leaderboard_langs[ currlang ];
		settings = settings_langs [ currlang ];
		quit_game = quit_game_langs[ currlang ];
	}


private:
	int stdlang = 0 , currlang = stdlang;
	
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
