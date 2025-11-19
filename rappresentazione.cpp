#include <ncurses.h>
using namespace std;

short MY_COLOR = 8; //dal 7 in su

void stampaMuro(int x, int y){  //Muro
	//attivazione colori
	init_color( COLOR_WHITE, 600, 600, 600);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);  
	attron(COLOR_PAIR(2));
	//prima riga
	mvaddch(y,x,ACS_ULCORNER);
	mvaddch(y,x+1,ACS_TTEE);
	mvaddch(y,x+2,ACS_URCORNER);

	//seconda riga
	mvaddch(y+1,x,ACS_LTEE);
	mvaddch(y+1,x+1,ACS_CKBOARD);
	mvaddch(y+1,x+2,ACS_RTEE);

	//attivazione riga sotto alla terza riga
	attron(A_UNDERLINE);

	//terza riga
	mvaddch(y+2,x,ACS_LLCORNER);
	mvaddch(y+2,x+1,ACS_BTEE);
	mvaddch(y+2,x+2,ACS_LRCORNER);
	attroff( A_UNDERLINE);
	attroff( COLOR_PAIR(2));
}

void stampaMuroDistr(int x, int y){
	attron (COLOR_PAIR(2) | A_BOLD | A_UNDERLINE );

	mvaddch(y,x, ACS_PLUS);
	mvaddch(y,x+1,ACS_NEQUAL);
	mvaddch(y,x+2,ACS_PLUS);

	//seconda riga
	mvaddch(y+1,x,ACS_PLUS);
	mvaddch(y+1,x+1,ACS_NEQUAL);
	mvaddch(y+1,x+2,ACS_PLUS);

	//attivazione riga sotto alla terza riga

	//terza riga
	mvaddch(y+2,x,ACS_PLUS);
	mvaddch(y+2,x+1,ACS_NEQUAL);
	mvaddch(y+2,x+2,ACS_PLUS);
	attroff( A_UNDERLINE | A_BOLD);
	attroff( COLOR_PAIR(2));
}

void stampaErba(int x , int y){
	init_pair(3, COLOR_WHITE, COLOR_GREEN);
	attron( COLOR_PAIR(3));

	mvaddch(y,x,ACS_CKBOARD);
	mvaddch(y,x+1,ACS_CKBOARD);
	mvaddch(y,x+2,'~');

	mvaddch(y+1,x,ACS_CKBOARD);
	attron(A_BOLD);
	mvaddch(y+1,x+1,ACS_CKBOARD);
	attroff(A_BOLD);
	mvaddch(y+1,x+2,'|');

	mvaddch(y+2,x,ACS_CKBOARD);
	mvaddch(y+2,x+1,ACS_CKBOARD);
	mvaddch(y+2,x+2,'.');

	attroff( COLOR_PAIR(3));
}

void stampaSprite(int x, int y){
	init_pair(1, COLOR_BLUE, COLOR_GREEN);
	init_pair(4, COLOR_RED, COLOR_GREEN);
	attron (COLOR_PAIR(3));
	mvaddch(y,x,ACS_CKBOARD);
	attroff(COLOR_PAIR(3));
	attron (COLOR_PAIR(1) );
	mvaddch(y,x+1, 'o');
	attron (A_BOLD | COLOR_PAIR(4));
	mvaddch(y,x+2, ACS_DIAMOND);
	attroff (A_BOLD | COLOR_PAIR(4));
	attron ( COLOR_PAIR(1));
	mvaddch(y+1,x,ACS_ULCORNER);
	mvaddch(y+1,x+1,ACS_PLUS);
	mvaddch(y+1,x+2,ACS_LRCORNER);
		
	mvaddch(y+2,x,ACS_ULCORNER);
	mvaddch(y+2,x+1,ACS_BTEE);
	mvaddch(y+2,x+2,ACS_URCORNER);
}

void stampaKamiKaze(int x, int y){
	attron(COLOR_PAIR(3));
	mvaddch(y,x+2,ACS_CKBOARD);
	mvaddch(y,x,ACS_CKBOARD);
	attroff(COLOR_PAIR(3));
		
	attron( COLOR_PAIR(4));
	attron(A_UNDERLINE | A_BOLD);
	mvaddch(y,x+1,'H');
	attroff(A_UNDERLINE);

	mvaddch(y+1,x,'{');
	attron(A_UNDERLINE);
	mvaddch(y+1,x+1,'@');
	attroff(A_UNDERLINE);
	mvaddch(y+1,x+2,'}');

	mvaddch(y+2,x,ACS_BTEE);
	mvaddch(y+2,x+2,ACS_BTEE);
	mvaddch(y+2,x+1,ACS_DIAMOND);
	attroff(A_BOLD);
	
	
}

void stampaBombarolo(int x, int y){
	init_pair(5, COLOR_MAGENTA , COLOR_GREEN);
	attron (COLOR_PAIR(5));
	attron (A_BOLD | COLOR_PAIR(4));
	mvaddch(y,x, ACS_DIAMOND);
	mvaddch(y,x+2, ACS_DIAMOND);
	attroff (A_BOLD | COLOR_PAIR(4));
	attron (COLOR_PAIR(5) | A_UNDERLINE | A_BOLD);
	mvaddch(y,x+1, 'U');
	attroff (A_UNDERLINE );
	mvaddch(y+1,x,ACS_LLCORNER);
	mvaddch(y+1,x+1,ACS_PLUS);
	mvaddch(y+1,x+2,ACS_LRCORNER);
		
	mvaddch(y+2,x,ACS_ULCORNER);
	mvaddch(y+2,x+1,ACS_BTEE);
	mvaddch(y+2,x+2,ACS_URCORNER);
	attroff(A_BOLD);	
}


/*int main(){
	cbreak();
	initscr();
	start_color();
	use_default_colors();
	int y = 0;
	for ( int j = 0 ; j <= 8 ; j++){
	int x = 0;
		for ( int i = 0 ; i <= 16 ; i++){
			if (y == 0 || x == 0 )stampaMuro(x,y);
			else if ( x == 3 && y == 3) stampaSprite(x,y);
			else if ( x == 6 && y == 3) stampaKamiKaze(x,y);
			else if ( x == 9 && y == 3) stampaBombarolo(x,y);
			else if ( x == 12 && y == 3) stampaMuroDistr(x,y);
			else if ( x == 15 && y == 3) stampaMuroDistr(x,y);
			else if ( i == 16 || j == 8) stampaMuro(x,y);
			else if ( y %2 == 0 && x %2 == 0)stampaMuro(x,y);
			else  stampaErba(x,y);
			x = x + 3;
		}
		y = y + 3;
	}
	refresh();
	getch();
	endwin();
	return 0;
}
*/
