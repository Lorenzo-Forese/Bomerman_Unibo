#ifndef RAPPRESENTAZIONE_H
#define RAPPRESENTAZIONE_H
#include <ncurses.h>
#include "finestre.h"

using namespace std;

class rappresentazione{

public:

	void stampaMuro ( int x , int y );

	void stampaMuroDistr ( int x , int y );

	void stampaErba ( int x , int y );
	
	void stampaProtag ( int x , int y );

	void stampaKamiKaze ( int x , int y );

	void stampaBombarolo ( int x , int y );

	void stampaBombaroloDisarmato1 ( int x , int y );

	void stampaBombaroloDisarmato2 ( int x , int y );

	void stampaBomba_1 ( int x , int y );

	void stampaBomba_2 ( int x , int y );

	void stampaFuoco ( int x , int y );

	void stampaOro ( int x , int y );

	void stampaLuckyBox ( int x , int y , int mult );

	void stampaPorta ( int x , int y );

	void stampaCuore ( int x , int y );
	
};

#endif
