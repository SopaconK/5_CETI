// Emmanuel Buenrostro Briseño 22300891
// Grafos 

#include<iostream>
using namespace std;
#include<vector>


struct Nodo{
    string nombre;
    vector<Nodo*> ady;
    vector<int> peso;
} *aux;

vector<Nodo*> grafo;

int Busca(string x){
    for(int i=0; i<grafo.size(); i++){
        if(grafo[i]->nombre==x) return i;
    }
    return -1;
}

void AgregaNodo(string x){
    for(Nodo* n: grafo){
        if(n->nombre==x){
            cout<<"Ese nodo ya existe"<<endl;
            return;
        }
    }
    aux=new Nodo();
    aux->nombre=x;
    grafo.push_back(aux);
}

bool Unidos(int a, int b){
    for(Nodo* aux: grafo[a]->ady){
        if(aux->nombre==grafo[b]->nombre){
            return true;
        }
    }
    return false;
}

void AgregaArista(string x, string y, int d){
    int a=Busca(x);
    int b=Busca(y);
    if(a==-1 && b==-1){
        cout<<"No existen esos nodos"<<endl;
        return;
    }
    if(a==-1){
        cout<<"No existe el primer nodo"<<endl;
        return;
    }

    if(b==-1){
        cout<<"No existe el segundo nodo"<<endl;
        return;
    }
    if(Unidos(a,b)){
        cout<<"Ya estan unidos"<<endl;
        return;
    }
    grafo[a]->ady.push_back(grafo[b]);
    grafo[a]->peso.push_back(d);
    grafo[b]->ady.push_back(grafo[a]);
    grafo[b]->peso.push_back(d);
}



void EliminaNodo(string x){
    int a=Busca(x);
    if(a==-1){
        cout<<"No se encuentra ese nodo"<<endl;
        return;
    }

    for(Nodo* adj: grafo[a]->ady){
        for(int i=0; i<adj->ady.size(); i++){
            if(adj->ady[i]->nombre==x){
                for(int j=i; j<adj->ady.size()-1; j++){
                    adj->ady[j]=adj->ady[j+1];
                    adj->peso[j]=adj->peso[j+1];
                }
                adj->ady.pop_back();
                adj->peso.pop_back();
                break;
            }
        }
    }
    
    aux=grafo[a];
    for(int i=a; i<grafo.size()-1; i++){
        grafo[i]=grafo[i+1];
    }
    grafo.pop_back();
    delete aux;
}

void EliminaArista(string x, string y){
    int a=Busca(x);
        int b=Busca(y);
    if(a==-1 && b==-1){
        cout<<"No existen esos nodos"<<endl;
        return;
    }
    if(a==-1){
        cout<<"No existe el primer nodo"<<endl;
        return;
    }

    if(b==-1){
        cout<<"No existe el segundo nodo"<<endl;
        return;
    }
    int c=-1;
    for(int i=0; i<grafo[a]->ady.size(); i++){
        if(grafo[a]->ady[i]->nombre==y){
            c=i;
            break;
        }
    }
    if(c==-1){
        cout<<"No estan unidos"<<endl;
        return;
    }
    for(int i=c; i<grafo[a]->ady.size()-1; i++){
        grafo[a]->ady[i]=grafo[a]->ady[i+1];
        grafo[a]->peso[i]=grafo[a]->peso[i+1];       
    }
    grafo[a]->ady.pop_back();
    grafo[a]->peso.pop_back();

    c=-1;
    for(int i=0; i<grafo[b]->ady.size(); i++){
        if(grafo[b]->ady[i]->nombre==x){
            c=i;
            break;
        }
    }
    if(c==-1){
        cout<<"No estan unidos"<<endl;
        return;
    }
    for(int i=c; i<grafo[b]->ady.size()-1; i++){
        grafo[b]->ady[i]=grafo[b]->ady[i+1];
        grafo[b]->peso[i]=grafo[b]->peso[i+1];       
    }
    grafo[b]->ady.pop_back();
    grafo[b]->peso.pop_back();

}

vector<bool> visited;
vector<string> ans;
int dis=0;

bool dfs(Nodo* a, Nodo* y){
    ans.push_back(a->nombre);
    visited[Busca(a->nombre)]=true;
    if(a==y) return true;
    for(int i=0; i<a->ady.size(); i++){
        if(visited[Busca(a->ady[i]->nombre)]) continue;
        bool b=dfs(a->ady[i], y);
        if(b){
            dis+=a->peso[i];
            return true;
        }
    }
    ans.pop_back();
    return false;
}

void Ruta(string x, string y){
    dis=0;
    ans.clear();
    visited.clear();
    visited.resize(grafo.size(), 0);
      int a=Busca(x);
        int b=Busca(y);
    if(a==-1 && b==-1){
        cout<<"No existen esos nodos"<<endl;
        return;
    }
    if(a==-1){
        cout<<"No existe el primer nodo"<<endl;
        return;
    }

    if(b==-1){
        cout<<"No existe el segundo nodo"<<endl;
        return;
    }
    if(dfs(grafo[a], grafo[b])){
        cout<<"Camino: "<<ans[0];
        for(int i=1; i<ans.size(); i++){
            cout<<"-> "<<ans[i];
        }
        cout<<endl<<"Distancia: "<<dis<<endl;
    }
    else{
        cout<<"No existe"<<endl;
    }
}


void Limpiar(){
    for(Nodo* x: grafo){
        delete x;
    }
    grafo.clear();
}

int main(){
    bool continuar=true;
    while(continuar){
        cout<<"Que quieres hacer?"<<endl;
        cout<<"1. Agregar Nodo \n 2.Agregar una Arista \n 3. Eliminar Nodo \n 4. Eliminar Arista \n 5.Imprimir Ruta \n 6.Salir"<<endl;
        int type;
        cin>>type;
        if(type==1){
            cout<<"Dame el nombre del nodo:"<<endl;
            string x;
            cin>>x;
            AgregaNodo(x);
        }
        else if(type==2){
            cout<<"Dame los dos nodos que quieres unir"<<endl;
            string s1,s2;
            cin>>s1>>s2;
            cout<<"Dame la longitud de la arista"<<endl;
            int d;
            cin>>d;
            AgregaArista(s1,s2,d);
        }
        else if(type==3){
            cout<<"Dame el nombre del nodo que quieres eliminar"<<endl;
            string s;
            cin>>s;
            EliminaNodo(s);
        }
        else if(type==4){
            cout<<"Dame el nombre de los extremos de la arista que quieres eliminar"<<endl;
            string s1,s2;
            cin>>s1>>s2;
            EliminaArista(s1,s2);
        }
        else if(type==5){
            cout<<"Dame el nombre de los dos nodos de los cuales quieres saber la ruta entre ellos"<<endl;
            string s1,s2;
            cin>>s1>>s2;
            Ruta(s1,s2);
        }
        else if(type==6){
            Limpiar();
            continuar=false;
        }
    }
}