#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
class Puntajes
{
private:
	char _nombreJugador[8];
	int _puntaje;

public:
	Puntajes();

	void setNombre(const char* nombreJugador) { strcpy_s(_nombreJugador, nombreJugador); }
	void setPuntaje(int puntaje) { _puntaje = puntaje; }

	const char* getNombre() { return _nombreJugador; }
	int getPuntaje() { return _puntaje; }
};

