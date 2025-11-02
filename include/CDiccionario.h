#ifndef CDICCIONARIO_H
#define CDICCIONARIO_H
#include<iostream>
#include<cstdio>
#include<cstring>


using namespace std;

typedef char cadena[30];

 typedef struct Entidad{
    cadena nombre;
    long sig;
    long atr;
    long dato;
};

typedef struct Atributo{
    cadena nombre;
    int tipo; // 1. int, 2. float, 3. char
    long sig;
    long dirDatos;
    int tamDatos;
};

class CDiccionario
{
    private:
        FILE* f;
        Entidad activa;
        long posEnt;
        int nAtributos;
        Atributo arrAtributos[50];
        long tamBloque;
        long cabEntidades;

    public:
        CDiccionario();
        ~CDiccionario();
        void setCabecera(long dir);
        void getCabecera();
        Entidad capturaEntidad();
        Entidad leeEntidad(long dir);
        long escribeEntidad(Entidad e);
        void reescribeEntidad(Entidad e, long dir);
        long buscaEntidad(cadena name);
        void insertaEntidad(Entidad e, long dir);
};

#endif // CDICCIONARIO_H
