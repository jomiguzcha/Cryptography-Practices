#ifndef ELGAMAL_H
#define ELGAMAL_H
#include <iostream>
#include <NTL/ZZ.h>
#include <string.h>
#include <sstream>
#include <stdlib.h>
#include <vector>

using namespace std;
using namespace NTL;

class ElGamal{
    ZZ lambda,r;
    public:
        string tamAlf="26",alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        ZZ p,alpha,beta,c1;
        ElGamal(int);
        ~ElGamal(){};

        string zz_To_String(ZZ);
        ZZ String_To_zz(string);
        ZZ eucExt(ZZ,ZZ);
        ZZ modulo(ZZ,ZZ);
        ZZ inversa(ZZ,ZZ);
        ZZ expRap(ZZ,ZZ,ZZ);
        vector<ZZ> Fact(ZZ n);
        ZZ RaizPrimitiva(ZZ);

        vector<ZZ> cifradonum(ZZ);
        ZZ descifradonum(vector<ZZ>);
        string cifrado(string);
        string descifrado(string);

};

#endif // ELGAMAL_H
