// Busqueda Secuencial
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

        bool buscar=false;
        do{
            int elem;
            cout<<"Que elemento quieres buscar?"<<endl;
            cin>>elem;
            for(int i=0; i<n; i++){
                if(datos[i]==elem){
                    cout<<"El elemento se encuentra en la posicion "<<i<<endl;
                    break;
                }
                if(i==n-1){
                    cout<<"El elemento no se encontro"<<endl;
                }
            }
            cout<<"Quieres bucar otro elemento? (1 si 0 no)" <<endl;
            cin>>buscar;
        }
        while(buscar);
        
        cout<<endl;
        cout<<"Quieres continuar? (1 si, 0 no)"<<endl;
        cin>>continuar;
    }while(continuar);
}
