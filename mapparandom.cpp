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

	void mappaRandom::randShop(){
	for(int i = 1 ; i <= 15 ; i++ ){         
		for(int j = 1 ; j<= 7 ; j++){
			if ( i %2 != 0 || j%2 != 0){
			
				mappa[j][i] = 0;
			}
		}
	}
	for (int i = 2; i <= 14 ; i = i + 2){
		if ( i == 8 ) i = i + 2;
		mappa[3][i] = randInt(17,27);
	}
	mappa[1][8] = 16;
	mappa[5][8] = 3;
}

	void mappaRandom::printMappa( finestre &finestra , int &numNemici ,int &score , int timeLeft){
		int pos_soldi_x =  finestra.gamewin_posx + 53 ;
		int pos_soldi_y =  finestra.gamewin_posy + 3 ;
		mvaddstr( finestra.gamewin_posy , finestra.gamewin_posx + 13 , "     ");
		mvprintw( finestra.gamewin_posy , finestra.gamewin_posx + 13 , "%d" , timeLeft);
		int cuoriDisplayed = 0; 
		init_pair(7 , COLOR_YELLOW , COLOR_BLACK);
		init_pair(8 , COLOR_RED , COLOR_BLACK);
		attron (COLOR_PAIR(7));
		mvaddch( pos_soldi_y  , pos_soldi_x , '$');
		for ( int i = 1 ; i <= 4 ; i ++ ){
			mvaddch( pos_soldi_y , pos_soldi_x + i , ' ');
		}
		mvprintw( pos_soldi_y , pos_soldi_x  + 1 , "%d" , soldi);
		attroff (COLOR_PAIR(7));

			for(int y = 0 ; y <= 21 && cuoriDisplayed < numVite ; y++){

				for ( int x = 0 ;  x <= 7  ; x++ ){
					if ( cuoriDisplayed < numVite ) {
						attron(COLOR_PAIR(8) );
						mvaddch( pos_soldi_y + 3 + y , pos_soldi_x + x, '+');
						attroff(COLOR_PAIR(8) );
						cuoriDisplayed++;
						}
						else mvaddch( pos_soldi_y + 3 + y , pos_soldi_x + x, ' ');
				}
			}

		mvprintw ( pos_soldi_y + 2 , pos_soldi_x, "%d" , score);
		
		

		int y = finestra.gamewin_posy + 1;
		for ( int j = 0 ; j <= 8 ; j++){
			int x = finestra.gamewin_posx + 1;
				for ( int i = 0 ; i <= 16 ; i++){
					if ( mappa[j][i] == 2 ) stampaMuro(x,y) ;
					else if ( mappa[j][i] == 3 ) stampaProtag(x,y) ;
					else if ( mappa[j][i] == 4 ) stampaKamiKaze(x,y);
					else if ( mappa[j][i] == 6 ) stampaKamiKaze(x,y);
					else if ( mappa[j][i] == 5 ) stampaBombarolo(x,y) ;
					else if ( mappa[j][i] == 7 ) {
					if( j % 2 == 0 || i % 2 == 0 ) stampaBombaroloDisarmato1(x,y);
					else stampaBombaroloDisarmato2(x,y);
					} 
					else if ( mappa[j][i] == 0 ) stampaErba(x,y) ;
					else if ( mappa[j][i] == 8 ) { stampaBomba_1(x,y) ; mappa[j][i] = 9; }
					else if ( mappa[j][i] == 9 ) { stampaBomba_2(x,y) ; mappa[j][i] = 10; }
					else if ( mappa[j][i] == 10 ) { stampaBomba_1(x,y) ; mappa[j][i] = 11; }
					else if ( mappa[j][i] == 11 ) { stampaBomba_2(x,y) ; mappa[j][i] = 12; }
					else if ( mappa[j][i] == 12 ) { 
					for (int b = 1 ; b <= potenzaBombe ; b++){
						if ( mappa[j - b][i] == 1) score = score + 10;
						if ( mappa[j - b][i] == 2) { break ;}
						if ( mappa[j - b][i] == 3) { numVite -- ; break; }
						if ( mappa[j - b][i] == 4 || mappa[j - b][i] == 6 ){ mappa [j - b][i] = 15 ; numNemici -- ; score = score + 30 ; break;}
						if ( mappa[j - b][i] == 5 || mappa[j - b][i] == 7 ){ mappa [j - b][i] = 15 ; numNemici -- ; score = score + 50 ; break;}
					 	stampaFuoco ( x , y - (b*3));
					 	mappa[j - b][i] = 14; 
						}
					for (int b = 1 ; b <= potenzaBombe ; b++){
						if ( mappa[j + b][i] == 1 ) score = score + 10;
						if ( mappa[j + b][i] == 2 ) { break; };
						if ( mappa[j + b][i] == 3 ) { numVite -- ; break; }
						if ( mappa[j + b][i] == 4 || mappa[j + b][i] == 6 ){ mappa [j + b][i] = 15 ; numNemici -- ; score = score + 30 ; break;}
						if ( mappa[j + b][i] == 5 || mappa[j + b][i] == 7 ){ mappa [j + b][i] = 15 ; numNemici -- ; score = score + 50 ; break;}
						stampaFuoco ( x , y + (b*3) );
						mappa[j + b][i] = 14;
						}
					for (int b = 1 ; b <= potenzaBombe ; b++){
						if ( mappa[j][i - b] == 1 ) score = score + 10;
						if ( mappa[j][i - b] == 2 ) { break;}
						if ( mappa[j][i - b] == 3 ) { numVite -- ; break;}
						if ( mappa[j][i - b] == 4 || mappa[j][i - b] == 6 ){ mappa [j][i - b] = 15 ; numNemici -- ; score = score + 30 ; break;}
						if ( mappa[j][i - b] == 5 || mappa[j][i - b] == 7 ){ mappa [j][i - b] = 15 ; numNemici -- ; score = score + 50 ; break;}
						stampaFuoco ( x - (b*3) , y );
						mappa[j][i - b] = 14;
						}
					for (int b = 1 ; b <= potenzaBombe ; b++){
						if ( mappa[j][i + b] == 1 ) score = score + 10;
						if ( mappa[j][i + b] == 2 ){ break ; }
						if ( mappa[j][i + b] == 3 ){ numVite -- ; break ;}
						if ( mappa[j][i + b] == 4 || mappa[j][i + b] == 6 ){ mappa [j][i + b] = 15 ; numNemici -- ; score = score + 30 ; break;}
						if ( mappa[j][i + b] == 5 || mappa[j][i + b] == 7 ){ mappa [j][i + b] = 15 ; numNemici -- ; score = score + 50 ; break;}
						stampaFuoco ( x + (b*3) , y );
						mappa[j][i + b] = 14;
						}
					mappa[j][i] = 14;
					stampaFuoco (x,y);
					}
					else if(mappa[j][i] == 14){
						mappa [j][i] = 0;
					}
					else if(mappa[j][i] == 15){
						stampaOro(x,y);
					}
					else if(mappa[j][i] == 16){
						stampaPorta(x,y);
					}
					else if( mappa[j][i] >= 17 && mappa[j][i] <= 26 ){
						stampaLuckyBox( x , y , mappa[j][i] - 16 );
					}
					else if( mappa[j][i] == 27 ){
						stampaCuore(x,y);
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
