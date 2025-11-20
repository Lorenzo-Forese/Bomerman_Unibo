#ifndef MAPPARANDOM_H
#define MAPPARANDOM_H
#include <random>
#include "finestre.h"
using namespace std;

class mappaRandom{

public:

	int randInt( int a , int b );
	
	bool randBool( float prob );

	int randMappa( float prob );

	int potenzaBombe = 1;
	
	unsigned int  mappa[9][17]{
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2}, // 0 = erba
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2}, // 1 = muro distruttibile
		{2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2}, // 2 = muro indistruttibile
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2}, // 3 = ..
		{2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2}, // 4 = ..
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,2,0,2,0,2,0,2,0,2,0,2,0,2,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2},
		
	};
	
	random_device rd;

	void printMappa( finestre &finestra );	

private:

	void spawn(int spawnCorner){
		
		if ( spawnCorner == 0){ //alto sx
			
			mappa[1][1] = 3 ;
			mappa[1][2] = 0 ;
			mappa[2][1] = 0 ;	
					
		}
			
		if ( spawnCorner == 1){ //alto dx
		
			mappa[1][15] = 3; 
			mappa[1][14] = 0; 
			mappa[2][15] = 0;
	
		}
			
		if ( spawnCorner == 2){ //basso sx
				
			mappa[7][1] = 3;
			mappa[7][2] = 0; 
			mappa[6][1] = 0;
				
		}
			
		if ( spawnCorner == 3){ //basso dx
				
			mappa[7][15] = 3;
			mappa[7][14] = 0;
			mappa[6][15] = 0;
	
		}
	}

};

#endif
