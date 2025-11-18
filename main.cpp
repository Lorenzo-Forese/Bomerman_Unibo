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
		lingua.initlang();
		while (int sel = Selezioni.Scelte(finestra , lingua) != 3){
			switch ( sel ){
				case 2:
					impostazioni.cambiolingua(lingua , finestra );
				break;
			}
		}
	}
	
	
	return 0;
	
}
