#include <iostream>
#include <limits>
#include "../include/CDiccionario.h"
#include "../include/CMenu.h"
using namespace std;

CMenu::CMenu(){
    //ctor
}

void CMenu::limpiarPantalla(){
    #ifdef _WIN32
        system("cls");

    #else
        system("clear");

    #endif
}

void CMenu::limpiarBuffer(){
    if(std::cin.fail())
        std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void CMenu::MenuPrincipal(){
    cout << "\n---- Menu Principal ----\n";
    cout << "1. Nuevo Diccionario\n";
    cout << "2. Abrir Diccionario\n";
    cout << "3. Salir del programa\n";
    cout << "Seleccione una opcion: \n";
}

void CMenu::MenuEntidades(){
    cout << "\n---- Menu Entidades ----\n";
    cout << "1. Nueva Entidad\n";
    cout << "2. Consultar Entidad\n";
    cout << "3. Eliminar Entidad\n";
    cout << "4. Modificar Entidad\n";
    cout << "5. Menu Atributos\n";
    cout << "6. Menu Datos\n";
    cout << "7. Regresar a Menu Principal\n";
    cout << "Seleccione una opcion: \n";

}

void CMenu::MenuAtributos(){
    cout << "\n---- Menu Atributos ----\n";
    cout << "1. Nuevo Atributo\n";
    cout << "2. Consultar Atributo\n";
    cout << "3. Eliminar Atributo\n";
    cout << "4. Modificar Atributo\n";
    cout << "5. Regresar a Menu Entidades\n";
    cout << "Seleccione una opcion: \n";
}

void CMenu::MenuDatos(){
    cout << "\n---- Menu Datos ----\n";
    cout << "1. Nuevo Registro\n";
    cout << "2. Consultar Registro\n";
    cout << "3. Eliminar Registro\n";
    cout << "4. Modificar Registro\n";
    cout << "5. Regresar a Menu Entidades\n";
    cout << "Seleccione una opcion: \n";
}

CMenu::~CMenu(){
    //dtor
}
