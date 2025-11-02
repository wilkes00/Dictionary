#include "../include/CDiccionario.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

CDiccionario::CDiccionario()
{
    //ctor
}

void CDiccionario::setCabecera(long dir){
    fseek(this->f, 0, SEEK_SET);
    fwrite(&dir, sizeof(long), 1, this->f);
}

void CDiccionario::getCabecera(){
    fseek(this->f, 0, SEEK_SET);
    fread(&cabEntidades, sizeof(long), 1, this->f);
}

Entidad CDiccionario::capturaEntidad(){
    Entidad e;
    cout<<" Ingrese el nombre de la Entidad: ";
    cin>>e.nombre;
    e.sig = -1;
    e.atr = -1;
    e.dato = -1;
    return e;
}

Entidad CDiccionario::leeEntidad(long dir){
    Entidad e;
    fseek(f, dir, SEEK_SET);
    fread(&e, sizeof(Entidad), 1, f);
    return e;
}

long CDiccionario::escribeEntidad(Entidad e){
    long dir = ftell(f);
    fwrite(&e, sizeof(Entidad), 1, f);
    return dir;
}

void CDiccionario::reescribeEntidad(Entidad e, long dir){
    fseek(f, dir, SEEK_SET);
    fwrite(&e, sizeof(Entidad), 1, f);
}

long CDiccionario::buscaEntidad(cadena name){
    getCabecera();
    long curr = cabEntidades;
    Entidad e;

    while(curr != -1){
        e = leeEntidad(curr);
        if(strcmpi(name, e.nombre) == 0)
            return curr;
        curr = e.sig;
    }
    return -1;
}

void CDiccionario::insertaEntidad(Entidad e, long dir)
{
    long dirAux = cabEntidades;
    if(dirAux == -1){
        dirAux = dir;
        setCabecera(dir);
    }
    else{
        Entidad aux;
        aux = leeEntidad(dirAux);
        if(strcmpi(e.nombre, aux.nombre) < 0){
            e.sig = dirAux;
            dirAux = dir;
            reescribeEntidad(e, dir);
            setCabecera(dir);
        }
        else{
            Entidad prev;
            long dirPrev = -1;
            while(dirAux != -1 && strcmpi(e.nombre, aux.nombre) > 0){
                dirPrev = dirAux;
                prev = aux;
                if(aux.sig != -1)
                    aux = leeEntidad(dirAux);
                dirAux = aux.sig;
            }
            if(dirAux != -1){
                e.sig = dirAux;
                reescribeEntidad(e, dir);
                prev.sig = dir;
                reescribeEntidad(prev, dirPrev);
            }
            else{
                prev.sig = dir;
                reescribeEntidad(prev, dirPrev);
            }
        }   
    }
}

CDiccionario::~CDiccionario()
{
    //dtor
}
