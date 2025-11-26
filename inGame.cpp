#include <ncurses.h>
#include "movimento.cpp"
#include "mapparandom.h"
#include "finestre.h"
#include "lang.h"
#include "Ai.cpp"
using namespace std;


bool inGame(finestre &finestra , lang &lingua , int &score){
	float difficulty = 0.1;
	mappaRandom mappa;
	movimento movimento;
	Ai Ai;
	finestra.gameWin(lingua);
	int ch = 0;
	int timeLeft;
	int startpos = mappa.randMappa( difficulty );
	movimento.startingpos(startpos);
	refresh();
	int numNemici = movimento.spawnMultiple_NPC(mappa , startpos , difficulty);
	mappa.printMappa( finestra , numNemici , score , 0 );
	refresh();
	timeout(1000 - (difficulty * 5000) );
	while ( true ){
		mappa.printMappa( finestra , numNemici , score , 0);
		refresh();
		timeLeft = 100000 - 1000 * difficulty;
		while ( ( numNemici > 0 || ( movimento.protag_x != 8 || movimento.protag_y != 5 ) ) && timeLeft != 0 ){
			ch = getch();
			movimento.protag(mappa , ch , difficulty);
			mappa.printMappa(finestra , numNemici , score , timeLeft / 100 );
			
			Ai.checkInactive(mappa);
			Ai.KamiKaze(mappa, numNemici);
			Ai.BombaroloArmato(mappa,movimento.protag_x , movimento.protag_y);
			Ai.BombaroloDisarmato(mappa);
			if (mappa.numVite == 0 ) return false;
			if ( numNemici == 0 ) mappa.mappa [5][8] = 16;
			timeLeft = timeLeft - 200;
			if (timeLeft == 0 )return false ;
			}
		mappa.randShop();
		mappa.printMappa(finestra , numNemici , score ,  0);
		while ( movimento.protag_x != 8 || movimento.protag_y != 1 ){
			ch = getch();
			movimento.protag(mappa , ch , difficulty);
			mappa.printMappa(finestra , numNemici , score , 0);
			if (mappa.numVite == 0 ) return false;
		}
		difficulty = difficulty + 0.05;
		int startpos = mappa.randMappa( difficulty );
		movimento.startingpos(startpos);
		numNemici = movimento.spawnMultiple_NPC(mappa , startpos , difficulty);
		
	}
	return false;
}

