#include <NTL/ZZ.h>
#include <vector>
#include <thread>

using namespace std;
using namespace NTL;

vector<ZZ> SieveOfEratosthenes(ZZ n){
    vector<ZZ> sieve;
    vector<bool> valores;
    ZZ i,root,aux;

    root=SqrRoot(n);

    for(i=0;i<n/2;i++){//Cantidad de numeros antes de n, en este caso impares
            valores.push_back(1);
    }

    valores[0]=0;

    for(i=3;i<root;i+=2){
        if(valores[conv<int>(i/2)]==1){
            for(aux=3*i;aux<n;aux+=2*i){
                valores[conv<int>(aux/2)]=0;
            }
        }
    }

    for(i=3;i<n;i++){
        if(valores[conv<int>(i/2)]==1){
            sieve.push_back(i);
        }
    }

    return sieve;
}

int main(){
    unsigned int nThreads;
    nThreads=thread::hardware_concurrency();

    vector<ZZ> block;
    //ZZ a(RandomBits_ZZ(30));
    ZZ a(1000000000);

    cout<<"A: "<<a<<endl;

    block=SieveOfEratosthenes(a);
    cout<<"# de primos: "<<block.size()<<endl;
    cout<<"Primo más cercano: "<<block.back()<<endl;

    /*for(int i=0;i<block.size();i++){
        cout<<block[i]<<" ";
    }*/

    return 0;
}
