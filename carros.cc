#include <iostream>
#include <malloc.h>
using namespace std;

// g++ carros.cc -o carros.exe     

// ve este es el del taller de EDD esta very good por si algo compadre XD.

struct parqueadero{

    float costo_carro = 5000;
    int posi_carro;
  
    float costo_moto ;
    int posi_moto = 2500;

    parqueadero *sig;

};

parqueadero *top,*aux,*topaux;

//CARROS---------->

void registrar_carro(){

    aux = (parqueadero *) malloc (sizeof(parqueadero ));

    if(top == NULL){

    top = aux;

    
    top->costo_carro = 5000;
    top->posi_carro = 1;
    top ->sig = NULL;

    }else{

        aux->costo_carro = 5000;
        aux->posi_carro = top->posi_carro+1;

        aux->sig = top;
        top = aux;

    }
}

void mostrar_carro(){
 
    cout<<"PARQUEADERO CARROS"<<endl<<endl;

    for(aux = top; aux != NULL; aux = aux->sig){

        
        cout<<" numero de carro "<<aux->posi_carro ;
        cout<<" su valor es -----> "<<aux->costo_carro<<endl;
        cout<<"------------------------------------------------------"<<endl<<endl;
    } 
}

void eliminar_carro() {

    mostrar_carro();

    int carro;
    int costos_extra = 0; 

    cout << "Ingrese el carro que va a eliminar: "<<endl;
    cin >> carro;

    if (top != NULL && top->posi_carro == carro) {
    
        aux = top;
        top = top->sig;
        free(aux);

        cout << "Carro sacado..." << endl << endl;

    } else {

        topaux = NULL;
        aux = top;
    
        while (aux != NULL && aux->posi_carro != carro) {
           
            topaux = aux;
            aux = aux->sig;
            costos_extra += 1000; 
        }
        if (aux != NULL) {


            topaux->sig = aux->sig;
            float costo_final = aux->costo_carro + costos_extra; 

            cout << "Carro eliminado. Carro " << carro << " valor " << costo_final << endl << endl;
         
            free(aux);
               
        }else {

            cout << "¡Ups, lo sentimos pero el carro no se encuentra!" << endl << endl;
        }
    }
}

//MOTOS---------->

void registrar_moto(){

    aux = (parqueadero *) malloc (sizeof(parqueadero ));

    if(top == NULL){

    top = aux;

    top->costo_moto = 2500;
    top->posi_moto = 1;
    top ->sig = NULL;

    }else{

        aux->costo_moto = 2500;
        aux->posi_moto = top->posi_moto+1;

        aux->sig = top;
        top = aux;
    }
}

void mostrar_moto(){

    cout<<"PARQUEADERO MOTOS"<<endl<<endl;

    for(aux = top; aux != NULL; aux = aux->sig){

    cout<<" numero de moto "<<aux->posi_moto;
    cout<<" su valor es -----> "<<aux->costo_moto<<endl;
    cout<<"------------------------------------------------------"<<endl<<endl;
    }
}

void eliminar_moto(){

    mostrar_moto();

    int moto;
    int costos_extra = 0;

    cout << "Ingrese el carro que va a eliminar: "<<endl;
    cin >> moto;

    if (top != NULL && top->posi_moto == moto) {
      
        aux = top;
        top = top->sig;
        free(aux);

        cout << "moto sacada..." << endl << endl;

    } else {

        topaux = NULL;
        aux = top;
    
        while (aux != NULL && aux->posi_moto != moto) {
            
            topaux = aux;
            aux = aux->sig;
            costos_extra += 500; 
        }
      
        if (aux != NULL) {

            topaux->sig = aux->sig;
            float costo_final = aux->costo_moto + costos_extra; 

            cout << "moto eliminada. moto " << moto << " valor " << costo_final << endl << endl;
            
            free(aux);

        } else {

            cout << "¡ups, lo sentimos pero la moto no esta!" << endl << endl;
        }
    }
}

int main() {

    int op = 0;

    do {
        cout << "PARQUEADERO :" << endl;
        
        cout<<"------------------------------------------------------"<<endl;
        cout << "1. estacionar carro " << endl;
        cout << "2. sacar carro "<< endl;
        cout << "3. estacionar moto  "<< endl;
        cout << "4. sacar moto "<< endl;
        cout << "5. Salir" << endl;
        cin >> op;
        cout<<"------------------------------------------------------"<<endl<<endl;
        switch (op) {

        case 1:
        registrar_carro();

        cout<<"carro agregado "<<endl<<endl;
        cout<<"------------------------------------------------------"<<endl<<endl;
        break;

        case 2:
        eliminar_carro();
        break;
           
        case 3:
        registrar_moto();

        cout<<"moto agregada "<<endl<<endl;
        cout<<"------------------------------------------------------"<<endl<<endl;
        break;
            
        case 4:
        eliminar_moto();
        break;


        default:
        cout << "Opcion no valida vro" << endl;
        break;

        }
            
    } while (op != 6);

    return 0;
} 

