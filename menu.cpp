#include <ncurses.h>
#include <locale>
#include "lang.cpp"
using namespace std;

WINDOW *create_newwin(int height, int width, int starty, int startx);

string menu1 = "BBBBB   OOOOO  M     M  BBBBB  EEEEE  RRRRR   M     M  AAAAA  N     N";
string menu2 = "B    B O     O MM   MM  B    B E      R    R  MM   MM  A   A  NN    N";
string menu3 = "BBBBB  O     O M M M M  BBBBB  EEEE   RRRRR   M M M M  AAAAA  N N   N";
string menu4 = "B    B O     O M  M  M  B    B E      R   R   M  M  M  A   A  N  N  N";
string menu5 = "BBBBB   OOOOO  M     M  BBBBB  EEEEE  R    R  M     M  A   A  N    NN";

void cambioschermata(int scelta, Lang lingua , WINDOW* local_win){
	switch (scelta){
		case 0:
			mvaddstr( 21, 60 , lingua.leaderboard.c_str());
			attron( A_REVERSE | A_BOLD ); 
			mvaddstr( 19, 60 , lingua.newgame.c_str() );
			attroff( A_REVERSE | A_BOLD );
		break;
		case 1:
			mvaddstr( 19, 60 , lingua.newgame.c_str() );
			mvaddstr( 23, 60 , lingua.settings.c_str() );
			attron( A_REVERSE | A_BOLD );
			mvaddstr( 21, 60 , lingua.leaderboard.c_str());
			attroff( A_REVERSE | A_BOLD );
		break;
		case 2:
			mvaddstr( 21, 60 , lingua.leaderboard.c_str());
			mvaddstr( 25, 60 , lingua.quit_game.c_str());
			attron( A_REVERSE | A_BOLD );
			mvaddstr( 23, 60 , lingua.settings.c_str() );
			attroff( A_REVERSE | A_BOLD );
		break;
		case 3:
			mvaddstr( 23, 60 , lingua.settings.c_str());
			attron( A_REVERSE | A_BOLD ); 
			mvaddstr( 25, 60 , lingua.quit_game.c_str() );
			attroff( A_REVERSE | A_BOLD );
		break;
	}
	wrefresh(local_win);

}


void scelta(WINDOW* local_win , Lang lingua){
	unsigned int sel = 0;
	int ch;
	int i = 0;
	while (( ch = getch()) != 'q'){
		switch (ch){
			case 'w':
				if ( sel > 0 ){ 
				sel-- ;
					cambioschermata(sel , lingua , local_win);
					wrefresh(local_win); 
				}
			break;
			case 's':
				if ( sel < 3 ){
					 sel++ ;
					cambioschermata(sel , lingua , local_win);
					wrefresh(local_win);
				}
			break;
			case 'r':
				switch (sel){
					case 2:
						if (i < 4){ i++ ;lingua.changelang(i);}
						if (i == 4) { i = 0 ; lingua.changelang(i);}
					break;
				}
		}
	}
}

int main(){
	WINDOW* local_win;
	Lang lingua;
	initscr();
	setlocale(LC_ALL, "");
	keypad(stdscr, true);
	noecho();
	refresh();
	local_win = newwin(40, 80,(LINES - 40 ) / 2 , (COLS -80 ) / 2 );
	keypad(local_win, TRUE);
	mvaddstr(3,40,menu1.c_str());
	mvaddstr(4,40,menu2.c_str());
	mvaddstr(5,40,menu3.c_str());
	mvaddstr(6,40,menu4.c_str());
	mvaddstr(7,40,menu5.c_str());
	lingua.initlang();
	attron(A_REVERSE | A_BOLD);
	mvaddstr(19,60,lingua.newgame.c_str());
	attroff(A_REVERSE | A_BOLD );
	mvaddstr(21,60,lingua.leaderboard.c_str());
	mvaddstr(23,60,lingua.settings.c_str());
	mvaddstr(25,60,lingua.quit_game.c_str());
	box(local_win, 0 , 0 );
	wrefresh(local_win);
	scelta(local_win , lingua);		
	wrefresh(local_win);
	getch();
	endwin();
}
