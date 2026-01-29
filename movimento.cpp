#include "include/mapparandom.h"
#include "include/movimento.h"
#include <queue>

using namespace std;


void movimento::piazzaBomba(mappaRandom &mappa , int bomb_y , int bomb_x ){
			mappa.mappa[bomb_y][bomb_x] = 8;
		}
	
	
void movimento::startingpos( int spawncorner ){

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

	void movimento::protag(mappaRandom &mappa, int dir , float difficulty){
		switch (dir){
		case 'w':

			if ( mappa.mappa [protag_y - 1] [protag_x] == 0 ||  mappa.mappa [protag_y - 1] [protag_x] >= 15 ) {
			if ( mappa.mappa [protag_y - 1] [protag_x] == 15 ) mappa.soldi = mappa.soldi + ( 100 * difficulty );
			mappa.mappa[protag_y] [protag_x] = 0 ;
			protag_y -- ;
			mappa.mappa[protag_y] [protag_x] = 3 ;
			}

		break;

		case 'a':

			if ( mappa.mappa[ protag_y ] [ protag_x - 1] == 0 || mappa.mappa[ protag_y ] [ protag_x - 1] >= 15 ){
			if ( mappa.mappa[ protag_y ] [ protag_x - 1] == 15 ) mappa.soldi = mappa.soldi + ( 100 * difficulty) ;
			if ( mappa.mappa[ protag_y ] [ protag_x - 1] >= 17 && ( ( mappa.mappa[ protag_y ] [ protag_x - 1] - 16) * 50 ) <= mappa.soldi ){
				mappa.soldi = mappa.soldi - ( (mappa.mappa[ protag_y ] [ protag_x - 1] - 16) * 50 );
				mappa.potenzaBombe++;
				if ( mappa.mappa[ protag_y ] [ protag_x - 1] == 27 ) {mappa.potenzaBombe -- ; mappa.numVite ++;}
			}
			mappa.mappa[protag_y] [protag_x] = 0;
			protag_x--;
			mappa.mappa[protag_y] [protag_x] = 3;
			}
		break;

		case 's':

			if ( mappa.mappa [ protag_y + 1 ] [ protag_x ] == 0 || mappa.mappa [ protag_y + 1 ] [ protag_x ] >= 15 ){
			if ( mappa.mappa [ protag_y + 1 ] [ protag_x ] == 15) mappa.soldi = mappa.soldi + ( 100 * difficulty);
			mappa.mappa[protag_y] [protag_x] = 0;
			protag_y++;
			mappa.mappa[protag_y] [protag_x] = 3;
			}
		break;

		case 'd':

			if ( mappa.mappa [ protag_y ] [ protag_x + 1] == 0 ||  mappa.mappa [ protag_y ] [ protag_x + 1] >= 15 ){
			if (  mappa.mappa [ protag_y ] [ protag_x + 1] == 15 ) mappa.soldi = mappa.soldi + ( 100 * difficulty);
			if ( mappa.mappa[ protag_y ] [ protag_x + 1] >= 17 && ( ( mappa.mappa[ protag_y ] [ protag_x + 1] - 16) * 50 ) <= mappa.soldi ){
				mappa.soldi = mappa.soldi - ( (mappa.mappa[ protag_y ] [ protag_x + 1] - 16) * 50 );
				mappa.potenzaBombe ++;
				if ( mappa.mappa[ protag_y ] [ protag_x + 1] == 27 ) {mappa.potenzaBombe -- ; mappa.numVite ++;}
			}
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


	int movimento::spawnMultiple_NPC( mappaRandom &mappa, int spawn , float difficulty ){
		int num_NPC = 0;
		difficulty = difficulty / 4;
		switch( spawn ){
			case 0:
				for ( int j = 6 ; j > 1 ; j -- ){
					for ( int i = 14 ; i >=2 ; i --){
						if ( mappa.mappa [j][i] <= 1 ){
							if ( mappa.randBool ( difficulty )){
								mappa.mappa[j][i] = mappa.randInt(4,5);
								num_NPC ++;
							}
						} 
					}
				}
			break;
			case 1:
					for ( int j = 6 ; j > 1 ; j -- ){
						for ( int i = 1 ; i <=14 ; i ++){
							if ( mappa.mappa [j][i] <= 1 ){
								if ( mappa.randBool ( difficulty )){
									mappa.mappa[j][i] = mappa.randInt(4,5);
									num_NPC ++;
								}
							}
						}
					}
			break;
			case 2:
				for ( int j = 1 ; j <= 6 ; j ++ ){
					for ( int i = 14 ; i > 1 ; i --){
						if ( mappa.mappa [j][i] <= 1 ){
							if ( mappa.randBool ( difficulty )){
								mappa.mappa[j][i] = mappa.randInt(4,5);
								num_NPC ++;
							}
						} 
					}
				}
			break;
			case 3:
				for ( int j = 1 ; j <= 6 ; j ++ ){
					for ( int i = 1 ; i <= 14 ; i ++){
						if ( mappa.mappa [j][i] <= 1 ){
							if ( mappa.randBool ( difficulty )){
								mappa.mappa[j][i] = mappa.randInt(4,5);
								num_NPC ++;
								}
						} 
					}
				}
			break;
			
		}
		return num_NPC;
	}
	

