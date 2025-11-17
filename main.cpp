#include <ncurses.h>
#include "finestre.h"
#include "selezioni.cpp"
#include "lang.h"
#include "impostazioni.cpp"
using namespace std;

int main(){
	Lang lingua;
	finestre finestra ;
	Selezioni Selezioni ;
	impostazioni impostazioni;
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
			}
		}
	endwin();
	return 0;
	}
}
