#include "../include/CDiccionario.h"
#include "../include/CMenu.h"



int main()
{
    CMenu menu;
    int opcion, opSecundaria;
    do{
        menu.MenuPrincipal();
        cin >>opcion;
        menu.limpiarBuffer();

        switch(opcion){
            case 1:
                do{
                    menu.MenuEntidades();
                    cin >>opSecundaria;
                    menu.limpiarBuffer();

                    switch(opSecundaria){
                        case 1:
                            menu.limpiarPantalla();
                            cout << "Funcion Nueva Entidad\n";
                            break;
                        case 2:
                            menu.limpiarPantalla();
                            cout << "Funcion Consultar Entidad\n";
                            break;
                        case 3:
                            menu.limpiarPantalla();
                            cout << "Funcion Eliminar Entidad\n";
                            break;
                        case 4:
                            menu.limpiarPantalla();
                            cout << "Funcion Modificar Entidad\n";
                            break;
                        case 5:
                            menu.limpiarPantalla();
                            cout << "Menu Atributos\n";
                            break;
                        case 6:
                            menu.limpiarPantalla();
                            cout << "Menu Datos\n";
                            break;
                        case 7:
                            menu.limpiarPantalla();
                            cout << "Regresando al menu principal\n";
                            break;

                    }
                }while(opSecundaria != 7);
                break;
            case 2:
                cout << "\nFuncion Abrir Diccionario\n";
                break;
            case 3:
                cout << "Saliendo del programa\n";
                break;
            default:
                cout << "Opcion invalida: ingrese una opcion valida\n";
                break;
        }
    }while(opcion != 3);

    return 0;
}
