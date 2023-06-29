#include "ArchivoPuntajes.h"

Puntajes ArchivoPuntajes::leerRegistro(int pos) {
    Puntajes reg;
    FILE* p;
    reg.setNombre("Mr.X");
    reg.setPuntaje(0);
    p = fopen(_nombre, "rb");
    if (p == NULL) return reg;
    fseek(p, sizeof(Puntajes) * pos, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}

int ArchivoPuntajes::contarRegistros() {
    FILE* p;
    p = fopen(_nombre, "rb");
    if (p == NULL) return -1;
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Puntajes);
}

bool ArchivoPuntajes::guardar(Puntajes reg)
{
    FILE* p = fopen(_nombre, "ab");

    if (p == NULL)
    {
        return false;
    }

    bool pudoEscribir = fwrite(&reg, sizeof(Puntajes), 1, p);
    fclose(p);
    return pudoEscribir;
}

void ArchivoPuntajes::vaciar() {
    FILE* p = fopen(_nombre, "wb");
        if (p == NULL)
        {
            return;
        }
    fclose(p);
}