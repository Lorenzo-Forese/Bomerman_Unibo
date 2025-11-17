#ifndef FINESTRE_H
#define FINESTRE_H

class finestre{

public:
	WINDOW* mainwin;

	int scr_x , scr_y , mainwin_x = 80 , mainwin_y = 40;

	void mainwin_refresh();

	bool initwin();

private:

	bool init();
	
}
