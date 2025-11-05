#include "../include/CDiccionario.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits>

using namespace std;

CDiccionario::CDiccionario()
{
    //ctor
}

void CDiccionario::limpiarPantalla(){
    #ifdef _WIN32
        system("cls");

    #else
        system("clear");

    #endif
}

void CDiccionario::limpiarBuffer(){
    if(std::cin.fail())
        std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void CDiccionario::menuPrincipal(){
    int opcion;
    do{
        cout << "\n---- Menu Principal ----\n";
        cout << "1. Nuevo Diccionario\n";
        cout << "2. Abrir Diccionario\n";
        cout << "3. Salir del programa\n";
        cout << "Seleccione una opcion: \n";
        cin >>opcion;
        limpiarBuffer();

        switch(opcion){
            case 1:
                limpiarPantalla();
                cout << "\nFuncion Nuevo Diccionario\n";
                menuEntidades();
                break;
            case 2:
                limpiarPantalla();
                cout << "\nFuncion Abrir Diccionario\n";
                menuEntidades();

                break;
            case 3:
                cout << "Saliendo del programa\n";
                break;
            default:
                cout << "Opcion invalida: ingrese una opcion valida\n";
                break;
        }
    }while(opcion != 3);
}

void CDiccionario::menuEntidades(){
    int opcion;
    do{
        cout << "\n---- Menu Entidades ----\n";
        cout << "1. Nueva Entidad\n";
        cout << "2. Consultar Entidad\n";
        cout << "3. Eliminar Entidad\n";
        cout << "4. Modificar Entidad\n";
        cout << "5. Menu Atributos\n";
        cout << "6. Menu Datos\n";
        cout << "7. Regresar a Menu Principal\n";
        cout << "Seleccione una opcion: \n";

        cin >>opcion;
        limpiarBuffer();

        switch(opcion){
            case 1:
                limpiarPantalla();
                cout << "\nFuncion Nueva Entidad\n";
                break;
            case 2:
                limpiarPantalla();
                cout << "\nFuncion Consultar Entidad\n";
                break;
            case 3:
                limpiarPantalla();
                cout << "\nFuncion Eliminar Entidad\n";
                break;
            case 4:
                limpiarPantalla();
                cout << "\nFuncion Modificar Entidad\n";
                break;
            case 5:
                limpiarPantalla();
                cout << "\nFuncion Menu Atributos\n";
                menuAtributos();
                break;
            case 6:
                limpiarPantalla();
                cout << "\nFuncion Menu Datos\n";
                menuDatos();
                break;
            case 7:
                limpiarPantalla();
                cout << "\nRegresando al menu Principal\n";
                break;
            default:
                cout << "Opcion invalida: ingrese una opcion valida\n";
                break;
        }
    }while(opcion != 7);


}

void CDiccionario::menuAtributos(){
    int opcion;
    do{
        cout << "\n---- Menu Atributos ----\n";
        cout << "1. Nuevo Atributo\n";
        cout << "2. Consultar Atributo\n";
        cout << "3. Eliminar Atributo\n";
        cout << "4. Modificar Atributo\n";
        cout << "5. Regresar a Menu Entidades\n";
        cout << "Seleccione una opcion: \n";

        cin >>opcion;
        limpiarBuffer();

        switch(opcion){
            case 1:
                limpiarPantalla();
                cout << "\nFuncion Nuevo Atributo\n";
                break;
            case 2:
                limpiarPantalla();
                cout << "\nFuncion Consultar Atributo\n";
                break;
            case 3:
                limpiarPantalla();
                cout << "\nFuncion Eliminar Atributo\n";
                break;
            case 4:
                limpiarPantalla();
                cout << "\nFuncion Modificar Atributo\n";
                break;
            case 5:
                limpiarPantalla();
                cout << "\nRegresando al menu Entidades\n";
                break;
            default:
                cout << "Opcion invalida: ingrese una opcion valida\n";
                break;
        }
    }while(opcion != 5);

}

void CDiccionario::menuDatos(){
    int opcion;
    do{
        cout << "\n---- Menu Datos ----\n";
        cout << "1. Nuevo Registro\n";
        cout << "2. Consultar Registro\n";
        cout << "3. Eliminar Registro\n";
        cout << "4. Modificar Registro\n";
        cout << "5. Regresar a Menu Entidades\n";
        cout << "Seleccione una opcion: \n";

        cin >>opcion;
        limpiarBuffer();

         switch(opcion){
            case 1:
                limpiarPantalla();
                cout << "\nFuncion Nuevo Registro\n";
                break;
            case 2:
                limpiarPantalla();
                cout << "\nFuncion Consultar Registro\n";
                break;
            case 3:
                limpiarPantalla();
                cout << "\nFuncion Eliminar Registro\n";
                break;
            case 4:
                limpiarPantalla();
                cout << "\nFuncion Modificar Registro\n";
                break;
            case 5:
                limpiarPantalla();
                cout << "\nRegresando al menu Entidades\n";
                break;
            default:
                cout << "Opcion invalida: ingrese una opcion valida\n";
                break;
        }
    }while(opcion != 5);

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
