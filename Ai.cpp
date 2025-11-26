#include "mapparandom.h"
using namespace std;


enum Nemici{
	KamiKaze_Attivo = 4,
	KamiKaze_Disattivo = 6,
	Bombarolo_Armato = 5,
	Bombarolo_Disarmato = 7,
};

class Ai{ 


public:

	int personaggio_x , personaggio_y;

	
	void checkInactive(mappaRandom &mappa){
		for (int j = 1 ; j <= 7 ; j++){
			for (int i = 1 ; i <= 15 ; i++){
				if ( mappa.mappa[j][i] == KamiKaze_Disattivo ) mappa.mappa[j][i] = KamiKaze_Attivo;
			}
		}
	}
	
	void KamiKaze(mappaRandom &mappa , int &numNemici ){ // 4 kami , 5 bombarolo , 6 e 7 boh
		for (int j = 1 ; j <= 9 ; j++){
			for (int i = 1 ; i <= 16 ; i++){
				if ( mappa.mappa[ j ] [ i ] == KamiKaze_Attivo ){
					if (mappa.mappa[ j + 1 ] [ i ] == 3 ){
						mappa.mappa[ j ][ i ] = 8;
						numNemici --;
					}
					else if (mappa.mappa[ j - 1 ] [ i ] == 3 ){
						mappa.mappa[ j ][ i ] = 8;
						numNemici --;
					}
					else if (mappa.mappa[ j ] [ i + 1] == 3 ){
						mappa.mappa[ j ][ i ] = 8;
						numNemici --;
					}
					else if (mappa.mappa[ j ] [ i - 1 ] == 3 ){
						mappa.mappa[ j ][ i ] = 8;
						numNemici --;
					}
					else if  (mappa.mappa[ j + 1 ] [ i ] == 0 ){
						mappa.mappa[ j + 1] [ i ] = KamiKaze_Disattivo;
						mappa.mappa[ j ][ i ] = 0;
					}
					else if (mappa.mappa[ j - 1 ] [ i ] == 0 ){
						mappa.mappa[ j - 1 ] [ i ] = KamiKaze_Disattivo;
						mappa.mappa[ j ][ i ] = 0;
					}
					else if (mappa.mappa[ j ] [ i + 1] == 0 ){
						mappa.mappa[ j  ] [ i + 1] = KamiKaze_Disattivo;
						mappa.mappa[ j ][ i ] = 0;
					}
					else if (mappa.mappa[ j ] [ i - 1 ] == 0 ){
						mappa.mappa[ j ] [ i - 1 ] = KamiKaze_Disattivo;
						mappa.mappa[ j ][ i ] = 0;
					}
					
				}
			}
		}
	}
	
	void trovaChar(mappaRandom &mappa){
		for (int j = 1 ; j <= 7 ; j++){
			for (int i = 1 ; i <= 15 ; i++){
				if ( mappa.mappa[j][i] == 3 ){
					personaggio_x = i;
					personaggio_y = j;
				}
			}
		}
	}
	void BombaroloArmato(mappaRandom &mappa,int personaggio_x ,int personaggio_y){
	bool Giamossi[9][17]{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
	};
		for (int j = 1 ; j <= 7 ; j++){

			for (int i = 1 ; i <= 17 ; i++){

				if ( mappa.mappa[j][i] == Bombarolo_Armato ){
					
					if ( i + 2 == personaggio_x && j == personaggio_y ) {
						if ( mappa.mappa[j][i+1] == 0){
							mappa.mappa[j][i+1] = 8;
							mappa.mappa[j][i] = Bombarolo_Disarmato;
						}
					}
					else if ( i - 2 == personaggio_x && j == personaggio_y ){
						if ( mappa.mappa[j][i-1] == 0){
							mappa.mappa[j][i-1] = 8;
							mappa.mappa[j][i] = Bombarolo_Disarmato;
						}
					}
					else if ( j + 2 == personaggio_y && i == personaggio_x ) {
						if ( mappa.mappa[j+1][i] == 0){
							mappa.mappa[j+1][i] = 8;
							mappa.mappa[j][i] = Bombarolo_Disarmato;
						}
					}
					else if ( j - 2 == personaggio_y && i == personaggio_x ){
						if ( mappa.mappa[j-1][i] == 0){
							mappa.mappa[j-1][i] = 8;
							mappa.mappa[j][i] = Bombarolo_Disarmato;
						}
					}
					else if ( ( i < personaggio_x && mappa.mappa[j][i + 1 ] == 0 ) && Giamossi[j][i] == false){
						mappa.mappa[j][i] = 0 ;
						mappa.mappa[j][ i + 1 ] = Bombarolo_Armato;
						Giamossi[j][i+1] = true;
					}
					else if ( ( i > personaggio_x && mappa.mappa[j][i-1] == 0 ) && Giamossi[j][i] == false ){
						mappa.mappa[j][i] = 0;
						mappa.mappa[j][ i - 1 ] = Bombarolo_Armato;
						Giamossi[j][i-1] = true;
					}
					else if ( ( j < personaggio_y && mappa.mappa[j + 1 ][i] == 0 ) && Giamossi[j][i] == false ){
						mappa.mappa[j][i] = 0;
						mappa.mappa[j + 1][i] = Bombarolo_Armato;
						Giamossi[j+1][i] = true;
					}
					else if ( ( j > personaggio_y && mappa.mappa[j - 1][i] == 0 ) && Giamossi[j][i] == false ){
						mappa.mappa[j][i] = 0;
						mappa.mappa[j-1][i] = Bombarolo_Armato;
						Giamossi[j-1][i] = true;
					}
					
				
				}
			}
		}
	}

	void BombaroloDisarmato(mappaRandom &mappa){
	bool Giamossi[7][15]{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};

	int angolo_x , angolo_y;
	
	for (int j = 1 ; j <= 7 ; j++){
	
		for (int i = 1 ; i <= 15 ; i++){
			if ( mappa.mappa[j][i] == Bombarolo_Disarmato ){
				int angolo = mappa.randInt(0,4);
				if ( angolo == 0 ){
					angolo_x = 1;
					angolo_y = 1;
				}
				if ( angolo == 1 ){
					angolo_x = 15;
					angolo_y = 1;
				}
				if ( angolo == 2 ){
					angolo_x = 1;
					angolo_y = 7;
				}
				if ( angolo == 3 ){
					angolo_x = 15;
					angolo_y = 7;
				}
				if ( ( i < angolo_x && mappa.mappa[j][i + 1 ] == 0 ) && Giamossi[j][i] == false){
					mappa.mappa[j][i] = 0 ;
					mappa.mappa[j][ i + 1 ] = Bombarolo_Disarmato;
					Giamossi[j][i+1] = true;
				}
				else if ( ( i > angolo_x && mappa.mappa[j][i-1] == 0 ) && Giamossi[j][i] == false ){
					mappa.mappa[j][i] = 0;
					mappa.mappa[j][ i - 1 ] = Bombarolo_Disarmato;
					Giamossi[j][i-1] = true;
				}
				else if ( ( j < angolo_y && mappa.mappa[j + 1 ][i] == 0 ) && Giamossi[j][i] == false ){
					mappa.mappa[j][i] = 0;
					mappa.mappa[j + 1][i] = Bombarolo_Disarmato;
					Giamossi[j+1][i] = true;
				}
				else if ( ( j > angolo_y && mappa.mappa[j - 1][i] == 0 ) && Giamossi[j][i] == false ){
					mappa.mappa[j][i] = 0;
					mappa.mappa[j-1][i] = Bombarolo_Disarmato;
					Giamossi[j-1][i] = true;
				}
			}
		}
	}
	
	}
};
