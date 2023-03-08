#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

const string alfabeto="abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-";
const int tamAlf = alfabeto.length();

class Afin{
	private:
		int a,b,inv_a;
	public:
		Afin(int);
		Afin(int,int);
		~Afin(){};

		int modulo(int,int);
		int mcd(int,int);
		int eucExt(int,int);

		int generadorRandom(int);
		string cifrado(string);
		string descifrado(string);
};


