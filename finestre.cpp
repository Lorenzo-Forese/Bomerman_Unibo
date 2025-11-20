#include <ncurses.h>
#include <string>
#include <cstring>
#include "finestre.h"
using namespace std;



	
	void finestre::mainwin_refresh(){
	
			char menu1[] = "BBBBB   OOOOO  M     M  BBBBB  EEEEE  RRRRR   M     M  AAAAA  N     N"; // definizione del titolo riga per riga
			char menu2[] = "B    B O     O MM   MM  B    B E      R    R  MM   MM  A   A  NN    N"; // fun fact: ogni lettera viene composta
			char menu3[] = "BBBBB  O     O M M M M  BBBBB  EEEE   RRRRR   M M M M  AAAAA  N N   N"; // dal suo corrispettivo maiuscolo.
			char menu4[] = "B    B O     O M  M  M  B    B E      R   R   M  M  M  A   A  N  N  N";
			char menu5[] = "BBBBB   OOOOO  M     M  BBBBB  EEEEE  R    R  M     M  A   A  N    NN";
	
			box( mainwin , 0 , 0 );  //Creazione della scatola generale di contenimento di tutto cio che verra rappresentato a schermo
			refresh();               //Refresh di tutto lo schermo, essenziale dopo la creazione della scatola perche si possa vedere
	 		
			mvaddstr( 3 , 40 , menu1 ); //  Scrittura delle stringhe del titolo su schermo. (parametri: y , x , char*)  
			mvaddstr( 4 , 40 , menu2 ); //  Importante il passaggio per puntatore ad un array di char
			mvaddstr( 5 , 40 , menu3 ); //  per non imbattersi in problemi di conversione. (es. stringhe) 
			mvaddstr( 6 , 40 , menu4 );
			mvaddstr( 7 , 40 , menu5 ); 
					
			
			wrefresh (mainwin); // Refresh del contenuto all'interno della finestra principale,
	                            // in assenza del titolo sarebbe sufficiente a rinfrescare tutto cio che viene rappresentato.
	}
		
	bool finestre::initwin(){
		if ( init() ){
			mainwin_refresh();
			return true;
		}
		else return false;
	}

	void finestre::gameWin(lang &lingua ,int charpos_x ,int charpos_y){
		gamewin_posy =  (scr_y - mainwin_y )/2 + 9 ;
		gamewin_posx =  (scr_x - mainwin_x) /2 + (mainwin_x /8) ;
		finestraGioco = newwin( dim_y , dim_x , gamewin_posy , gamewin_posx );
		start_color();
		init_pair(2, COLOR_WHITE , COLOR_BLACK);
		wattron(finestraGioco, COLOR_PAIR(2) | A_REVERSE);
		wborder(finestraGioco,
		    ACS_VLINE ,
		    ACS_VLINE ,
		    ACS_HLINE ,
		    ACS_HLINE ,
		    ACS_ULCORNER ,
		    ACS_URCORNER ,
		    ACS_LLCORNER ,
		    ACS_LRCORNER 
		);
		move(0,0);
		wattroff(finestraGioco , COLOR_PAIR(2) | A_REVERSE);
		mvaddstr( gamewin_posy + 2, gamewin_posx + 54 , lingua.money.c_str() );
		mvaddstr( gamewin_posy + 3, gamewin_posx + 54 , to_string(charpos_x).c_str() );
		mvaddstr( gamewin_posy + 4, gamewin_posx + 54 , to_string(charpos_y).c_str() );
		wrefresh (finestraGioco);
		
	}


