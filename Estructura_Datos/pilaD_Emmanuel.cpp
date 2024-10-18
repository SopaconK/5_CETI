// Cola Dinamica
// Emmanuel 22300891 5I

#include<iostream>
using namespace std;

struct Node{
    int dato;
    Node* sig;
} *pila, *tope, *aux;

void Inicializar(){
    pila=NULL;
}
bool vacia(){
    if(pila==NULL){
        return true;
    }
    return false;
}

void push(int valor){
    if(vacia()){
        pila=new Node;
        pila->sig=NULL;
        pila->dato=valor;
        tope=pila;
    }
    else{
        aux=new Node();
        aux->sig=NULL;
        aux->dato=valor;
        tope->sig=aux;
        tope=aux;
    }
}
void pop(){
    if(vacia()){
        cout<<"Pila vacia"<<endl;
    }
    else{
       aux=pila;
       if(pila==tope){
        delete pila;
        Inicializar();
       } 
       else{
        while(aux->sig!=tope){
            aux=aux->sig;
        }
        delete tope;
        aux->sig=NULL;
        tope=aux;
       }
    }
}

void Imprimir(){
    if(vacia()){
        cout<<"Pila vacia"<<endl;
    }
    else{
        aux=pila;
        while(aux!=tope){
            cout<<aux->dato<<" ";
            aux=aux->sig;
        }
        cout<<aux->dato<<endl;
    }
}

void Limpiar(){
    if(vacia()){
        cout<<"Ya esta vacia"<<endl;
    }
    else{
        aux=pila;
        while(pila!=tope){
            aux=aux->sig;
            delete pila;
            pila=aux;
        }
        delete pila;
        Inicializar();
    }
}


void Tope(){
    if(vacia()){
        cout<<"Pila vacia"<<endl;
    }
    else{
        cout<<"El valor del tope es: "<<tope->dato<<endl;
    }
}

int main(){

    bool continuar=true;
    do{
        cout<<"Que quieres hacer"<<endl;
        cout<<"[1] Push (X) //Ingresa un elemento en la posición tope"<<endl;
        cout<<"[2] Pop //Elimina un elemento (primero que entra primero que sale)"<<endl;
        cout<<"[3] Imprimir (Imprime la cola)"<<endl;
        cout<<"[4] Limpia (Limpia la cola)"<<endl;
        cout<<"[5] Tope (Imprime el valor del tope)"<<endl;
        cout<<"[6] Salir (Sale del sistema)"<<endl;
        
        int tipo;
        cin>>tipo;
        int val;
        switch(tipo){
            case 1:
                cout<<"Que valor?"<<endl;
                cin>>val;
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                Imprimir();
                break;
            case 4:
                Limpiar();
                break;
            case 5: 
                Tope();
                break;
            case 6:
                Limpiar();
                continuar=false;
                break;
        }
      
    }while(continuar);
}
