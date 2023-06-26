#pragma once

#include "Puntajes.h"
#include <stdio.h>

class ArchivoPuntajes
{
private:
	char _nombre[30];
public:
	ArchivoPuntajes(const char* nombre)
	{
		strcpy(_nombre, nombre);
	}
    Puntajes leerRegistro(int pos) {
        Puntajes reg;
        FILE* p;
        reg.setPuntaje(-1);
        p = fopen(_nombre, "rb");
        if (p == NULL) return reg;
        fseek(p, sizeof(Puntajes) * pos, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros() {
        FILE* p;
        p = fopen(_nombre, "rb");
        if (p == NULL) return -1;
        fseek(p, 0, 2);
        int tam = ftell(p);
        fclose(p);
        return tam / sizeof(Puntajes);
    }
};

