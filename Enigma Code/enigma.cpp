#include "enigma.h"
#include <string.h>

Enigma::Enigma(int r1,int r2,int r3,string clave,string finales,string ste){ 
	rotor1=arr[r1-1];
	rotor2=arr[r2-1];
	rotor3=arr[r3-1];
	key=clave;
	limites=finales;
	steckers=ste;

	c=alfabeto.find(clave[0]);
	b=alfabeto.find(clave[1]);
	a=alfabeto.find(clave[2]); 
}

int Enigma::modulo(int a,int n){
	int r=0,q=0;
	q=a/n;
	r=a-(q*n);
	if(r<0){
		r+=n;
	}
	return r;                     
}
								
string Enigma::cifrado(string m){
	string mc;

		for(int i=0;i<m.length();i++){
		
			int x=0;string aux;        	
			if(a==tamAlf){
				a=modulo(a,tamAlf);}
			if(b==tamAlf){
				b=modulo(b,tamAlf);}
			if(c==tamAlf){
				c=modulo(c,tamAlf);}
			
			a++;
			if(a==alfabeto.find(limites[2])){
				b++;}
			if(b==alfabeto.find(limites[1])){
				c++;}
						
			//3 ROTOR
			if(m[i]==steckers[0]){
				m[i]=steckers[1];}
			else if(m[i]==steckers[1]){
				m[i]=steckers[0];} 
					 
			x = alfabeto.find(m[i]);  
			x+=a;
			x=modulo(x,tamAlf);			
			aux=rotor3[x];                      
			x = alfabeto.find(aux);   
			x-=a;
			x=modulo(x,tamAlf);
			aux=alfabeto[x];
			//cout<<"3 rotor: "<<aux<<endl;
			
			//2 ROTOR		
			x = alfabeto.find(aux);
			x+=b;
			x=modulo(x,tamAlf);
			aux=rotor2[x]; 
			x = alfabeto.find(aux); 
			x-=b;
			x=modulo(x,tamAlf);
			aux=alfabeto[x];
			//cout<<"2 rotor: "<<aux<<endl;
			
			//1 ROTOR
			x = alfabeto.find(aux);
			x+=c;
			x=modulo(x,tamAlf);
			aux=rotor1[x];
			x = alfabeto.find(aux);
			x-=c;
			x=modulo(x,tamAlf);
			aux=alfabeto[x];
			//cout<<"1 rotor: "<<aux<<endl;
			
			//REFLECTOR
			x = alfabeto.find(aux);
			/*x+=c;
			x=modulo(x,tamAlf);*/
			aux=reflector[x];
			//cout<<"Reflector: "<<aux<<endl;
			
			//1 ROTOR DE VUELTA
			x = alfabeto.find(aux);
			x+=c;
			x=modulo(x,tamAlf);               	
			aux=alfabeto[x];	
			x=rotor1.find(aux);
			x-=c;
			x=modulo(x,tamAlf);
			aux=alfabeto[x];
			//cout<<"1v rotor: "<<aux<<endl;
			
			//2 ROTOR DE VUELTA	
			x = alfabeto.find(aux);
			x+=b;
			x=modulo(x,tamAlf);
			aux=alfabeto[x];
			x=rotor2.find(aux);
			x-=b;
			x=modulo(x,tamAlf);
			aux=alfabeto[x];
			//cout<<"2v rotor: "<<aux<<endl;
			
			//3 ROTOR DE VUELTA	
			x = alfabeto.find(aux);
			x+=a;
			x=modulo(x,tamAlf);
			aux=alfabeto[x];              
			x=rotor3.find(aux);        
			aux=alfabeto[x];              
			x-=a;             
			x=modulo(x,tamAlf);
			aux=alfabeto[x];
			//cout<<"3v rotor: "<<aux<<endl;
			
			if(aux[0]==steckers[0]){
				aux[0]=steckers[1];}
			else if(aux[0]==steckers[1]){
				aux[0]=steckers[0];} 
				
			mc+=aux;
			
			//cout<<"Vuelta :"<<a<<endl;			
		}		
	return mc;	
}

string Enigma::descifrado(string m){
	string md;
	c=alfabeto.find(key[0]);
	b=alfabeto.find(key[1]);
	a=alfabeto.find(key[2]);
	md=cifrado(m);
	return md;
}
