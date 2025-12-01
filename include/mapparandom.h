#ifndef MAPPARANDOM_H
#define MAPPARANDOM_H
#include <random>
#include "finestre.h"
#include "rappresentazione.h"
using namespace std;

class mappaRandom{

public:

	int randInt( int a , int b );
	
	bool randBool( float prob );

	int randMappa( float prob );

	int soldi = 30;

	int numVite = 3;

	int potenzaBombe = 1;
	
	int  mappa[9][17]{
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}, // 0 = Erba
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2}, // 1 = Muro distruttibile
		{2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2}, // 2 = Muro indistruttibile
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2}, // 3 = Protagonista
		{2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2}, // 4 = Nemico 1  //KamiKaze
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2}, // 5 = Nemico 2  //Bombarolo
		{2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		
	};
	
	random_device rd;

	void printMappa( finestre &finestra , int &numNemici , int &score , int timeLeft);

	void randShop ();	

private:

	void spawn(int spawnCorner);

};

#endif
