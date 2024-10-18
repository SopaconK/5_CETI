// Quick Sort
// Emmanuel 22300891 5I

#include<iostream>
using namespace std;
int n;
void MergeSort(int datos[], int tam){
    int m=tam/2;
    int L[m];
    int R[tam-m];
    for(int i=0; i<tam; i++){
        if(i<m){
            L[i]=datos[i];
        }
        else{
            R[i-m]=datos[i];
        }
    }
    cout<<"Arreglo partido  "<<endl;
    for(int i=0; i<m; i++){
        cout<<L[i]<<" ";
    }
    cout<<"        ";
    for(int i=0; i<tam-m; i++){
        cout<<R[i]<<" ";
    }
    cout<<endl;
    if(m>1) MergeSort(L, m);
    if(tam-m>1) MergeSort(R, tam-m);
    int ind1=0;
    int ind2=0;
    while(ind1<m && ind2<tam-m){
        if(L[ind1]<R[ind2]){
            datos[ind1+ind2]=L[ind1];
            ind1++;
        }
        else{
            datos[ind1+ind2]=R[ind2];
            ind2++;
        }
    }
    while(ind1<m){
        datos[ind1+ind2]=L[ind1];
        ind1++;
    }
    while(ind2<tam-m){
         datos[ind1+ind2]=R[ind2];
        ind2++;
    }
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
        MergeSort(datos, n);
        
        cout<<endl;
        cout<<"Quieres continuar? (1 si, 0 no)"<<endl;
        cin>>continuar;
    }while(continuar);
}
