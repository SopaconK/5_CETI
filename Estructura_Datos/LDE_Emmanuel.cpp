// Lista Doblemente Enlazada
// Emmanuel 22300891 5I

#include<iostream>
using namespace std;

struct Node{
    int dato;
    Node* sig;
    Node* ant;
} *L, *a, *a2;

void Inicializar(){
    L=NULL;
    a=NULL;
    a2=NULL;
}
bool vacia(){
    if(L==NULL){
        return true;
    }
    return false;
}

void Agrega(int x){
    a=new Node;
    a->dato=x;
    a->sig=NULL;
    a->ant=NULL;
    if(vacia()){
        L=a;
    }
    else{
        if(a->dato < L->dato){
            a->sig=L;
            L->ant=a;
            L=a;
        }
        else{
            a2=L;
            while(a2->sig!=NULL && a2->sig->dato <x){
                a2=a2->sig;
            }
            a->sig=a2->sig;
            a->ant=a2;
            a2->sig=a;
            if(a2->sig){
                a2->sig->ant=a;
            }
        }
    }
}

bool busca(int x){
    a=L;
    while(a && a->dato!=x){
        a=a->sig;
    }
    if(a){
        return true;
    }
    return false;
}

void Elimina(int x){
   if(vacia()){
    cout<<"Error, esta vacia"<<endl;
    return;
   }
   else{
    if(!busca(x)){
        cout<<"no se encuentra en la lista"<<endl;
    }
    else{
        if(L->dato==x){
            if(L->sig==NULL){
                delete L;
                Inicializar();
            }
            else{
                a=L;
                L=L->sig;
                delete a;
            }
        }
        else{
            a2=L;
            while(a2->sig && a2->sig->dato<x){
                a2=a2->sig;
            }
            a=a2->sig;
            a2->sig=a2->sig->sig;
            if(a->sig){
                a->sig->ant=a2;
            }
            delete a;
        }
    }
   }
}

void Imprimir(){
    if(vacia()){
        cout<<"Lista vacia"<<endl;
    }
    else{
        a=L;
        while(a){
            cout<<a->dato<<" ";
            a=a->sig;
        }
    }
}

void Limpiar(){
    if(vacia()){
        cout<<"Ya esta vacia"<<endl;
    }
    else{
        a=L;
        while(a->sig){
            a2=a->sig;
            delete a;
            a=a2;
        }
        delete a;
        Inicializar();
    }
}




int main(){

    bool continuar=true;
    do{
        cout<<"Que quieres hacer"<<endl;
        cout<<"[1] Agregar (X) "<<endl;
        cout<<"[2] Eliminar (X) "<<endl;
        cout<<"[3] Imprimir"<<endl;
        cout<<"[4] Limpia "<<endl;
        cout<<"[5] Salir (Sale del sistema)"<<endl;
        
        int tipo;
        cin>>tipo;
        int val;
        switch(tipo){
            case 1:
                cout<<"Que valor?"<<endl;
                cin>>val;
                Agrega(val);
                break;
            case 2:
                cout<<"Que valor?"<<endl;
                cin>>val;
                Elimina(val);
                break;
            case 3:
                Imprimir();
                break;
            case 4:
                Limpiar();
                break;
            case 5: 
                Limpiar();
                continuar=false;
                break;
        }
      
    }while(continuar);
}
