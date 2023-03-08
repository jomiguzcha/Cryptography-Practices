#include "afin.h"
#include "string"
#include <NTL/ZZ.h>
#include <time.h>

using namespace std;
using namespace NTL;

int main(){
	string mensaje;
	cout<<"Mensaje: ";
	getline(cin,mensaje);
	int bytes,i=0,
	a=0,
	b=0;
	cout<<"Bytes: ";
	cin>>bytes;

	clock_t c;
	srand(time(NULL));


	while(i<5){Afin emisor(bytes);i++;}
	c = clock();
	Afin emisor(bytes);
    string mc=emisor.cifrado(mensaje);
    c = clock() - c;
    cout<<"Mensaje cifrado: "<<mc<<endl;
    cout << "Tiempo: " << ((float)c) / CLOCKS_PER_SEC << endl;
    a=0,
    cout<<"A: ";
    cin>>a;
	b=0;
	cout<<"B: ";
	cin>>b;
	c = clock();
    Afin receptor(a,b);
	string md=receptor.descifrado(mc);
	c = clock() - c;
	cout<<"Mensaje descifrado: "<<md<<endl;

	cout << "Tiempo: " << ((float)c) / CLOCKS_PER_SEC << endl;



	system("pause");
	return 0;
}
