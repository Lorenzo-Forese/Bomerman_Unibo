#include <ncurses.h>
#include "movimento.cpp"
#include "mapparandom.h"
#include "finestre.h"
#include "lang.h"
using namespace std;


bool inGame(finestre &finestra , lang &lingua , int &score){
	float difficulty = 0.1;
	mappaRandom mappa;
	movimento movimento;
	finestra.gameWin(lingua);
	int ch = 0;
	int startpos = mappa.randMappa( difficulty );
	movimento.startingpos(startpos);
	refresh();
	int numNemici = movimento.spawnMultiple_NPC(mappa , startpos , difficulty);
	mappa.printMappa( finestra , numNemici , score);
	refresh();
	while ( true ){
		mappa.printMappa( finestra , numNemici , score);
		refresh();
		while ( numNemici > 0 || ( movimento.protag_x != 8 || movimento.protag_y != 5 ) ){
			mvprintw( 1 , 1 , "%d" , numNemici);
			ch = getch();
			movimento.protag(mappa , ch , difficulty);
			mappa.printMappa(finestra , numNemici , score);
			if (mappa.numVite == 0 ) return false;
			if ( numNemici == 0 ) mappa.mappa [5][8] = 16;
			}
		mappa.randShop();
		mappa.printMappa(finestra , numNemici , score);
		while ( movimento.protag_x != 8 || movimento.protag_y != 1 ){
			ch = getch();
			movimento.protag(mappa , ch , difficulty);
			mappa.printMappa(finestra , numNemici , score);
		}
		difficulty = difficulty + 0.05;
		int startpos = mappa.randMappa( difficulty );
		movimento.startingpos(startpos);
		numNemici = movimento.spawnMultiple_NPC(mappa , startpos , difficulty);
		
	}
	return false;
}

