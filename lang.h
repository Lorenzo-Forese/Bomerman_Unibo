#ifndef LANG_H
#define LANG_H
#include <string>
using namespace std;

class lang{
public:
	std::string lingua , newgame, leaderboard , settings , quit_game
			,	money , skip , start_over ;
	unsigned int stdlang  = 0 , currlang = stdlang ;
		
	void initlang();
		
	void changelang(int lingua_scelta);


private:

	std::string langS[5] = { "en" , "it" , "es" ,  "de" , "fr" } ;
	std::string newgame_langs[5] = {
		"New Game" , "Nuova Partita" , "Nueva Partida" , "Spiel Starten" , "Nouvelle Partie"
	} ;
	std::string leaderboard_langs[5] = {
		"Leaderboard" , "Classifica" , "Tabla de clasificación" , "Rangliste" , "Tableau de classement"
	};
	std::string settings_langs[5] = {
		"Settings" , "Impostazioni" , "Configuraciones" , "Einstellungen" , "Paramètres"
	};
	std::string quit_game_langs[5] = {
		"Quit" , "Esci" , "Salir de juego" , "Verlassen" , "Quitter"
	};
	std::string money_langs[5] = {
		"Money :" , "Soldi :" , "Dinero: " , "Geld: " , "Argent: "
	};
	std::string skip_langs[5] = {
		"Skip" , "Salta" , "Salta" , "überspringen" , "Sauter"
	};
	std::string start_over_langs[5] = {
		"Start over?" , "Ricomincia?" , "Neustart?" , "Redémarrer?"
	};
};

#endif
