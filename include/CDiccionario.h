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
    int tam;
    int tipo; // 1. int, 2. float, 3. char
    long sig;
    char iskp; //S, N
    char descripcion[50];
};

class CDiccionario
{
    private:
        FILE* f;
        Entidad activa;
        long posEntActiva;
        int nAtributos;
        Atributo arrAtributos[50];
        long tamBloque;
        long cabEntidades;

    public:
        CDiccionario();
        ~CDiccionario();
        int abrirArchivo();
        int crearArchivo();
        void menuPrincipal();
        void menuEntidades();
        void menuAtributos();
        void menuDatos();
        void limpiarBuffer();
        void limpiarPantalla();
        void setCabecera(long dir);
        void getCabecera();
        Entidad capturaEntidad();
        Entidad leeEntidad(long dir);
        long escribeEntidad(Entidad e);
        void reescribeEntidad(Entidad e, long dir);
        long buscaEntidad(cadena name);
        void insertaEntidad(Entidad e, long dir);
        void consultaEntidades();
        void altaEntidad();
        void bajaEntidad();
        long eliminaEntidad(cadena name);
        void modificaEntidad();
        void altaAtributo();
        void insertaAtributo(Atributo nuevo,long dir);
        Atributo capturaAtributo();
        long escribeAtributo(Atributo atr);
        void reescribeAtributo(Atributo atr, long dir);
        long buscaAtributo(char nombre[50]);
        Atributo leeAtributo(long dir);
        void consultaAtributos();

};

#endif // CDICCIONARIO_H
