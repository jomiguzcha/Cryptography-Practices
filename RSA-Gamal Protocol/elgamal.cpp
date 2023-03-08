#include "elgamal.h"
elgamal::elgamal(int b){
    p=RandomPrime_ZZ(b);
    alpha=Generar_raiz_primitiva(p);
    lambda=modulo(RandomPrime_ZZ(b),p);
    lambda_bin=binario(lambda);
    beta=bynexpo(alpha,lambda_bin,p);
}

vector<ZZ> elgamal::cifradonum(ZZ m){
    vector<ZZ> c;ZZ aux,c1,c2;

    r= RandomBnd(p-2);
    r=11;
    string r_bin=binario(r);
    c1=bynexpo(alpha,r_bin,p);
    aux=bynexpo(beta,r_bin,p);
    c2=modulo(m*aux,p);

    c.push_back(c1);
    c.push_back(c2);

    return c;
}

ZZ elgamal::descifradonum(vector<ZZ> m){
    ZZ n1,n2,resul;

    n1=bynexpo(m[0],lambda_bin,p);
    n2=inversa(n1,p);
    resul=modulo(m[1]*n2,p);

    return resul;
}

string elgamal::cifrado(string m){
    int cont=0;ZZ k,conv,z,temp,len_p;string c,alfa,temp2,aux2,cifra="0";

    aux2=ZZ_to_string(p);
    len_p=aux2.length();

    for(int i=0;i<m.length();i++){
        z=alfabeto.find(m[i]);
        if(z<10){
            temp2=ZZ_to_string(z);
            temp2.insert(0,cifra);
            alfa+=temp2;
            continue;
        }
        alfa+=ZZ_to_string(z);
    }

    r= RandomBnd(p-2);//r=5;
    string r_bin=binario(r);
    c1=bynexpo(alpha,r_bin,p);
    k=bynexpo(beta,r_bin,p);

    for(int i=0;i<m.length();i++,cont+=2){
        aux2=alfa[cont];
        aux2+=alfa[cont+1];
        conv=string_to_ZZ(aux2);

        temp=modulo(conv*k,p);
        temp2=ZZ_to_string(temp);
        while(temp2.length()<len_p){
            temp2.insert(0,cifra);}
        c+=temp2;
    }

    aux2=ZZ_to_string(c1);
    c.insert(0,aux2);
    return c;
}

string elgamal::descifrado(string m){
    int len_c1,len_p,cont;
    ZZ n1,n2,temp,temp2;string resul,alfa,aux,aux2,cifra="0";

    aux2=ZZ_to_string(p);len_p=aux2.length();
    aux2=ZZ_to_string(c1);cont=aux2.length();
    len_c1=cont;

    n1=bynexpo(c1,lambda_bin,p);
    n2=inversa(n1,p);

    for(int i=len_c1;i<m.length();i+=len_p){
        aux.clear();
        for(int j=0;j<len_p;j++,cont++){
            aux+=m[cont];
        }
        temp2=string_to_ZZ(aux);

        temp=modulo(temp2*n2,p);
        if(temp<10){
            aux2=ZZ_to_string(temp);
            aux2.insert(0,cifra);
            alfa+=aux2;
            continue;
        }
        aux2=ZZ_to_string(temp);
        alfa+=aux2;
    }

    for(int i=0;i<alfa.length();i+=2){
        aux=alfa.substr(i,2);
        temp=string_to_ZZ(aux);
        cont=conv<int>(temp);
        resul+=alfabeto[cont];
    }

    return resul;
}
