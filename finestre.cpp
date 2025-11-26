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
	 		
			mvaddstr( (scr_y - mainwin_y ) /2 + 2 , (scr_x - mainwin_x) /2 + 6 , menu1 ); //  Scrittura delle stringhe del titolo su schermo. (parametri: y , x , char*)  
			mvaddstr( (scr_y - mainwin_y ) /2 + 3 , (scr_x - mainwin_x) /2 + 6 , menu2 ); //  Importante il passaggio per puntatore ad un array di char
			mvaddstr( (scr_y - mainwin_y ) /2 + 4 , (scr_x - mainwin_x) /2 + 6 , menu3 ); //  per non imbattersi in problemi di conversione. (es. stringhe) 
			mvaddstr( (scr_y - mainwin_y ) /2 + 5 , (scr_x - mainwin_x) /2 + 6 , menu4 );
			mvaddstr( (scr_y - mainwin_y ) /2 + 6 , (scr_x - mainwin_x) /2 + 6 , menu5 ); 
					
			
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

	void finestre::gameWin(lang &lingua ){
		start_color();
		gamewin_posy =  (scr_y - mainwin_y )/2 + 9 ;
		gamewin_posx =  (scr_x - mainwin_x) /2 + (mainwin_x /8) ;
		finestraGioco = newwin( dim_y , dim_x , gamewin_posy , gamewin_posx );
		box(finestraGioco , 0 ,0 );
		move(0,0);
		mvaddstr( gamewin_posy , gamewin_posx + 7 , lingua.time.c_str() );
		mvaddstr( gamewin_posy + 2, gamewin_posx + 54 , lingua.money.c_str() );
		wrefresh (finestraGioco);
		
	}


