// Burbuja
// Emmanuel 22300891 5I

#include<iostream>
using namespace std;

int main(){
    bool continuar=false;
    do{
        continuar=false;
        int n;
        do{
            cout<<"Cuantos datos van a insertar (entre 2 y 20)"<<endl;
            cin>>n;
            if(n<2 || n>20){
                cout<<"Tienen que ser entre 2 y 20"<<endl;
            }
        } while(n<2 || n>20);
        int datos [n];
        bool repetidos=false;
        do{
            
            cout<<"Dame los datos enteros y sin valores repetidos"<<endl;
            for(int i=0; i<n; ++i){
                cin>>datos[i];
            }
            repetidos=false;
            for(int i=0; i<n; ++i){ 
                for(int j=0; j<i; ++j){
                    if(datos[i]==datos[j]) repetidos=true;
                }
            }
            if(repetidos){
                cout<<"Hay datos que estan repetidos por favor ingrese valores distintos"<<endl;
            }
        } while(repetidos);

        cout<<"Arreglo original:"<<endl;
        for(int i=0; i<n; ++i){ 
            cout<<datos[i]<<" ";
        }
        cout<<endl;
        for(int i=0; i<n-1; ++i){
            int pos=i;
            for(int j=i; j<n; ++j){
                if(datos[j]<datos[pos]){
                    pos=j;
                }
            }
            int aux=datos[i]; // Entero auxiliar para intercambiar
            datos[i]=datos[pos];
            datos[pos]=aux;
            cout<<"Iteracion "<<i+1<<":"<<endl;
            for(int j=0; j<n; ++j){
                cout<<datos[j]<<" ";
            }
            cout<<endl;
        }
        cout<<"Arreglo ordenado:"<<endl;
        for(int i=0; i<n; ++i){
            cout<<datos[i]<<" ";
        }
        cout<<endl;
        cout<<"Quieres continuar? (1 si, 0 no)"<<endl;
        cin>>continuar;
    }while(continuar);
}
