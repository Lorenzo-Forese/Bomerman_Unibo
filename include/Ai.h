#ifndef AI_H
#define AI_H

#include "mapparandom.h"

using namespace std;

class Ai{

public:

	int personaggio_x , personaggio_y;

	void checkInactive(mappaRandom &mappa);

	void KamiKaze( mappaRandom &mappa , int &numNemici );

	void trovaChar( mappaRandom &mappa );

	void BombaroloArmato( mappaRandom &mappa , int personaggio_x , int personaggio_y );

	void BombaroloDisarmato( mappaRandom &mappa );

};

#endif
