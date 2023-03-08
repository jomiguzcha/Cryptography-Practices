#ifndef MENU_H
#define MENU_H
#include "protocolo.h"

class menu{
public:
    menu();
    int op;
    int op2;
    string e_aux;
    string n_aux;
    string p_aux;
    string g_aux;

    string e_receptor;
    string n_receptor;
    string p_receptor;
    string g_receptor;

    string mensaje_aux;
    string mensaje_a_descifrar_1;
    string mensaje_a_descifrar_2;
};

#endif // MENU_H

