// MAIKEL DELGADO -- 1610287 -- UNIVERSIDAD SIMÓN BOLIVAR 
// LABORATORIO DE ALGORITMOS Y ESTRUCTURAS II 
// SEMANA 1: CODEFORCES
// EXCERSICE: A. CARD EXCHANGE

#include <iostream>
using namespace std;

    int main(){
        int t;                      //Cantidad de casos posibles que permitirá el programa hacer 
        cin >> t;
        while(t--){                 //Ciclo donde disminuye t ya que es el número de casos de prueba a realizar 
            int n;
            int k;
            //cout << "Mano de cartas de tamaño: " ;
            cin >> n;               //Cantidad de cartas totales en mano
            //cout << "Elegimos la cantidad de cartas del mismo valor vamos a tomar: " ;
            cin >> k;               //Cantidad de cartas que se van a intercambiar
            
            int array[n];           
            int cn[101] = {0};      //para contar la cantidad de cada número de carta
            int i;
            int minimo_de_cartas = 0; 

            /* Se inicia un bucle for que recorre el arreglo y pide por terminal los 
            elementos del arreglo los cuales los almacena en la variable array[i]
            y cuenta cuantas veces aparece la cantidad de cada elemento en el arreglo. */
            for(i=0; i<n; i++){    
                cin >> array[i];    
                cn[array[i]]++; //contamos    
                /* Verificamos si el número de ocurrencias de un elemento en el arreglo 
                es igual a un valor k dado. */
                if(cn[array[i]] == k){ 
                    minimo_de_cartas++;
                }
            }
            
            /* Condiciones */
           int salida;
            if(minimo_de_cartas){
			    salida = k-1;
	        }       
            else{
			    salida = n;
		    }
            cout << salida << endl;
        }
    }