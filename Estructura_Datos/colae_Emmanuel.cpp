// Cola Estatica
// Emmanuel 22300891 5I

#include<iostream>
using namespace std;


bool llena(int tope){
    return (tope==19);
}
bool vacia(int tope){
    return (tope==-1);
}

void encolar(int *tope, int cola[], int valor){
    if(llena(*tope)){
        cout<<"Cola llena"<<endl;
    }
    else{
        (*tope)++;
        cola[*tope]=valor;
    }
}
void desencolar(int *tope, int cola[]){
    if(vacia(*tope)){
        cout<<"Cola vacia"<<endl;
    }
    else{
        for(int i=0; i<*tope; i++){
            cola[i]=cola[i+1];
        }
        (*tope)--;
    }
}
void Imprimir(int *tope, int cola[]){
    if(vacia(*tope)){
        cout<<"Cola vacia"<<endl;
    }
    else{
        cout<<"Cola: ";
        int i=0;
        while(i<=(*tope)){
            cout<<cola[i]<<" ";
            i++;
        }
        cout<<endl<<"Fin"<<endl;
    }
}
void Limpiar(int *tope, int cola[]){
    while(!vacia(*tope)){
        cola[*tope]=-1;
        (*tope)--;
    }
    cout<<"Cola vacia"<<endl;
}

void Tope(int *tope, int cola[]){
    if(vacia(*tope)){
        cout<<"Cola vacia"<<endl;
    }
    else{
        cout<<"El valor del tope es: "<<cola[*tope]<<endl;
    }
}

int main(){
    int tope=-1;
    int cola[20];
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
                encolar(&tope, cola, val);
                break;
            case 2:
                desencolar(&tope, cola);
                break;
            case 3:
                Imprimir(&tope, cola);
                break;
            case 4:
                Limpiar(&tope, cola);
                break;
            case 5: 
                Tope(&tope, cola);
                break;
            case 6:
                continuar=false;
                break;
        }
      
    }while(continuar);
}
