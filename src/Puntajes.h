#pragma once
#include <cstring>
#include <stdio.h>
class Puntajes
{
private:
	char _nombreJugador[9];
	int _puntaje;

public:
	Puntajes();

	void setNombre(const char* nombreJugador) { strcpy(_nombreJugador, nombreJugador); }
	void setPuntaje(int puntaje) { _puntaje = puntaje; }

	const char* getNombre() { return _nombreJugador; }
	int getPuntaje() { return _puntaje; }
};

