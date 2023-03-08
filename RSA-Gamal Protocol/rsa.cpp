#include "rsa.h"
rsa::rsa(int a){
    p=GenPrime_ZZ(a);
    q=GenPrime_ZZ(a);
    n=p*q;
    phi=conv<ZZ>(((p-ZZ(1))*(q-ZZ(1))));
    e=generare(phi,a);
    d=inversa(modulo(phi,n),e);
}
rsa::rsa(ZZ e_receptor,ZZ n_receptor){
    e_ext=e_receptor;
    n_ext=n_receptor;
}
string rsa::cifrado(string mensaje){
    string cadena_letras;
    string bloque;
    string bin_e=binario(e_ext);
    vector<string> auxiliar;
    ZZ exponenciacion;
    string expo_aux;
    string mns;
    for(int i=0;i<mensaje.size();i++){
        if(int_to_string(mensaje[i]).size() < int_to_string(255).size()){
            cadena_letras=cadena_letras+'0'+int_to_string(mensaje[i]);
        }
        else{
            cadena_letras+=int_to_string(mensaje[i]);
        }
    }
    for(int i=0;i<cadena_letras.size();i++){
        bloque+=cadena_letras[i];
        if(string_to_ZZ(bloque)> n_ext){
            auxiliar.push_back(bloque.substr(0,bloque.size()-1));
            bloque=cadena_letras[i];
        }
    }
    auxiliar.push_back(bloque);
    for(int i=0;i<auxiliar.size();i++){
        exponenciacion=bynexpo(string_to_ZZ(auxiliar[i]),bin_e,n_ext);
        expo_aux=ZZ_to_string(exponenciacion);
        if(ZZ_to_string(exponenciacion).size()<ZZ_to_string(n_ext).size()){
            expo_aux.insert(0,ZZ_to_string(n_ext).size()-ZZ_to_string(exponenciacion).size(),'0');
        }
        mns+=expo_aux;
        expo_aux=" ";
    }
    return mns;
}
string rsa::descifrado(string a){
    string bloque;
    ZZ exponenciacion;
    string auxiliar;
    string expo_aux;
    string tmp;
    string resultado;
    vector <ZZ> operaciones=precalculo(d,q,p);
    for(int i=0;i<a.size();i++){
        bloque+=a[i];
        if(bloque.size()==ZZ_to_string(n).size()){
            exponenciacion=restochino(operaciones,string_to_ZZ(bloque));
            auxiliar+=ZZ_to_string(exponenciacion);
            bloque="";
        }
    }
    cout<<auxiliar<<endl;
    for(int i=0;i<auxiliar.size();i++){
        //cout<<i<<endl;
        tmp+=auxiliar[i];
        if(auxiliar[i]=='0'){
         cout<<tmp<<endl;
         resultado+=tmp;
         tmp="";
         continue;
        }
    }
    //cout<<resultado;
    return "s";
}
vector<ZZ> rsa::precalculo(ZZ d,ZZ q,ZZ p){
    vector<ZZ> auxiliar;
    ZZ dp;
    ZZ dq;
    dp=modulo(d,p-1);
    dq=modulo(d,q-1);
    ZZ p_inversa;
    p_inversa=bynexpo(p,binario(q-2),q);
    auxiliar.push_back(dp);
    auxiliar.push_back(dq);
    auxiliar.push_back(p_inversa);
    return auxiliar;
}
ZZ rsa::restochino(vector<ZZ> g,ZZ j){
    ZZ cp;
    ZZ cq;
    cp=modulo(j,p);
    cq=modulo(j,q);
    ZZ x1;
    ZZ x2;
    x1=bynexpo(cp,binario(g[0]),p);
    x2=bynexpo(cq,binario(g[1]),q);
    ZZ h;
    h=modulo(((x2-x1)*g[2]),q);
    ZZ x;
    x=x1+h*p;
    return x;
}
ZZ rsa::getd(){return d;}
ZZ rsa::gete(){return e;}
ZZ rsa::getn(){return n;}
ZZ rsa::getp(){return p;}
ZZ rsa::getq(){return q;}
