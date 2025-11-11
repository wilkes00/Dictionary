#include "../include/CDiccionario.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits>

using namespace std;

CDiccionario::CDiccionario()
{
    f = NULL;
    cabEntidades = -1;
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

int CDiccionario::abrirArchivo(){
    cadena nombre;
    printf("== APERTURA DE ARCHIVO ==\n");
    printf("Teclee el nombre del archivo a abrir:\n");
    scanf("%s", nombre);
    limpiarBuffer();

    f = fopen(nombre, "rb+");
    if(f == NULL){
        printf("Error: El archivo no existe o no se puede abrir\n");
        return 0;
    }else{
        printf("Archivo abierto con exito\n");
        getCabecera();
        return 1;
    }
}

int CDiccionario::crearArchivo(){
    cadena nombre;
    printf("== CREACION DE ARCHIVO ==\n");
    printf("Teclee el nombre del archivo a crear:\n");
    scanf("%s", nombre);
    limpiarBuffer();

    f = fopen(nombre, "rb");
    if(f != NULL){
        printf("Ya existe un diccionario con ese nombre\n");
        fclose(f);
        return 0;
    }else{
        f = fopen(nombre, "wb+");
        if(f == NULL){
            printf("Error al crear el archivo\n");
            return 0;
        }else{
            printf("Archivo creado con exito\n");
            setCabecera(-1);
            return 1;
        }
    }
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
                if(crearArchivo())
                    menuEntidades();
                break;
            case 2:
                limpiarPantalla();
                if(abrirArchivo())
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
                altaEntidad();
                break;
            case 2:
                limpiarPantalla();
                consultaEntidades();
                break;
            case 3:
                limpiarPantalla();
                bajaEntidad();
                break;
            case 4:
                limpiarPantalla();
                modificaEntidad();
                break;
            case 5:
                limpiarPantalla();
                menuAtributos();
                break;
            case 6:
                limpiarPantalla();
                menuDatos();
                break;
            case 7:
                cout << "\nRegresando al menu Principal\n";
                break;
            default:
                limpiarPantalla();
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
                cout << "\nFuncion Nuevo Atributo\n";
                break;
            case 2:
                cout << "\nFuncion Consultar Atributo\n";
                break;
            case 3:
                cout << "\nFuncion Eliminar Atributo\n";
                break;
            case 4:
                cout << "\nFuncion Modificar Atributo\n";
                break;
            case 5:
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
    limpiarBuffer();

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
    getCabecera();
    long dirAux = cabEntidades;

    if(dirAux == -1){     // caso 1, la lista esta vacia
        dirAux = dir;
        setCabecera(dir);
    }
    else{ // la lista no esta vacia
        Entidad aux;
        aux = leeEntidad(dirAux);
        if(strcmpi(e.nombre, aux.nombre) < 0){ // caso 2 insertar al inicio
            e.sig = dirAux;
            dirAux = dir;
            reescribeEntidad(e, dir);
            setCabecera(dir);
        }
        else{ // insertar en medio o al final
            Entidad prev;
            long dirPrev = -1;
            while(dirAux != -1 && strcmpi(e.nombre, aux.nombre) > 0){
                dirPrev = dirAux;
                prev = aux;

                if(aux.sig != -1)
                    aux = leeEntidad(dirAux);
                dirAux = aux.sig;
            }
            if(dirAux != -1){ // caso 3 insertar en medio
                e.sig = dirAux;
                reescribeEntidad(e, dir);
                prev.sig = dir;
                reescribeEntidad(prev, dirPrev);
            }
            else{ // caso 4 insertar al final
                prev.sig = dir;
                reescribeEntidad(prev, dirPrev);
            }
        }
    }
}

void CDiccionario::consultaEntidades(){
    Entidad ent;
    getCabecera();
    long auxDir = cabEntidades;

    if(auxDir == -1)
        printf("El diccionario esta vacio\n");

    while(auxDir != -1){
        ent = leeEntidad(auxDir);
        printf("Nombre de la Entidad: %s\n", ent.nombre);
        printf("Apuntador a siguiente Entidad: %ld\n", ent.sig);
        printf("Apuntador a Atributo: %ld\n", ent.atr);
        printf("Apuntador a Data: %ld\n", ent.dato);
        auxDir = ent.sig;
    }
}

void CDiccionario::altaEntidad(){
    long dir = -1;
    Entidad ent = capturaEntidad();
    if(buscaEntidad(ent.nombre) == -1){
        dir = escribeEntidad(ent);
        insertaEntidad(ent, dir);
        printf("Entidad agregada con exito!\n");
    }
    else
        printf("Error: No puede agregarse la Entidad porque ya existe\n");

}

void CDiccionario::bajaEntidad(){
    cadena name;
    printf("Ingrese el nombre de la Entidad a eliminar: \n");
    scanf("%s", name);
    limpiarBuffer();

    if(buscaEntidad(name) != -1)
        eliminaEntidad(name);
    else
        printf("Error: La entidad no existe\n");
}

long CDiccionario::eliminaEntidad(cadena name){
    getCabecera();
    long auxDir = cabEntidades;
    Entidad ent;
    ent = leeEntidad(auxDir);

    if(strcmpi(ent.nombre, name) == 0){
        setCabecera(ent.sig);
        return auxDir;
    }
    else{
        long prevDir = -1;
        Entidad prev;
        while(auxDir != -1 && strcmpi(ent.nombre, name) != 0){
            prevDir = auxDir;
            prev = ent;
            auxDir = ent.sig;
            if(auxDir != -1)
                ent = leeEntidad(auxDir);
        }
        if(auxDir != -1){
            prev.sig = ent.sig;
            reescribeEntidad(prev, prevDir);
        }
    }
    return auxDir;
}

void CDiccionario::modificaEntidad(){
	cadena name;
	printf("Ingrese el nombre de la Entidad a modificar: \n");
	scanf("%s",name);
	limpiarBuffer();

	if(buscaEntidad(name)!= -1){
		Entidad ent;
		ent=capturaEntidad();
		if(buscaEntidad(ent.nombre)!= -1){
			printf("Error: Ya existe una Entidad de nombre %s",ent.nombre);
		}else{
			long dir=eliminaEntidad(name);
			reescribeEntidad(ent,dir);
			insertaEntidad(ent,dir);
		}
	}else{
		printf("Error: No existe la Entidad que desea modificar\n");
	}
}

CDiccionario::~CDiccionario()
{
    //dtor
}
