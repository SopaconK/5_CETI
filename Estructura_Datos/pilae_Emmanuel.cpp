// Pila Estatica
// Emmanuel 22300891 5I

#include<iostream>
using namespace std;


bool llena(int tope){
    return (tope==19);
}
bool vacia(int tope){
    return (tope==-1);
}

void push(int *tope, int pila[], int valor){
    if(llena(*tope)){
        cout<<"Pila llena"<<endl;
    }
    else{
        (*tope)++;
        pila[*tope]=valor;
    }
}
void pop(int *tope, int pila[]){
    if(vacia(*tope)){
        cout<<"Pila vacia"<<endl;
    }
    else{
        pila[*tope]=-1;
        (*tope)--;
    }
}
void Imprimir(int *tope, int pila[]){
    if(vacia(*tope)){
        cout<<"Pila vacia"<<endl;
    }
    else{
        cout<<"Pila: ";
        int i=0;
        while(i<=(*tope)){
            cout<<pila[i]<<" ";
            i++;
        }
        cout<<endl<<"Fin"<<endl;
    }
}
void Limpiar(int *tope, int pila[]){
    while(!vacia(*tope)){
        pila[*tope]=-1;
        (*tope)--;
    }
    cout<<"Pila vacia"<<endl;
}

void Tope(int *tope, int pila[]){
    if(vacia(*tope)){
        cout<<"Pila vacia"<<endl;
    }
    else{
        cout<<"El valor del tope es: "<<pila[*tope]<<endl;
    }
}

int main(){
    int tope=-1;
    int pila[20];
    bool continuar=true;
    do{
        cout<<"Que quieres hacer"<<endl;
        cout<<"[1] Push (Ingresa un elemento)"<<endl; 
        cout<<"[2] Pop (Elimina un elemento)"<<endl;
        cout<<"[3] Imprimir (Imprime la pila)"<<endl;
        cout<<"[4] Limpia (Limpia la pila)"<<endl;
        cout<<"[5] Tope (Imprime el valor del tope)"<<endl;
        cout<<"[6] Salir (Sale del sistema)"<<endl;
        
        int tipo;
        cin>>tipo;
        int val;
        switch(tipo){
            case 1:
                cout<<"Que valor?"<<endl;
                cin>>val;
                push(&tope, pila, val);
                break;
            case 2:
                pop(&tope, pila);
                break;
            case 3:
                Imprimir(&tope, pila);
                break;
            case 4:
                Limpiar(&tope, pila);
                break;
            case 5: 
                Tope(&tope, pila);
                break;
            case 6:
                continuar=false;
                break;
        }
      
    }while(continuar);
}
