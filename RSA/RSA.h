#ifndef RSA_H
#define RSA_H
#include <iostream>
#include <NTL/ZZ.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
using namespace NTL;

class RSA{
    ZZ p,q,phi,d,dp,dq;
    vector<int> w;//vector<string> block;

    public:
        ZZ e,N;
        string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";int tamAlf=alfabeto.length();
        RSA(int);
        RSA(string,ZZ,ZZ);

        string zz_To_String(ZZ);
        ZZ String_To_zz(string);
        ZZ eucExt(ZZ,ZZ);
        ZZ modulo(ZZ,ZZ);
        ZZ inversa(ZZ,ZZ);
        ZZ Resto_Chino(ZZ,ZZ,ZZ,ZZ);

        ZZ expRap(ZZ,ZZ,ZZ);
        void calcular_esp(string);
        ZZ cifrado(string);
        string descifrado(ZZ);
        vector<string> generar_bloques_n_1(string,int);
        vector<string> generar_bloques_menor_n(string);
        string cifradoblocks(string);
        string descifradoblocks(string);


        ~RSA(){};

};

#endif // RSA_H
