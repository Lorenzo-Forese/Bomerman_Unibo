#include <ncurses.h>
#include "mapparandom.h"
#include "finestre.h"
#include "selezioni.h"
#include "lang.h"
#include "impostazioni.cpp"
#include "inGame.cpp"
using namespace std;

int main(){
	start_color();
	use_default_colors();
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
				case 0:
					while (inGame( finestra , lingua )){
						
					}
					
				case 2:
					impostazioni.cambiolingua(lingua , finestra );
				break;
			}
		}
		while ( sel != 3);
		endwin();
	}
	
	
	return 0;
	
}
