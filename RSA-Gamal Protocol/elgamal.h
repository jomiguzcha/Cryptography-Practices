#ifndef ELGAMAL_H
#define ELGAMAL_H
#include "../ops.h"
class elgamal{
private:
    ZZ lambda,r;
    string lambda_bin;
public:
    ZZ p,alpha,beta,c1;
    elgamal(int);
    vector<ZZ> cifradonum(ZZ);
    ZZ descifradonum(vector<ZZ>);
    string cifrado(string);
    string descifrado(string);
};

#endif // ELGAMAL_H
