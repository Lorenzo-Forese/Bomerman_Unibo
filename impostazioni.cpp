#include <ncurses.h>
#include "lang.h"
#include "finestre.h"
#include <cstring>
using namespace std;

class impostazioni{
public:

	void cambiolingua (lang &lingua,finestre mainwin){
	mainwin.mainwin_refresh();
	refreshinterno_cambiolingua(lingua, mainwin);
	int ch;
		while((ch = getch()) != 's' ){
			switch (ch){
				case 'd':
					lingua.changelang(lingua.currlang+1);
					refreshinterno_cambiolingua( lingua, mainwin );
				break;
				case 'a':
					lingua.changelang(lingua.currlang-1);
					refreshinterno_cambiolingua( lingua, mainwin );
			}
		}
		mainwin.mainwin_refresh(); 
	}
	
private:

	void refreshinterno_cambiolingua(lang lingua, finestre mainwin){
		string line = " -- " + lingua.settings + " -- ";
		char istruzioni[] = " <-- [d]      [s]      [a] --> ";
	//	char istruzioni2[] = " s  "; 
		mainwin.mainwin_refresh();
		attron(A_BOLD | A_STANDOUT);
		mvaddstr( 14 , (mainwin.scr_x - strlen(line.c_str()) ) /2 , line.c_str() );
		attroff(A_BOLD | A_STANDOUT);
		mvaddstr( 27 , ((mainwin.scr_x - strlen(istruzioni)) /2) , istruzioni);
	//	mvaddstr( 28 , (mainwin.scr_x - strlen(istruzioni2)) /2 , istruzioni2);
		attron(A_UNDERLINE);
		mvaddstr(24 , (mainwin.scr_x /2 - 1) , lingua.lingua.c_str() ); 
		attroff(A_UNDERLINE);
	}

};
