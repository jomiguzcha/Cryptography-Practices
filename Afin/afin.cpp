#include "afin.h"
#include <string.h>

int Afin::modulo(int a,int n){
	int r=0,q=0;
	q=a/n;
	r=a-(q*n);
	if(r<0){
		r+=n;
	}
	return r;
}

int Afin::mcd(int y,int x){
	int r=0;
	while(y!=0){
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}

int Afin::eucExt(int a,int b){
    int r,r1=a,r2=b,s,s1=1,s2=0,t,t1=0,t2=1,q;
    while (r2>0) {
	   q=r1/r2;
	   r=r1-(q*r2);
	   r1=r2;r2=r;

	   s=s1-(q*s2);
	   s1=s2;s2=s;

	   t=t1-(q*t2);
	   t1=t2;t2=t;
    }
	return s1;
}

int Afin::generadorRandom(int b){
	int a=0;
	while(mcd(a,tamAlf)!=1 || a<0){
		a=modulo(conv<int>(RandomPrime_ZZ(b)),1000000);}
	return a;
}

Afin::Afin(int z){
	a=generadorRandom(z);
	cout<<"Clave a:"<<a<<endl;
	b=generadorRandom(z);
	cout<<"Clave b:"<<b<<endl;
	inv_a=eucExt(a,tamAlf);
    if(inv_a<0){
    	modulo(inv_a,tamAlf);}
}

Afin::Afin(int x,int y){
    a=x;
    b=y;
    if(mcd(a,tamAlf)!=1){
    	cout<<"Clave Inadecuada"<<endl;
    }
    inv_a=eucExt(a,tamAlf);
    if(inv_a<0){
    	modulo(inv_a,tamAlf);}
}

string Afin::cifrado(string m){
	string mc;
	for(int i=0;i<m.length();i++){
		int aux=modulo((alfabeto.find(m[i])*a)+b,tamAlf);
        mc+=alfabeto[aux];
	}
	return mc;
}

string Afin::descifrado(string m){
	string md;
	for(int i=0;i<m.length();i++){
		int aux=modulo((alfabeto.find(m[i])-b)*inv_a,tamAlf);
        md+=alfabeto[aux];
	}
	return md;
}

