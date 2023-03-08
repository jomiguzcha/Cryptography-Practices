#ifndef PROTOCOLO_H
#define PROTOCOLO_H
#include "../ops.h"
#include "elgamal.h"
#include "rsa.h"

class protocolo{
private:
    ZZ p_rsa;ZZ q_rsa;ZZ phi;ZZ d;
public:
    ZZ N;ZZ e;ZZ p_elgamal;ZZ raiz_primitiva;

    protocolo(int);

    ZZ getN_rsa();
    ZZ getG_raiz_primitiva();
    ZZ getP_elgamal();
    ZZ gete_rsa();

    vector<string> cifrado(string);
    string descifrado(vector<string>);
};

#endif // PROTOCOLO_H
