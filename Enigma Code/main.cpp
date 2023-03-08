#include <iostream>
#include "enigma.h"
#include <string.h>

using namespace std;

int main(){
	string clave="XAM",steckers="DE",finales="QEV",
	mensaje="HOLAHOLAHOLAHOLAHOLAHOLAHOLAHOLAHOLAHOLA";
	int rotor1=1,rotor2=2,rotor3=3;
	/*cout<<"Mensaje: ";
	getline(cin,mensaje);
	cout<<"Rotor 1: ";
	cin>>rotor1;	
	cout<<"Rotor 2: ";
	cin>>rotor2;
	cout<<"Rotor 3: ";
	cin>>rotor3;
	cin.ignore();
	cout<<"Clave: ";
	getline(cin,clave);
	cout<<"Finales: ";
	getline(cin,finales);
	cout<<"Steckers: ";  
	getline(cin,steckers);*/

	Enigma emisor(rotor1,rotor2,rotor3,clave,finales,steckers);
	string mc=emisor.cifrado(mensaje);
	cout<<mc<<endl;
	string md=emisor.descifrado(mc);
	cout<<md<<endl;
	
	return 0;
}

