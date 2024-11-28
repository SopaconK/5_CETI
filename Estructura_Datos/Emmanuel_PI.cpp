//Emmanuel Buenrostro Briseño 22300891
//Par Impar

#include<iostream>
using namespace std;

struct Node{
    int dato;
    Node* sig;
} *pila, *topeP, *topeC, *aux, *cola;

void InicializarP(){
    pila=NULL;
}
bool vaciaP(){
    if(pila==NULL){
        return true;
    }
    return false;
}

void pushP(int valor){
    if(vaciaP()){
        pila=new Node;
        pila->sig=NULL;
        pila->dato=valor;
        topeP=pila;
    }
    else{
        aux=new Node();
        aux->sig=NULL;
        aux->dato=valor;
        topeP->sig=aux;
        topeP=aux;
    }
}
void popP(){
    if(vaciaP()){
        cout<<"Pila vacia"<<endl;
    }
    else{
       aux=pila;
       if(pila==topeP){
        delete pila;
        InicializarP();
       } 
       else{
        while(aux->sig!=topeP){
            aux=aux->sig;
        }
        delete topeP;
        aux->sig=NULL;
        topeP=aux;
       }
    }
}

void ImprimirP(){
    if(vaciaP()){
        cout<<"Pila vacia"<<endl;
    }
    else{
        aux=pila;
        while(aux!=topeP){
            cout<<aux->dato<<" ";
            aux=aux->sig;
        }
        cout<<aux->dato<<endl;
    }
}

void LimpiarP(){
    if(vaciaP()){
        cout<<"Ya esta vacia"<<endl;
    }
    else{
        aux=pila;
        while(pila!=topeP){
            aux=aux->sig;
            delete pila;
            pila=aux;
        }
        delete pila;
        InicializarP();
    }
}


void InicializarC(){
    cola=NULL;
}
bool vaciaC(){
    if(cola==NULL){
        return true;
    }
    return false;
}

void encolarC(int valor){
    if(vaciaC()){
        cola=new Node;
        cola->sig=NULL;
        cola->dato=valor;
        topeC=cola;
    }
    else{
        aux=new Node();
        aux->sig=NULL;
        aux->dato=valor;
        topeC->sig=aux;
        topeC=aux;
    }
}
void desencolarC(){
    if(vaciaC()){
        cout<<"Cola vacia"<<endl;
    }
    else{
       aux=cola->sig;
       delete cola;
       cola=aux;
    }
}

void ImprimirC(){
    if(vaciaC()){
        cout<<"Cola vacia"<<endl;
    }
    else{
        aux=cola;
        while(aux!=topeC){
            cout<<aux->dato<<" ";
            aux=aux->sig;
            }
        cout<<aux->dato<<endl;
    }
}

void LimpiarC(){
    if(vaciaC()){
        cout<<"Ya esta vacia"<<endl;
    }
    else{
        aux=cola;
        while(cola!=topeC){
            aux=aux->sig;
            delete cola;
            cola=aux;
        }
        delete cola;
        InicializarC();
    }
}


int main(){
    InicializarC();
    InicializarP();
    bool continuar=true;
    while(continuar){
        cout<<"Que quieres hacer? \n 1.Agregar Dato \n 2.Imprimir \n 3.Eliminar \n 4.Limpiar \n 5.Salir"<<endl;
        int type;
        cin>>type;
        if(type==1){
            int x;
            cout<<"Dame el dato"<<endl;
            cin>>x;
            if(x%2==1){
                encolarC(x);
            }
            else{
                pushP(x);
            }
        }
        else if(type==2){
            cout<<"Pila: "<<endl;
            ImprimirP();
            cout<<endl<<"Cola: "<<endl;
            ImprimirC();
        }
        else if(type==3){
            popP();
            desencolarC();
        }
        else if(type==4){
            LimpiarC();
            LimpiarP();
        }
        else if(type==5){
            continuar=false;
        }
    }
}