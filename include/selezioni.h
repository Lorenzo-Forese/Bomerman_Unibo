#ifndef SELEZIONI_H
#define SELEZIONI_H
#include "lang.h"
#include <ncurses.h>
#include <cstring>
using namespace std;


class selezioni{
public:
	int Scelte(finestre mainwin, lang lingua);
	int scelta = 0;
private:

	void evidenziato(finestre mainwin,lang lingua);
};
#endif
