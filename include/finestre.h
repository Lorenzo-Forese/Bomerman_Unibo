#ifndef FINESTRE_H
#define FINESTRE_H
#include "lang.h"
#include <ncurses.h>
#include <cstring>
class finestre{

WINDOW *create_newwin(int height, int width , int starty, int startx);

public:
	WINDOW* mainwin;
	WINDOW* finestraGioco;

	lang lingua;

	int dim_x = 64 , dim_y = 29 ;

	int soldi = 30;
	
	int scr_x , scr_y , mainwin_x = 80 , mainwin_y = 40; // scr_x = larghezza del terminale nel quale viene aperto il gioco													 // scr_y = altezza del termninale nel quale viene aperto il gioco.
															 // mainwin_x e mainwin_y = larghezza e altezza della finestra principale,
															 // maggiori dettagli di cosa tratta in mainwin_refresh().	
	int gamewin_posx , gamewin_posy;
	void mainwin_refresh();

	bool initwin();

	void gameWin(lang &lingua );

private:
	
	
		bool init();
};
#endif
