#include <NTL/ZZ.h>
#include "ElGamal.h"

using namespace std;
using namespace NTL;

int main(){
    int a=1024;
    ZZ by;by=64;
    ZZ mensaje;mensaje=26;
    string men="ILIKEMATHILIKEMATHILIKEMATHILIKEMATHILIKEMATHILIKEMATHILIKEMATHILIKEMATHILIKEMATHILIKEMATHILIKEMATHILIKEMATH",men_cifrado;
    vector<ZZ> cs;

    ElGamal emisor(a);
    for(int i=0;i<5;i++){
       cout<<"Raiz"<<i<<": "<<emisor.RaizPrimitiva(by)<<endl;
    }

    /*cs=emisor.cifradonum(mensaje);
    cout<<"C1: "<<cs[0]<<endl;
    cout<<"C2: "<<cs[1]<<endl;
    mensaje=emisor.descifradonum(cs);
    cout<<"Descifrado: "<<mensaje<<endl;*/

    /*men_cifrado=emisor.cifrado(men);
    cout<<"Cifrado: "<<men_cifrado<<endl;
    men=emisor.descifrado(men_cifrado);
    cout<<"Descifrado: "<<men<<endl;*/

    return 0;
}
