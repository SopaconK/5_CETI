//Emmanuel Buenrostro Briseño 22300891
//Soldados

#include<iostream>
#include <cstdlib>
using namespace std;


struct Node{
    string nombre;
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

void Agrega(string x){
    a=new Node;
    a->nombre=x;
    if(vacia()){
        L=a;
        L->sig=L;
        L->ant=L;
    }
    else{
        if(a->nombre < L->nombre){
            a->sig=L;
            L->ant->sig=a;
            a->ant=L->ant;
            L->ant=a;
            L=a;
        }
        else{
            a2=L;
            while(a2->sig!=L && a2->sig->nombre <x){
                a2=a2->sig;
            }
            a->sig=a2->sig;
            a->ant=a2;
            a2->sig->ant=a;
            a2->sig=a;
            
        }
    }
}

bool busca(string x){
    a=L;
    if(vacia()) return false;
    if(a->nombre==x) return true;
    a=a->sig;
    while(a!=L && a->nombre!=x){
        a=a->sig;
    }
    if(a->nombre==x){
        return true;
    }
    return false;
}

void Elimina(string x){
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
        if(L->nombre==x){
           
            a=L;
            L->ant->sig=L->sig;
            L->sig->ant=L->ant;
            L=L->sig;
            delete a;
    
        }
        else{
            a=L;
            do{
                if(a->nombre==x) break;
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
            cout<<a->nombre<<" ";
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
    Inicializar();
    bool continuar=true;
    int n;
    bool choose1=false;
    bool choose2=false;
    int sz=0;
    string nombres[21]={"Franco", "Emiliano", "Emmanuel", 
                            "Fernando", "Fabian", "Oscar", 
                            "Nestor", "Itzel", "Rangel", 
                            "Ulises", "Elias", "Merin", 
                            "Hugo", "Yotuel", "Olvera", 
                            "Ortega", "Pelayo", "Mario", 
                            "Omar","Max","Emilio"};
    while(continuar){
        cout<<"Que quieres hacer? \n 1. Agregar # de soldados \n 2.Agregar Soldados \n 3.Mostrar Soldados \n 4. Sacar soldado \n 5. Reiniciar juego \n 6. Salir"<<endl;
        int type;
        cin>>type;
        if(type==1){
            if(choose2){
                cout<<"Ya existe una lista, quieres borrar la actual? (1 Si 0 No)"<<endl;
                bool nueva;
                cin>>nueva;
                if(nueva){
                    Limpiar();
                    cout<<"Dame n entre 2 y 21"<<endl;
                    cin>>n;
                    if(n<2 || n>21){
                        cout<<"Valores incorrectos"<<endl;
                        continue;
                    }
                }
            }
            else{
                 cout<<"Dame n"<<endl;
                    cin>>n;
                     if(n<2 || n>21){
                        cout<<"Valores incorrectos"<<endl;
                        continue;
                    }

            }
            choose1=true;
        }
        else if(type==2){
            if(!choose1){
                cout<<"No haz hecho la operacion 1"<<endl;
            }
            else{
                bool visited[21];
                for(int i=0; i<=20; ++i) visited[i]=false;
                int cont=0;
                while(sz<n){
                    int x=rand()%21+1;
                    while(x--){
                        cont++;
                        while(visited[cont%21]) cont++;
                    }
                    visited[cont%21]=true;
                    Agrega(nombres[cont%21]);
                    sz++;
                }
                choose2=true;
            }
        }
        else if(type==3){
            if(!choose1){
                cout<<"No se a hecho la operacion 1"<<endl;
            }
            else if(!choose2){
                cout<<"No se a hecho la operacion 2"<<endl;
            }
            else{
                Imprimir();
            }
        }
        else if(type==4){
            if(!choose1){
                cout<<"No se a hecho la operacion 1"<<endl;
            }
            else if(!choose2){
                cout<<"No se a hecho la operacion 2"<<endl;
            }
            else{
                if(L->sig==L){
                    cout<<"No puedes sacar mas soldados porque "<<L->nombre<<" fue por ayuda"<<endl;
                }
                else{
                    int x=rand()%21;
                    a=L;
                    while(x--){
                        a=a->sig;
                    }
                    cout<<"Se saco a "<<a->nombre<<endl;
                    Elimina(a->nombre);
                    sz--;
                    if(L->sig==L){
                        cout<<L->nombre<<" fue por ayuda"<<endl;
                    }
                }
            }
        }
        else if(type==5){
            Limpiar();
            sz=0;
            choose2=false;
        }
        else if(type==6){
            continuar=false;
        }
    }
}

