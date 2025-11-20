#include "mapparandom.h"
#include <queue>

using namespace std;

struct npc{
	bool vivo;
	int pos_x;
	int pos_y;
	int type;
	npc *next;
};
typedef npc* p_npc;


class movimento{

public:

	void piazzaBomba(mappaRandom &mappa , int bomb_y , int bomb_x ){
			mappa.mappa[bomb_y][bomb_x] = 8;
		}
	
	int protag_x = 0 , protag_y = 0 , spawn = 0;
	int numvite = 3;
	int bombdisp = 1;
	int soldi = 0;
	
	void startingpos( int spawncorner ){

	spawn = spawncorner;

		if ( spawncorner == 0 ){ // Angolo in alto a sx

			protag_x = 1;
			protag_y = 1;
			
		}

		if ( spawncorner == 1 ){ // Angolo in alto a dx

			protag_x = 15;
			protag_y = 1;
		
		}

		if ( spawncorner == 2 ){ // angolo in basso a sx

			protag_x = 1;
			protag_y = 7;
		
		}

		if ( spawncorner == 3 ){ // angolo in basso a dx

			protag_x = 15;
			protag_y = 7;
		}
	}

	void protag(mappaRandom &mappa, int dir ){
		switch (dir){
		case 'w':

			if ( mappa.mappa [protag_y - 1] [protag_x] == 0 ) {
			mappa.mappa[protag_y] [protag_x] = 0 ;
			protag_y -- ;
			mappa.mappa[protag_y] [protag_x] = 3 ;
			}

		break;

		case 'a':

			if ( mappa.mappa[ protag_y ] [ protag_x - 1] == 0 ){
			mappa.mappa[protag_y] [protag_x] = 0;
			protag_x--;
			mappa.mappa[protag_y] [protag_x] = 3;
			}
		break;

		case 's':

			if ( mappa.mappa [ protag_y + 1 ] [ protag_x ] == 0){
			mappa.mappa[protag_y] [protag_x] = 0;
			protag_y++;
			mappa.mappa[protag_y] [protag_x] = 3;
			}
		break;

		case 'd':

			if ( mappa.mappa [ protag_y ] [ protag_x + 1] == 0){
			mappa.mappa[protag_y] [protag_x] = 0;
			protag_x++;
			mappa.mappa[protag_y] [protag_x] = 3;
			}
		break;

		case 'b':
			int ch = getch();
			switch ( ch ){
						
				case 'w':
					if ( mappa.mappa [ protag_y - 1 ] [ protag_x ] == 0 ){
						piazzaBomba( mappa , protag_y - 1 , protag_x );
						
					}
				break;

				case 'a':
					if ( mappa.mappa [ protag_y ] [ protag_x - 1 ] == 0 ){
						piazzaBomba( mappa , protag_y , protag_x - 1 );
					}
				break;

				case 's':
					if ( mappa.mappa [ protag_y +1 ] [ protag_x ] == 0 ){
						piazzaBomba( mappa , protag_y + 1 , protag_x );
					}
				break;
				
				case 'd':
					if ( mappa.mappa [ protag_y ] [ protag_x + 1 ] == 0 ){
						piazzaBomba( mappa , protag_y , protag_x + 1 );
					}
				break;

			break;
					
			
			}
		}
	}

	void npc ( mappaRandom &mappa ,p_npc nemico){
		if ( nemico == nullptr ) return;
		npc ( mappa , nemico->next);

			if ( nemico -> vivo == false ) return;
			if ( nemico -> type == 0 ) kamikaze(mappa , nemico );
			if ( nemico -> type == 1 ) bombarolo(mappa , nemico );
		}

private:

	void kamikaze ( mappaRandom &mappa , p_npc nemico ){}

	void bombarolo ( mappaRandom &mappa , p_npc nemico ){}		
	
};

