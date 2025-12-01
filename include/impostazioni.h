#ifndef IMPOSTAZIONI_H
#define IMPOSTAZIONI_H
#include "lang.h"
#include "finestre.h"

class impostazioni{

public:

	void cambiolingua ( lang &lingua , finestre mainwin );

private:

	void refreshinterno_cambiolingua( lang lingua, finestre mainwin );
	
};

#endif
