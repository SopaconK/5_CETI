// Shell
// Emmanuel 22300891 5I

#include<iostream>
using namespace std;
int n;

void Shell(int datos[], int tam, int dis){
    bool comp=false;
    for(int i=0; i<dis; i++){
        for(int j=i; j+dis<tam; j+=dis){
            if(datos[j]>datos[j+dis]){
                swap(datos[j], datos[j+dis]);
                comp=true;
            }
        }
    }
    cout<<"Iteracion"<<endl;
    for(int i=0; i<n; ++i){
        if(i%dis==0) cout<<"    ";
        cout<<datos[i]<<" ";
    }
    cout<<endl;
    if(comp) Shell(datos, tam, dis);
}

int main(){
    bool continuar=false;
    do{
        continuar=false;
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

        cout<<"Arreglo original: "<<endl;
        for(int i=0; i<n; ++i){
            cout<<datos[i]<<" ";
        }
        cout<<endl;
        int dis=n/2;
        while(dis>0){
            cout<<"Distancia "<<dis<<endl;
             for(int i=0; i<n; ++i){
                if(i%dis==0) cout<<"    ";
                cout<<datos[i]<<" ";
            }
            cout<<endl;
            Shell(datos, n, dis);
            dis/=2;
        }
        
        cout<<endl;
        cout<<"Quieres continuar? (1 si, 0 no)"<<endl;
        cin>>continuar;
    }while(continuar);
}
