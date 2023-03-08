#include "ElGamal.h"

string ElGamal::zz_To_String(ZZ z) {
    stringstream buffer;
    buffer << z;
    return buffer.str();
}

ZZ ElGamal::String_To_zz(string p) {
    char oracion[10000];
    strcpy(oracion,p.c_str());
    return conv<ZZ>(oracion);
}

ZZ ElGamal::eucExt(ZZ a,ZZ b){
    ZZ r,r1=a,r2=b,s,t,q;
    ZZ s1,s2,t1,t2;
    s1=1;s2=0;t1=0;t2=1;
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

ZZ ElGamal::modulo(ZZ a,ZZ n){
	ZZ r,q;
	q=a/n;
	r=a-(q*n);
	if(r<0){
		r+=n;
	}
	return r;
}

ZZ ElGamal::inversa(ZZ a,ZZ b){
    ZZ i=eucExt(a,b);
    if(i<0){
        return modulo(i,b);
    }
    else{
        return i;
    }
}

ZZ ElGamal::expRap(ZZ b, ZZ expo, ZZ NN) {

   ZZ result;result=1;

   while (expo > 0) {
      if ((expo & 1) > 0) {
	  	result = (result * b);
	  	result=modulo(result,NN);
		}
      expo >>= 1;
      b = (b*b);
      b = modulo(b,NN);
   }

   return result;

 }

vector<ZZ> ElGamal::Fact(ZZ n){
    ZZ aux;aux=2;
    vector<ZZ> fact;
  while (n>1) {
    if (modulo(n,aux)==0) {
      cout <<aux<<endl;
      fact.push_back(aux);
      n/=aux;
    }
    else{
      aux++;}
}
  return fact;
}

ZZ ElGamal::RaizPrimitiva(ZZ n){
    ZZ aux,q,found,g;
    q=(n-1)/2;
    found=0;aux=2;
    while(found!=1){
        g=RandomBnd(n-1);
        if((expRap(g,aux,n)!=1)&&(expRap(g,q,n)!=1)){
            found=1;
        }
    }
    return g;
}

ElGamal::ElGamal(int b){
    p=RandomPrime_ZZ(b);
    alpha=RaizPrimitiva(p);
    lambda=modulo(RandomPrime_ZZ(b),p);
    beta=expRap(alpha,lambda,p);
    /*p=83;
    alpha=2;
    beta=70;
    lambda=4;*/
    /*cout<<"P: "<<p<<endl;
    cout<<"Alpha: "<<alpha<<endl;
    cout<<"Lambda: "<<lambda<<endl;
    cout<<"Beta: "<<beta<<endl;*/
}

vector<ZZ> ElGamal::cifradonum(ZZ m){
    vector<ZZ> c;ZZ aux,c1,c2;

    r= RandomBnd(p-2);
    r=11;
    c1=expRap(alpha,r,p);
    aux=expRap(beta,r,p);
    c2=modulo(m*aux,p);

    c.push_back(c1);
    c.push_back(c2);

    return c;
}

ZZ ElGamal::descifradonum(vector<ZZ> m){
    ZZ n1,n2,resul;

    n1=expRap(m[0],lambda,p);
    n2=inversa(n1,p);
    resul=modulo(m[1]*n2,p);

    return resul;
}

string ElGamal::cifrado(string m){
    int cont=0;ZZ k,conv,z,temp,len_p;string c,alfa,temp2,aux2,cifra="0";

    aux2=zz_To_String(p);
    len_p=aux2.length();

    for(int i=0;i<m.length();i++){
        z=alfabeto.find(m[i]);
        if(z<10){
            temp2=zz_To_String(z);
            temp2.insert(0,cifra);
            alfa+=temp2;
            continue;
        }
        alfa+=zz_To_String(z);
    }

    r= RandomBnd(p-2);//r=5;
    c1=expRap(alpha,r,p);
    k=expRap(beta,r,p);

    for(int i=0;i<m.length();i++,cont+=2){
        aux2=alfa[cont];
        aux2+=alfa[cont+1];
        conv=String_To_zz(aux2);

        temp=modulo(conv*k,p);
        temp2=zz_To_String(temp);
        while(temp2.length()<len_p){
            temp2.insert(0,cifra);}
        c+=temp2;
    }

    aux2=zz_To_String(c1);
    c.insert(0,aux2);
    return c;
}

string ElGamal::descifrado(string m){
    int len_c1,len_p,cont;
    ZZ n1,n2,temp,temp2;string resul,alfa,aux,aux2,cifra="0";

    aux2=zz_To_String(p);len_p=aux2.length();
    aux2=zz_To_String(c1);cont=aux2.length();
    len_c1=cont;

    n1=expRap(c1,lambda,p);
    n2=inversa(n1,p);

    for(int i=len_c1;i<m.length();i+=len_p){
        aux.clear();
        for(int j=0;j<len_p;j++,cont++){
            aux+=m[cont];
        }
        temp2=String_To_zz(aux);

        temp=modulo(temp2*n2,p);
        if(temp<10){
            aux2=zz_To_String(temp);
            aux2.insert(0,cifra);
            alfa+=aux2;
            continue;
        }
        aux2=zz_To_String(temp);
        alfa+=aux2;
    }

    for(int i=0;i<alfa.length();i+=2){
        aux=alfa.substr(i,2);
        temp=String_To_zz(aux);
        cont=conv<int>(temp);
        resul+=alfabeto[cont];
    }

    return resul;
}
