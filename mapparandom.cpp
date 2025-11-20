#include <random>
#include "mapparandom.h"
#include "finestre.h"
#include "rappresentazione.cpp"
using namespace std;

	int mappaRandom::randInt(int a , int b) {
		mt19937 generator(rd()); // Mersenne Twister generator
		uniform_int_distribution<int> dist( a , b );
		return ( dist (generator) );
	}

	bool mappaRandom::randBool(float prob){
		mt19937 generator(rd()); // Mersenne Twister generator
		bernoulli_distribution distribution(prob); // 50-40 chance
		return (distribution (generator) );
	}

	
	int mappaRandom::randMappa( float prob ){ // il parametro float rappresenta
                                              // la frequenza di creazione di muri distruttibili
	for(int i = 1 ; i <= 15 ; i++ ){          // 0 min 1 max
		for(int j = 1 ; j<= 7 ; j++){
			if ( i %2 != 0 || j%2 != 0){

				mappa[j][i] = randBool ( prob );

			}
		}
	}
	int spawnCorner = randInt( 0 , 3);

	spawn (spawnCorner);

	return spawnCorner;
}


	void mappaRandom::printMappa( finestre &finestra ){
		int y = finestra.gamewin_posy + 1;
		for ( int j = 0 ; j <= 8 ; j++){
			int x = finestra.gamewin_posx + 1;
				for ( int i = 0 ; i <= 16 ; i++){
					if ( mappa[j][i] == 2 ) stampaMuro(x,y) ;
					else if ( mappa[j][i] == 3 ) stampaProtag(x,y) ; 
					else if ( mappa[j][i] == 0 ) stampaErba(x,y) ;
					else if ( mappa[j][i] == 8 ) { stampaBomba_1(x,y) ; mappa[j][i] = 9; }
					else if ( mappa[j][i] == 9 ) { stampaBomba_2(x,y) ; mappa[j][i] = 10; }
					else if ( mappa[j][i] == 10 ) { stampaBomba_1(x,y) ; mappa[j][i] = 11; }
					else if ( mappa[j][i] == 11 ) { stampaBomba_2(x,y) ; mappa[j][i] = 12; }
					else if ( mappa[j][i] == 12 ) { 
					for (int b = 1 ; b <= potenzaBombe && mappa[j - b][i] < 2 ; b++){
					 	stampaFuoco ( x , y - (b*3));
					 	mappa[j - b][i] = 14; 
						}
					for (int b = 1 ; b <= potenzaBombe && mappa[j + b][i] < 2 ; b++){
						stampaFuoco ( x , y + (b*3) );
						mappa[j + b][i] = 14;
						}
					for (int b = 1 ; b <= potenzaBombe && mappa[j][i - b] < 2 ; b++){
						stampaFuoco ( x - (b*3) , y );
						mappa[j][i - b] = 14;
						}
					for (int b = 1 ; b <= potenzaBombe && mappa[j][i + b] < 2 ; b++){
						stampaFuoco ( x + (b*3) , y );
						mappa[j][i + b] = 14;
						}
					mappa[j][i] = 14;
					stampaFuoco (x,y);
					}
					else if(mappa[j][i] == 14){
						mappa [j][i] = 0;
					}

					else stampaMuroDistr(x,y);
					x = x+3;
				}
			y = y + 3;
		}
	}




/*
int main(){
	cbreak();
	initscr();
	start_color();
	int spawnCorner;
	use_default_colors();
	while (true){
		int y = 0;
		randomizzazione(spawnCorner);
		spawn(spawnCorner);
		for ( int j = 0 ; j <= 8 ; j++){
		int x = 0;
			for ( int i = 0 ; i <= 16 ; i++){
				if ( matrix[j][i] == 2 ) stampaMuro(x,y);
				else if ( matrix[j][i] == 0 ) stampaErba(x,y);
				else stampaMuroDistr(x,y);
				x = x+3;
			}
		y = y + 3;
		}
	getch();
	refresh();
	erase();
	move(0,0);
	}
	endwin();
	return 0;
}
*/
