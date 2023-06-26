#pragma once

#include "Puntajes.h"
#include <stdio.h>

class ArchivoPuntajes
{
private:
	char _nombre[30];
public:
	ArchivoPuntajes(const char* nombre){strcpy(_nombre, nombre);
    }
    Puntajes leerRegistro(int pos);
    int contarRegistros();
};

