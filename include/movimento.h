#ifndef MOVIMENTO_H
#define MOVIMENTO_H
#include "mapparandom.h"

using namespace std;

class movimento{

public:

	int protag_x = 0 , protag_y = 0 , spawn = 0;
	
	void piazzaBomba( mappaRandom &mappa , int bomb_y , int bomb_x );
	
	void startingpos( int spawncorner);

	void protag ( mappaRandom &mappa , int dir , float difficulty );

	int spawnMultiple_NPC ( mappaRandom &mappa , int spawn , float difficulty );
	
};

#endif
