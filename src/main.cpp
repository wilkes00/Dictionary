#include "../include/CDiccionario.h"


/*
Autores:
Oman Leon Aguilar
Leonardo Martinez Alvarado
*/

int main()
{
    CDiccionario *dicc = new CDiccionario();
    dicc->menuPrincipal();
    delete dicc;

    return 0;
}
