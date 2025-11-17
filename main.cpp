#include <ncurses.h>
#include "finestre.cpp"

using namespace std;

int main(){
	finestre finestra ; 
	if (!finestra.initwin()){
		endwin();
		return 0;
	}
	getch();
	endwin();
	return 0;
}
