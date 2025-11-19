#include <random>
#include "rappresentazione.cpp"

int matrix[9][17]{
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


void randomizzazione(int &corner){
	random_device rd;
	mt19937 generator(rd()); // Mersenne Twister generator
	uniform_int_distribution<int> dist(0, 3);
	bernoulli_distribution distribution(0.6); // 60-40 chance
	for(int i = 1 ; i <= 15 ; i++ ){
		for(int j = 1 ; j<= 7 ; j++){
			if ( i %2 != 0 || j%2 != 0){
			matrix[j][i] = distribution(generator);
			}
		}
	}
	corner = dist(generator);
	
}

void spawn(int spawnCorner){
	if ( spawnCorner == 0){
		 matrix[1][1] = 0; matrix[1][2] = 0 ; matrix[2][1] = 0; //alto sx
	}
	if ( spawnCorner == 1){
		 matrix[1][15] = 0; matrix[1][14] = 0 ; matrix[2][15] = 0; //alto dx
	}
	if ( spawnCorner == 2){
		 matrix[7][1] = 0; matrix[7][2] = 0 ; matrix[6][1] = 0; //basso sx
	}
	if ( spawnCorner == 3){
		 matrix[7][15] = 0; matrix[7][14] = 0 ; matrix[6][15] = 0; //basso dx
	}}

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
