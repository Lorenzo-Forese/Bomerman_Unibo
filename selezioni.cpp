#include <ncurses.h>
#include "lang.h"
#include "finestre.h"
#include <cstring>
#include "selezioni.h"

using namespace std;


int selezioni::Scelte(finestre finestre, lang lingua){
	int ch;
	noecho();
	while ( (ch = getch()) != 'j' ){
		switch(ch){
			case 'w':
				scelta--;
				evidenziato( finestre  , lingua );
				refresh();
			break;

			case 's':
				scelta++;
				evidenziato( finestre , lingua );
				refresh();
			break;
		}
	}
	return (scelta);
}
