#include <NTL/ZZ.h>
#include <vector>

using namespace std;
using namespace NTL;


string conv_binario(ZZ num){
    string binario = "";

    if (num > 0) {
        while (num > 0) {
            if (num%2 == 0) {
                binario = "0"+binario;}
            else {
                binario = "1"+binario;}
            num/=2;
        }
    }
    else if (num == 0) {
        binario = "00000000";}

    return binario;
}

ZZ modulo(ZZ a,ZZ n){
	ZZ r,q;
	q=a/n;
	r=a-(q*n);
	if(r<0){
		r+=n;}
	return r;
}

ZZ RC4(string k){
    int len=256,aux_int=0;ZZ t,aux,len_zz;len_zz=256;
    ZZ s[len];ZZ f[len];

    //INICIALIZACION
    for(int i=0;i<len;i++){
        s[i]=i;}

    for(int j=0;j<len;){
        for(int i=0;i<k.length();i++,j++){
            f[j]=k[i]+0;    }
    }

    //KSA
    ZZ j;j=0;
    for (int i=0; i < len; i++) {
        j = (j + s[i] + f[i]) ;
        j=modulo(j,len_zz);

        aux_int=conv<int>(j);
        aux=s[i];
        s[i]=s[aux_int];
        s[aux_int]=aux;
    }

    //GENERADOR DE SECUENCIA
    int i=0;j=0;aux=conv<ZZ>(i);

    aux=modulo((aux+1),len_zz);
    i=conv<int>(aux);
    j = modulo((j + s[i]),len_zz);

    aux_int=conv<int>(j);
    aux=s[i];
    s[i]=s[aux_int];
    s[aux_int]=aux;

    t=s[i]+s[aux_int];
    t=modulo(t,len_zz);

    aux_int=conv<int>(t);

    return s[aux_int];
}

int main(){
    string mensaje="casa";
    ZZ res;

    res=RC4(mensaje);
    cout<<res<<endl;

    mensaje=conv_binario(res);
    cout<<mensaje<<endl;

    return 0;
}
