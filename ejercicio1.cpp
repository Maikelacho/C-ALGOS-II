// MAIKEL DELGADO -- 1610287 -- UNIVERSIDAD SIMÓN BOLIVAR 
// LABORATORIO DE ALGORITMOS Y ESTRUCTURAS II 
// SEMANA 1: SPOJ

#include <iostream>     //Biblioteca importante
using namespace std;    

    int main(){
        int numero;     //Numero de entrada (input)
        while(true){    //Admite cualquier valor entero
        cin >> numero;  //Imprime por salida el mismo numero que entra (output)
            if(numero == 42){
                break;  //Si el numero es 42 el ciclo culmina
            }
            cout << numero << endl;
        }
        return 0;
    }
