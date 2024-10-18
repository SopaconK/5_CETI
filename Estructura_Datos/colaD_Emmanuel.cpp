// Cola Dinamica
// Emmanuel 22300891 5I

#include<iostream>
using namespace std;

struct Node{
    int dato;
    Node* sig;
} *cola, *tope, *aux;

void Inicializar(){
    cola=NULL;
}
bool vacia(){
    if(cola==NULL){
        return true;
    }
    return false;
}

void encolar(int valor){
    if(vacia()){
        cola=new Node;
        cola->sig=NULL;
        cola->dato=valor;
        tope=cola;
    }
    else{
        aux=new Node();
        aux->sig=NULL;
        aux->dato=valor;
        tope->sig=aux;
        tope=aux;
    }
}
void desencolar(){
    if(vacia()){
        cout<<"Cola vacia"<<endl;
    }
    else{
       aux=cola->sig;
       delete cola;
       cola=aux;
    }
}

void Imprimir(){
    if(vacia()){
        cout<<"Cola vacia"<<endl;
    }
    else{
        aux=cola;
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
        aux=cola;
        while(cola!=tope){
            aux=aux->sig;
            delete cola;
            cola=aux;
        }
        delete cola;
        Inicializar();
    }
}


void Tope(){
    if(vacia()){
        cout<<"Cola vacia"<<endl;
    }
    else{
        cout<<"El valor del tope es: "<<cola->dato<<endl;
    }
}

int main(){

    bool continuar=true;
    do{
        cout<<"Que quieres hacer"<<endl;
        cout<<"[1] Encolar (X) //Ingresa un elemento en la posición tope"<<endl;
        cout<<"[2] Desencolar //Elimina un elemento (primero que entra primero que sale)"<<endl;
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
                encolar(val);
                break;
            case 2:
                desencolar();
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
