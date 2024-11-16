// Lista Circular Doble
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
    if(vacia()){
        L=a;
        L->sig=L;
        L->ant=L;
    }
    else{
        if(a->dato < L->dato){
            a->sig=L;
            L->ant->sig=a;
            a->ant=L->ant;
            L->ant=a;
            L=a;
        }
        else{
            a2=L;
            while(a2->sig!=L && a2->sig->dato <x){
                a2=a2->sig;
            }
            a->sig=a2->sig;
            a->ant=a2;
            a2->sig->ant=a;
            a2->sig=a;
            
        }
    }
}

bool busca(int x){
    a=L;
    if(vacia()) return false;
    if(a->dato==x) return true;
    a=a->sig;
    while(a!=L && a->dato!=x){
        a=a->sig;
    }
    if(a->dato==x){
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
        if(L->sig==L){
            delete L;
            Inicializar();
        }
        else{
        if(L->dato==x){
           
            a=L;
            L->ant->sig=L->sig;
            L->sig->ant=L->ant;
            L=L->sig;
            delete a;
    
        }
        else{
            a=L;
            do{
                if(a->dato==x) break;
                a=a->sig;
            }while(a!=L);
            a->ant->sig=a->sig;
            a->sig->ant=a->ant;
            delete a;
        }
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
        do{
            cout<<a->dato<<" ";
            a=a->sig;
        }while(a!=L);
    }
}

void Limpiar(){
    if(vacia()){
        cout<<"Ya esta vacia"<<endl;
    }
    else{
        a=L;
        while(a->sig!=L){
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
