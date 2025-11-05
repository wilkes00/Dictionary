#include "../include/CDiccionario.h"




int main()
{
    CDiccionario *dicc = new CDiccionario();
    dicc->menuPrincipal();
    delete dicc;

    return 0;
}
