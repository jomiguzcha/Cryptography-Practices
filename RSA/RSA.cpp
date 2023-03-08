#include "RSA.h"

string RSA::zz_To_String(ZZ z) {
    stringstream buffer;
    buffer << z;
    return buffer.str();
}

ZZ RSA::String_To_zz(string p) {
    char oracion[100000];
    strcpy(oracion,p.c_str());
    return conv<ZZ>(oracion);
}

ZZ RSA::eucExt(ZZ a,ZZ b){
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

ZZ RSA::modulo(ZZ a,ZZ n){
	ZZ r,q;
	q=a/n;
	r=a-(q*n);
	if(r<0){
		r+=n;
	}
	return r;
}

ZZ RSA::inversa(ZZ a,ZZ b){
    ZZ i=eucExt(a,b);
    if(i<0){
        return modulo(i,b);
    }
    else{
        return i;
    }
}

ZZ RSA::expRap(ZZ b, ZZ expo, ZZ NN) {
    ZZ exp=ZZ(1);
    ZZ x=modulo(b,NN);
    while(expo>ZZ(0)){
        if(modulo(expo,ZZ(2))==ZZ(1))
            exp=modulo(exp*x,NN);
        x=modulo(x*x,NN);
        expo=expo/ZZ(2);
    }
    return exp;
 }

ZZ RSA::Resto_Chino(ZZ a_1,ZZ mod1,ZZ a_2,ZZ mod2){
    ZZ dp,dq;
    dp=modulo(d,p-1);dq=modulo(d,q-1);

    a_1=expRap(modulo(a_1,p),dp,p);
    a_2=expRap(modulo(a_2,q),dq,q);
	ZZ m=mod1*mod2;ZZ res;
	ZZ m1=m/mod1;ZZ m2=m/mod2;
	ZZ inv1=inversa(m1,mod1);ZZ inv2=inversa(m2,mod2);
	res=(a_1*m1*inv1)+(a_2*m2*inv2);
	res=modulo(res,m);

	return res;
}

void RSA::calcular_esp(string m){
    string aux,es=" ";

    for(int i=0;i<m.length();i++){
        if(m[i]!= es[0]){
            aux+=m[i];
        }
        else if(m[i]==es[0]){
            w.push_back(aux.length());
            aux="";
        }
    }
}

vector<string> RSA::generar_bloques_n_1(string men,int n){
    vector<string> block;
    ZZ z,menos_significativa;
    string x,h,cifra="0";

    menos_significativa=alfabeto.find("w");
    int aux=n-1;

    for(int i=0;i<men.length();i++){
        z=alfabeto.find(men[i]);
        //cout<<"La palabra numerica: "<<z<<endl;
        if(z<10){
            h=zz_To_String(z);
            h.insert(0,cifra);
            x+=h;
            continue;
        }
    x+=zz_To_String(z);}


    for(int j=0;j<x.length();j+=aux){
        h.clear();
        h=x.substr(j,aux);

        while(h.length()<aux){
            if(h.length()==aux-1){
                h+=(zz_To_String(menos_significativa))[0];
            }
            else{
                h+=zz_To_String(menos_significativa);
            }
        }

        //cout<<"Bloques: "<<h<<endl;
        block.push_back(h);
    }
    return block;
}

vector<string> RSA::generar_bloques_menor_n(string men){
    vector<string> block;
    ZZ z,menos_significativa;
    string x,h,cifra="0";
    bool end=0;

    menos_significativa = alfabeto.find("w");

    for(int i=0;i<men.length();i++){
        z=alfabeto.find(men[i]);
        //cout<<"La palabra numerica: "<<z<<endl;
        if(z<10){
            h=zz_To_String(z);
            h.insert(0,cifra);
            x+=h;
            continue;
        }
    x+=zz_To_String(z);}

    for(int i=0;i<x.length();){
        h=x[i];i++;

        while(String_To_zz(h)<N){
            if(i>=x.length()){
                h+=zz_To_String(menos_significativa);
                end=1;
            }
            else{
                h+=x[i];
                i++;
            }
        }

        if(end && String_To_zz(h)>N ){
            h.pop_back();
            h.pop_back();
        }

        else if(String_To_zz(h)>N){
            h.pop_back();
            i--;
        }

        cout<<"Bloques: "<<h<<endl;
        block.push_back(h);
    }

    return block;

}

RSA::RSA(int c){
    p=RandomPrime_ZZ(c);
    q=RandomPrime_ZZ(c);
    N=p*q;
    phi=(p-1)*(q-1);
    e= RandomBnd(phi);
    while(GCD(e,phi)!=1){
        e= RandomBnd(phi);}
    d=modulo(inversa(e,phi),phi);
    cout<<"E: "<<e<<endl;
    cout<<"N: "<<N<<endl;
    cout<<"D: "<<d<<endl;
}

RSA::RSA(string a,ZZ P,ZZ n){
    if(a=="des"){
        d=P; N=n;
        //calcular_esp(es);
    }
    else if(a=="des_b"){
        d=P;N=n;
        cout<<"D: "<<d<<endl;
        cout<<"N: "<<N<<endl;
    }
    else{
        e=P;N=n;
        cout<<"E: "<<e<<endl;
        cout<<"N: "<<N<<endl;
    }
}


ZZ RSA::cifrado(string m){
    int aux=0;
    ZZ mc,z;
    string x="",y="";

    for(int i=0;i<m.length();i++){
        z=alfabeto.find(m[i]);
        //cout<<"La palabra numerica: "<<z<<endl;
        mc=expRap(z,e,N);
        y=zz_To_String(mc);
        x+=y;
        w.push_back(y.length());
        }
    mc=String_To_zz(x);
    return mc;
}

string RSA::descifrado(ZZ mc){
    int aux=0;
    ZZ x,y;
    string cifra="0",z="",md,len,aux2;

    len=zz_To_String(mc);

    for(int i=0;i<len.length();){
        aux2=len.substr(i,w[aux]);
        y=String_To_zz(aux2);
        //x=expRap(y,d,N);
        x=Resto_Chino(y,p,y,q);
        //cout<<"La palabra numerica: "<<x<<endl;
        if(x<10){
            md=zz_To_String(x);
            md.insert(0,cifra);
            z+=md;
            i+=w[aux];
            aux++;
            continue;
        }
        z+=zz_To_String(x);
        i+=w[aux];
        aux++;
    }
    md.clear();
    //cout<<"Antes de alfabetizar: "<<z<<endl;

    for(int i=0;i<z.length();i+=2){
        aux2=z.substr(i,2);
        y=String_To_zz(aux2);
        aux=conv<int>(y);
        md+=alfabeto[aux];}

    return md;
}

string RSA::cifradoblocks(string m){
    string n=zz_To_String(N),cifra="0",almacenar="",aux;
    ZZ exp,mc;
    vector<string> block;

    int len_n=n.length();
    //block=generar_bloques_n_1(m,len_n);
    block=generar_bloques_menor_n(m);

    for(int i=0;i<block.size();i++){
        mc=String_To_zz(block[i]);
        exp=expRap(mc,e,N);
        aux=zz_To_String(exp);
        while(aux.length()<len_n){
            aux.insert(0,cifra);}
        //cout<<"Bloques Cifrados: "<<aux<<endl;
        almacenar+=aux;
    }

    return almacenar;
}

string RSA::descifradoblocks(string mc){
    ZZ aux2,des_exp;
    string n=zz_To_String(N),cifra="0",aux,almacenar="",md,menos_significativa="w";
    int ind=0;

    int len_n=n.length();

    for(int j=0;j<mc.length();j+=len_n){
        md=mc.substr(j,len_n);
        //cout<<"Bloques a descifrar:"<<md<<endl;
        des_exp=String_To_zz(md);
        aux2=expRap(des_exp,d,N);
        //aux2=Resto_Chino(des_exp,p,des_exp,q);
        md=zz_To_String(aux2);
        while(md.length()<(len_n-1)){
            md.insert(0,cifra);}
        //cout<<"Bloques:"<<md<<endl;
        almacenar+=md;
    }

    md.clear();
    for(int i=0;i<almacenar.length();i+=2){
        aux=almacenar.substr(i,2);
        aux2=String_To_zz(aux);
        ind=conv<int>(aux2);
        md+=alfabeto[ind];
    }

    while(md.back()==menos_significativa[0]){
        md.pop_back();
    }

    return md;
}
