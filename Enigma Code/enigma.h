#ifndef ENIGMA_H
#define ENIGMA_H
#include <iostream>
#include <string.h>
//#include "maths.h"

using namespace std;

const int tamAlf=26;
const string arr[7]={"EKMFLGDQVZNTOWYHXUSPAIBRCJ","AJDKSIRUXBLHWTMCQGZNPYFVOE",
					  "BDFHJLCPRTXVZNYEIWGAKMUSQO","ESOVPZJAYQUIRHXLNFTGKDCMWB",
					  "VZBRGITYUPSDNHLXAWMJQOFECK","JPGVOUMFYQBENHZRDKASXLICTW",
					  "NZJHGRCXMYSWBOUFAIVLPEKQDT"};
const string alfabeto="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string reflector="YRUHQSLDPXNGOKMIEBFZCWVJAT";

class Enigma{
	private:
		string key,rotor1,rotor2,rotor3,limites,steckers;int a,b,c;
		
	public:
		Enigma(int,int,int,string,string,string);
		~Enigma(){};
		
		int modulo(int,int);
		
		string cifrado(string); 
		string descifrado(string);           
};

#endif
