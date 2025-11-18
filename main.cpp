#include <ncurses.h>
#include "finestre.h"
#include "selezioni.h"
#include "lang.h"
#include "impostazioni.cpp"
using namespace std;

int main(){
	lang lingua;
	finestre finestra ;
	selezioni Selezioni ;
	impostazioni impostazioni;
	noecho();
	raw();
	if (!finestra.initwin()){
		endwin();
		return 0;
	}
	else{
		int sel;
		lingua.initlang();
		do {
			sel = Selezioni.Scelte(finestra,lingua);
			switch ( sel ){
				case 2:
					impostazioni.cambiolingua(lingua , finestra );
				break;
			}
		}
		while ( sel != 3 );
		endwin();
	}
	
	
	return 0;
	
}
