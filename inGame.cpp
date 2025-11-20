#include <ncurses.h>
#include "movimento.cpp"
#include "mapparandom.h"
#include "finestre.h"
#include "lang.h"
using namespace std;


bool inGame(finestre &finestra , lang &lingua){
	mappaRandom mappa;
	movimento movimento;
	finestra.gameWin(lingua , movimento.protag_x , movimento.protag_y);
	int ch;
	while (true){
		movimento.startingpos(mappa.randMappa(0.5));
		mappa.printMappa( finestra );
		while ( ( ch = getch() ) != 'r' ){
			movimento.protag(mappa , ch);
			mappa.printMappa(finestra);
		}
	}
	endwin();
	return false;
}

