// MAIKEL DELGADO -- 1610287 -- UNIVERSIDAD SIMÓN BOLIVAR 
// LABORATORIO DE ALGORITMOS Y ESTRUCTURAS II 
// SEMANA 2: CODEFORCES
// EXCERSICE: A. Sasha and the Beautiful Array

#include <iostream>
#include <vector> //Vector: vector <tipo_de_los_valores> nombre_de_la_variable(tamaño);
using namespace std;

int main(){
    int t; //Número de casos de prueba que puede realizar el programa
    cin >> t;
    while(t--){
        int n; //Longitud de la matriz(vector)
        cin >> n;  
        
        vector <int> matriz(n); //Creamos la matriz(vector) con n elementos
        for(int k=0; k<n; k++){ //Almacenamos los elementos dados por consola en la matriz(vector)
            cin >> matriz[k];
        }
        /* Implementamos el algoritmo de ordenamiento Bubble Sort explicado en clases.
        Nuestro objetivo para el problema es recibir el arreglo de forma desordenada y con este 
        algoritmo lo vamos a ordenar para realizar la operacion pedida. En el primer ciclo 
        iteramos para saber hasta donde vamos a recorrer para ordenar el vector. */
        for(int i=0; i<n; i++){
            for(int j=n-1; j>=i+1; j--){
                if (matriz[j] < matriz[j-1]){
                int intercambio = matriz[j];
                matriz[j] = matriz[j-1];
                matriz[j-1] = intercambio;
                }
            }     
        }
    /* Una vez ordenados de menor a mayor ahora realizamos la operacion  tal que (a2-a1)+(a3-a2)....
    Su equivalente es restar el primer elemento con el último elemento de nuestra matriz(vector). */
    int primer_elemento, ultimo_elemento, respuesta;
    primer_elemento = matriz[0];
    ultimo_elemento = matriz[n-1];
    respuesta = ultimo_elemento - primer_elemento;
    cout << respuesta << endl;
    }
}