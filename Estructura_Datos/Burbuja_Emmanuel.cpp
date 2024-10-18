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
        for(int i=1; i<=n-1; ++i){
            for(int j=0; j<n-i; ++j){
                if(datos[j]>datos[j+1]){
                    int aux=datos[j]; // Entero auxiliar para intercambiar los dos valores
                    datos[j]=datos[j+1];
                    datos[j+1]=aux;
                }
            }
            cout<<"Iteracion "<<i<<":"<<endl;
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
