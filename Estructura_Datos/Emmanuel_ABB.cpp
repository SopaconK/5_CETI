#include<iostream>
using namespace std;

struct Node{
    int dato;
    Node* left;
    Node* right;
    Node* parent;
} *abb, *a, *a2;

void Inicializar(){
    abb=NULL;
}

bool Vacio(){
    if(abb==NULL) return true;
    return false;
}
void Insertar(int x){
    if(Vacio()){
        abb=new Node();
        abb->dato=x;
        abb->left=NULL;
        abb->right=NULL;
        abb->parent=NULL;
        return;
    }
    else{
        a=abb;
        while(true){
            if(x<a->dato){
                if(a->left==NULL){
                    a->left=new Node();
                    a->left->parent=a;
                    a=a->left;
                    a->dato=x;
                    a->left=NULL;
                    a->right=NULL;
                    return;
                }
                else{
                    a=a->left;
                }
            }
            else{
                 if(a->right==NULL){
                    a->right=new Node();
                    a->right->parent=a;
                    a=a->right;
                    a->dato=x;
                    a->left=NULL;
                    a->right=NULL;
                    return;
                }
                else{
                    a=a->right;
                }
            }
        }
    }


}

bool Busca(int x, Node* n){
    if(!n){
        return false;
    }
    if(n->dato==x){
        return true;
    }
    if(x<n->dato){
        return Busca(x, n->left);
    }
    else return Busca(x, n->right);
}

void Eliminar(int x){
    if(Vacio()){
        cout<<"Error arbol vacio"<<endl;
        return;
    }
    if(!Busca(x, abb)){
        cout<<"Error, no se encuentra el valor"<<endl;
        return;
    }
    if(abb->dato==x){
        if(!abb->left){
            if(!abb->right){
                delete abb;
                Inicializar();
                return;
            }
            else{
                a=abb->right;
                a->parent=NULL;
                delete abb;
                abb=a;
                return;
            }
        }
        else if(!abb->right){
            a=abb->left;
            a->parent=NULL;
            delete abb;
            abb=a;
            return;
        }
        else{
            a=abb->left;
            if(a->right==NULL){

                a->right=abb->right; //aqui lo que haces es poner el nodo mas grande de la izq (en este caso el hijo izq) como raiz por eso mueves todo lo de la derecha a la derecha de la izq 
                a->right->parent=a;
                a->parent=NULL;
                delete abb;
                abb=a;
                return;
            }
            while(a->right!=NULL){
                a=a->right;
            }
            abb->dato=a->dato;
            a->parent->right=a->left;
            if(a->left){
                a->left->parent=a->parent;
            }
            delete a;
            return;
        }


    }
    a=abb;
    while(a->dato!=x){
        if(x<a->dato){
            a=a->left;
        }
        else a=a->right;
    }
    if(!a->left){
        if(!a->right){
            if(x<a->parent->dato){
                a->parent->left=NULL;
            }
            else{
                a->parent->right=NULL;
            }
            delete a;
            return;
        }
        else{
            if(x<a->parent->dato){
                a->parent->left=a->right;
                a->right->parent=a->parent;
            }
            else{
                a->parent->right=a->right;
                a->right->parent=a->parent;
            }
            delete a;
            return;
        }
    }
    else{
        if(!a->right){
            if(x<a->parent->dato){
                a->parent->left=a->left;
                a->left->parent=a->parent;
            }
            else{
                a->parent->right=a->left;
                a->left->parent=a->parent;
            }
            delete a;
            return;
        }
        else{
            //Este es cuando tiene dos hijos 
            a2=a->left;
            if(a2->right==NULL){
                if(x<a->parent->dato){
                    a->parent->left=a2;
                }
                else{
                    a->parent->right=a2;
                }
                a2->parent=a->parent;
                a2->right=a->right;
                a->right->parent=a2;
                delete a;
                return;
            }
            while(a2->right!=NULL){
                a2=a2->right;
            }

            a->dato=a2->dato;
            a2->parent->right=a2->left;
          
            if(a2->left){
                a2->left->parent=a2->parent;
            }
            delete a2;
        }
    }

}


void InOrder(Node *n){
    if(n==NULL) return;
    InOrder(n->left); //si es NULL no va a hacer nada
    cout<<n->dato<<" ";
    InOrder(n->right);
}


void PreOrder(Node *n){
    if(n==NULL) return;
    cout<<n->dato<<" ";
    PreOrder(n->left);
    PreOrder(n->right);
}

void PostOrder(Node *n){
    if(n==NULL) return;
    PostOrder(n->left);
    PostOrder(n->right);
    cout<<n->dato<<" ";
}

void Raiz(){
    if(Vacio()){
        cout<<"El arbol esta vacio no tiene raiz"<<endl;
    }
    else{
        cout<<abb->dato<<endl;
    }
}

void Hojas(Node *n){
    if(n==NULL) return;
    if(n->left==NULL && n->right==NULL){
        cout<<n->dato<<" ";
    }
    else{
        Hojas(n->left);
        Hojas(n->right);
    }
}

Node* Encontrar(int x, Node *n){
    if(!n){
        return NULL;
    }
    if(n->dato==x){
        return n;
    }
    if(x<n->dato){
        return Encontrar(x, n->left);
    }
    else return Encontrar(x, n->right);
}

int Nivel(Node *n){
    if(!n) return -1;
    return 1+max(Nivel(n->left), Nivel(n->right));
}

int Altura(Node *n){
    if(!n) return 0;
    return 1+max(Altura(n->left), Altura(n->right));
}

int Tamano(Node *n){
    if(!n) return 0;
    return 1+Tamano(n->left)+Tamano(n->right);
}

void Hijos(Node *n){
    if(!n) return;
    if(n->parent!=NULL){
        cout<<n->dato<<" ";
    }
    Hijos(n->left);
    Hijos(n->right);
}


void Padres(Node *n){
    if(!n) return;
    if(n->left!=NULL || n->right!=NULL){
        cout<<n->dato<<" ";
        Padres(n->left);
        Padres(n->right);
    }
}


int main(){
    Inicializar();
    bool continuar=true;
    while(continuar){
        cout<<"Que quieres hacer?"<<endl;
        cout<<"1.Ingresa un Nodo \n 2.Elimina un Nodo \n 3.InOrden \n 4.PostOrden \n 5.PreOrden \n 6.Raiz \n 7.Hojas \n 8.Nivel \n 9.Altura \n 10.Tamano \n 11.Orden \n 12.Hijos \n 13.Padres \n 14.Salir"<<endl;
        int tipo;
        cin>>tipo;
        if(tipo==1){
            int x;
            cout<<"Dame el valor"<<endl;
            cin>>x;
            Insertar(x);
        }
        else if(tipo==2){
            int x;
            cout<<"Dame el valor"<<endl;
            cin>>x;
            Eliminar(x);
        }
        else if(tipo==3){
            InOrder(abb);
            cout<<endl;
        }
        else if(tipo==4){
            PostOrder(abb);
            cout<<endl;
        }
        else if(tipo==5){
            PreOrder(abb);
            cout<<endl;
        }
        else if(tipo==6){
            Raiz();
        }
        else if(tipo==7){
            Hojas(abb);
        }
        else if(tipo==8){
            bool b;
            cout<<"Quieres del arbol (1) o de un nodo (0)";
            cin>>b;
            if(b){
                if(Vacio()){
                    cout<<"Esta vacio no hay nivel"<<endl;
                }
                else{
                    cout<<Nivel(abb)<<endl;
                }
            }
            else{
                int x;
                cout<<"Dame el valor del nodo"<<endl;
                cin>>x;
                if(Busca(x, abb)){
                    cout<<Nivel(Encontrar(x,abb))<<endl;
                }
                else{
                    cout<<"No se encuentra"<<endl;
                }
            }
        }
        else if(tipo==9){
              bool b;
            cout<<"Quieres del arbol (1) o de un nodo (0)";
            cin>>b;
            if(b){
                if(Vacio()){
                    cout<<"Esta vacio altura 0"<<endl;
                }
                else{
                    cout<<Altura(abb)<<endl;
                }
            }
            else{
                int x;
                cout<<"Dame el valor del nodo"<<endl;
                cin>>x;
                if(Busca(x, abb)){
                    cout<<Altura(Encontrar(x,abb))<<endl;
                }
                else{
                    cout<<"No se encuentra"<<endl;
                }
            }
        }
        else if(tipo==10){
            cout<<Tamano(abb)<<endl;
        }
        else if(tipo==11){
            cout<<"El orden es 2"<<endl;
        }
        else if(tipo==12){
            Hijos(abb);
            cout<<endl;
        }
        else if(tipo==13){
            Padres(abb);
            cout<<endl;
        }
        else if(tipo==14){
            continuar=false;
        }
    }
}




