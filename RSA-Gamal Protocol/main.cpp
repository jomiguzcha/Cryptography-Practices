#include "menu.h"
#include "ops.h"
#include "protocolo.h"

int main(){

    //enu Elmenu;

    /*protocolo emisor(64);

    cout<<"N: "<<emisor.getN_rsa()<<endl;
    cout<<"G: "<<emisor.getG_raiz_primitiva()<<endl;
    cout<<"P: "<<emisor.getP_elgamal()<<endl;
    cout<<"E: "<<emisor.gete_rsa()<<endl;

    string mensajes="no me creerias si te lo dijera";

    vector<string> cif=emisor.cifrado(mensajes);

    for(int i=0;i<2;i++){
        cout<<"Cifrado" <<i<<": "<<cif[i]<<endl;
    }

    /*string des=emisor.descifrado(cif);
    cout<<"Descifrado: "<<des<<endl;*/

   /* protocolo prueba(32);
    ZZ prob;prob=32;
    for(int i=0;i<2;i++){
        cout<<"Raiz"<<i<<": "<<Generar_raiz_primitiva(prob)<<endl;
    }*/
    for(int i =0; i<10; i++){
        cout<<"Aleatorio"<<i<<": "<<generar_random(64)<<endl;
    }

    return 0;
}
