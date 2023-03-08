#include "protocolo.h"
protocolo::protocolo(int b){
    p_elgamal=generar_random(b);
    raiz_primitiva=Generar_raiz_primitiva(p_elgamal);

    p_rsa=generar_random(b);
    q_rsa=generar_random(b);
    N=p_rsa*q_rsa;
    phi=(p_rsa-1)*(q_rsa-1);
    e=generare(phi,b);
    d=inversa(modulo(phi,N),e);

    /*p_elgamal=ZZ(2203);
    raiz_primitiva=ZZ(5);
    e=;
    N=;*/
}

ZZ protocolo::getN_rsa(){return N;}

ZZ protocolo::getG_raiz_primitiva(){return raiz_primitiva;}

ZZ protocolo::getP_elgamal(){return p_elgamal;}

ZZ protocolo::gete_rsa(){return e;}

vector<string> protocolo::cifrado(string mensaje){
/// ////////////ASCII//////////////////////
    string mensaje_numero;
    string bloques_menores_p_gamal;
    vector<string> bloques_final;
    vector<string> fin;

    for(int i=0;i<mensaje.size();i++){
        int tempo;
        tempo=mensaje[i];
        string tempo_2=int_to_string(tempo);
        tempo_2.insert(0,ZZ_to_string(ZZ(255)).size()-tempo_2.size(),'0');
        mensaje_numero+=tempo_2;
    }

    //cout<<"Palabra Numerica: "<<mensaje_numero<<endl;
/// /////////// BLOCKS GENERATION ////////////////
    for(int i=0;i<mensaje_numero.size();i++){
        bloques_menores_p_gamal+=mensaje_numero[i];
        if(string_to_ZZ(bloques_menores_p_gamal)>p_elgamal){
            bloques_final.push_back(bloques_menores_p_gamal.substr(0,bloques_menores_p_gamal.size()-1));
            //cout<<"Bloques: "<<bloques_menores_p_gamal.substr(0,bloques_menores_p_gamal.size()-1)<<endl;
            bloques_menores_p_gamal=mensaje_numero[i];
        }
    }
    bloques_final.push_back(bloques_menores_p_gamal);
    //cout<<"Bloques: "<<bloques_menores_p_gamal<<endl;

/// ////////// BLOCKS CYPHER  //////////
    ZZ r;r=RandomBnd(p_elgamal);
    ZZ K;ZZ Ca;
    string resultado;
    string r_bin=binario(r);
    string e_bin=binario(e);

    K=bynexpo(raiz_primitiva,r_bin,p_elgamal);
    Ca=bynexpo(r,e_bin,N);

    for(int i=0;i<bloques_final.size();i++){
        string pre_resultado;
        ZZ para_cifrar;
        para_cifrar=string_to_ZZ(bloques_final[i]);
        pre_resultado=ZZ_to_string(modulo(para_cifrar*K,p_elgamal));
        pre_resultado.insert(0,ZZ_to_string(p_elgamal).size()-pre_resultado.size(),'0');
        resultado+=pre_resultado;
    }

    fin.push_back(ZZ_to_string(Ca));
    fin.push_back(resultado);
    return fin;
}

string protocolo::descifrado(vector<string> mensaje){
    ZZ Ca;string Cm;
    Ca=string_to_ZZ(mensaje[0]);Cm=mensaje[1];
    string d_bin=binario(d);
    string mensaje_numero,descifrado,aux;

    ZZ a;a=bynexpo(Ca,d_bin,N);
    string a_bin=binario(a);
    ZZ k;k=bynexpo(raiz_primitiva,a_bin,p_elgamal);

    ZZ k_1;k_1=inversa(p_elgamal,k);

    for(int i=0;i<Cm.size();i++){
        string num;
        aux+=Cm[i];
        if(aux.size()>ZZ_to_string(p_elgamal).size()){
            num=ZZ_to_string(modulo(string_to_ZZ(aux.substr(0,aux.size()-1))*k_1,p_elgamal));
            num.insert(0,ZZ_to_string(p_elgamal).size()-num.size(),'0');
            //cout<<"Bloques_Des:"<<num<<endl;
            mensaje_numero+=num;
            aux=Cm[i];
        }
    }

    aux=ZZ_to_string(modulo(string_to_ZZ(aux)*k_1,p_elgamal));
    aux.insert(0,ZZ_to_string(p_elgamal).size()-aux.size(),'0');
    //cout<<"Bloques_Des:"<<aux<<endl;
    mensaje_numero+=aux;

    aux.clear();
    for(int i=0;i<mensaje_numero.size();i++){
        aux+=mensaje_numero[i];
        if(aux.size()>ZZ_to_string(ZZ(255)).size()){
            int tempo=string_to_int(aux.substr(0,aux.size()-1));
            descifrado+=ASCII_to_string(tempo);
            aux=mensaje_numero[i];
        }
    }

    int tempo=string_to_int(aux);
    descifrado+=ASCII_to_string(tempo);

    return descifrado;
}
