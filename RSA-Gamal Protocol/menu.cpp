#include "menu.h"
menu::menu(){

    cout<<"Ingrese el numero de bits: ";
    int bits;
    cin>>bits;
    protocolo claves(bits);
    fstream archivo("registro.txt");
    fstream archivo_cif("mensaje_texto.txt");
    do{
    cout<<"1.- Generar Claves\n 2.- Cifrar\n 3.- Descifrar\n4.- Cerrar\n";
    cin>>op;
    cin.ignore();
    if(op==1){
        if(!archivo.is_open()){
            archivo.open("registro.txt", ios::out);
        }
        cout<<"1.- Guardar claves\n 2.-Dar claves 3.- Regresar\n";
        cin>>op2;
        if(op2==1){
            archivo<<"N= "<<claves.getN_rsa()<<endl;
            archivo<<"G= "<<claves.getG_raiz_primitiva()<<endl;
            archivo<<"P= "<<claves.getP_elgamal()<<endl;
            archivo<<"E= "<<claves.gete_rsa()<<endl;
            system("cls");
            cout<<"Registro guardado con exito...\n";
            system("pause");
            system("cls");
        }
        if(op2==2){
            ifstream receptor("C:/Users/joseg/OneDrive/Escritorio/Protocolo/claves_receptor.txt");
            if(receptor.fail()){
                cout<<"Texto entrada claves_receptor.txt no existe"<<endl;
            }
            else{
                getline(receptor,n_receptor);
                getline(receptor,p_receptor);
                getline(receptor,g_receptor);
                getline(receptor,e_receptor);
            }
            //protocolo claves(n_receptor,p_receptor,g_receptor,e_receptor);
        }
        archivo.close();
    }
    if(op==2){
        ifstream datos("C:/Users/joseg/OneDrive/Escritorio/Protocolo/claves.txt");
        if(datos.fail()){
            cout<<"Texto entrada claves.txt no existe"<<endl;
        }
        else{
            getline(datos,n_aux);
            getline(datos,g_aux);
            getline(datos,p_aux);
            getline(datos,e_aux);
        }
        cout<<"1.- Cifrar texto\n 2.- Regresar\n";
        cin>>op2;
        if(op2==1){
            ifstream msn("C:/Users/joseg/OneDrive/Escritorio/Protocolo/mensaje.txt");
            getline(msn,mensaje_aux);
            vector<string> cif=claves.cifrado(mensaje_aux);
            archivo_cif.open("mensaje_cifrado.txt", ios::out);
            archivo_cif<<cif[0]<<endl;
            archivo_cif<<cif[1];
            archivo_cif.close();
            cout<<"Cifrado0:" <<cif[0]<<endl;
            cout<<"Cifrado1:" <<cif[1]<<endl;

            cout<<"Texto plano cifrado con exito :D ...\n";
            system("pause");
            system("cls");
        }
    }
    if(op==3){
        ifstream texto_cifrado("C:/Users/joseg/OneDrive/Escritorio/Protocolo/mensaje_cifrado.txt");
        if(texto_cifrado.fail()){
            cout<<"Texto entrada mensaje.txt no existe"<<endl;
        }
        else{
            getline(texto_cifrado,mensaje_a_descifrar_1);
            getline(texto_cifrado,mensaje_a_descifrar_2);
        }
        cout<<"1.- Descifrar texto\n 2.- Regresar\n";
        cin>>op2;
        if(op2==1){
            vector<string> cif;
            cif.push_back(mensaje_a_descifrar_1);
            cif.push_back(mensaje_a_descifrar_2);
            string descifrado=claves.descifrado(cif);
            cout<<"Descifrado: "<<descifrado<<endl;

            cout<<"Texto plano descifrado con exito :D ...\n";
            system("pause");
            system("cls");
        }
    }
  }while(op!=4);
}
