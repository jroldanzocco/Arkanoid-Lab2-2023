#pragma once
#include "Puntajes.h"

class ArchivoPuntajes
{
private:
	char _nombre[30];
public:
	ArchivoPuntajes(const char* nombre) { strcpy(_nombre, nombre); }
	void setNombre(const char* nombre) { strcpy(_nombre, nombre); }
    Puntajes leerRegistro(int pos);
    int contarRegistros();
	bool guardar(Puntajes reg);
	void vaciar();
};

