#ifndef LANG_H
#define LANG_H

#include <string>
using namespace std;

class lang{
public:

	string lingua , newgame, leaderboard , settings , quit_game , money , skip , insert_name , time ;
	unsigned int stdlang  = 0 , currlang = stdlang ;
		
	void initlang();
		
	void changelang(int lingua_scelta);


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
	string money_langs[5] = {
		"Money :" , "Soldi :" , "Dinero: " , "Geld: " , "Argent: "
	};
	string skip_langs[5] = {
		"Skip" , "Salta" , "Salta" , "überspringen" , "Sauter"
	};
	string insert_name_langs[5] = {
		"Insert name:" , "Inserire nome:" , "Insertar nombre:" , "Name einfügen" , "Insérer le nom:"
	};
	string time_langs[5] = {
		"Time: " , "Tempo: " , "Tiempo: " , "Zeit: " , "Temps: "
	};
};

#endif
