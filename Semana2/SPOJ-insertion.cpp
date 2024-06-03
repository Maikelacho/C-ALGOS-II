// MAIKEL DELGADO --- 1610287 --- UNIVERSIDAD SIMÓN BOLIVAR 
// LABORATORIO DE ALGORITMOS Y ESTRUCTURAS II 
// SEMANA 2: SPOJ
// EXCERSICE: RKS - RK Sorting

#include <iostream>
#include <vector>
#include <utility> //Para usar pares ordenados
using namespace std;

/**
  * Primeramente, creamos una función llamada "intercambiar" que toma como argumento una referencia a un vector de pares de pares de enteros
  *  y un entero. Esta función es fundamental dada las especificaciones de nuestro problema a resolver. 
  * Su propósito es intercambiar elementos dentro del vector si se cumplen ciertas condiciones y devuelve un valor booleano indicando 
  * si se realizó algún intercambio.
  **/
bool intercambiar(vector <pair<pair<int, int>, int >> &array){
    bool ans = false;
    int n = array.size();

    // Iteramos sobre el vector desde n-2 hasta first (primera posición)
    for (int i = n-2; i >= 0; i--){
        // Dos condiciones a cumplir  
        if (array[i].second < array[i + 1].second && array[i].first.second == array[i + 1].first.second){
            swap(array[i], array[i + 1]);
            ans = true;           
        }
    }
    return ans;
}

/** 
  * Segundo, dado que en el ejercico anterior usamos bubbleSort en este vamos a utilizar el otro algoritmo de ordenamiento visto.
  * El algoritmo de inserción ordena el arreglo de forma ascendente donde compamos cada elemento con los elementos anteriores y 
  * moviendo los elementos mayores a su posición correcta. 
  * 
  * Es importante este algoritmo ya que necesitamos ordenar el arreglo dado por consola para asi contar el numero de ocurrencias de 
  * cada elemento (esto se explicara más adelante). Es decir, queremos ordenar el array de forma ascendente según el segundo elemento 
  * del par que esta como primer elemento de los pares del vector.
  **/
void insertionSort(vector<pair<pair<int,int>, int>> &array){
    int n = array.size();

    /**
      *  Iteramos sobre el vector desde el segundo elemento del array ya que vamos
      * a comparar desde el segundo elemento con el anterior, es decir, con el primero. 
      **/
    for(int i = 1; i < n; i++){
        int key = i;
       
        // Vamos almacenar temporalmente el elemento actual array[key] en la variable temp
        pair<pair<int,int>, int> temp = array[key];
       /**
         * Mientras que el elemento sea mayor que 0 y el segundo elemento del primer par del elemento 
         * en array[key-1] sea mayor que el segundo elemento del primer par en temp se va a 
         * intercambiar el elemento en array[key-1] a array[key]. 
         **/
        while(key > 0 && array[key-1].first.second > temp.first.second){
            array[key] = array[key-1];
            key--;
        }
        array[key] = temp;
    }
}

int main(){
    int N; // Longitud del mensaje
    cin >> N;
    int C; // Número de descripción de la tarea
    cin >> C;

    /** 
      * Creamos un vector pares de pares (para usar insertionSort).
      * Nuestro primer elemento del par será otro par cuyo primer elemento será un elemento dado y el segundo elemento será el número de
      * frecuencias de dicho elemento. El segundo elemento del par indica la posición del elemento.
      **/
    vector<pair<pair<int, int>, int>> frecuencia(N); //Pares de elementos del vector "matriz" junto con su índice origina.
    int posicion = 0; 

    // Con este ciclo lo que haremos es llenar el vector de pares (frecuencia).
    for(int i=0; i<N; i++){
        int vector;
        cin >> vector;
        bool a = false;

        // Iteramos nuestro vector (frecuencia).
        for (auto& par : frecuencia) {

            // Verificamos la frecuencia en el que aparece el elemento del vector 'frecuencia'.
            if (par.first.first == vector) {
                par.first.second++;
                a = true;
                break;
            }
        }

        // Se ejecuta si y solo si no se haya ejecutado el bloque if del ciclo anterior ya que !a.
        if (!a) {
            posicion++;

            // Asignamos el elemento(de tamaño N) en la iteracion.
            frecuencia[posicion-1].first.first = vector; 
            
            // Asignamos a la frecuencia 1.
            frecuencia[posicion-1].first.second = 1; 
            
            // Asignamos el valor de i al vector. 
            frecuencia[posicion-1].second = i; 
        }
    }

    /**
      * Eliminamos el rango de los elementos innecesarios del vector frecuencia comenzando desde la posición indicada 'posicion'
      * y terminamos en la posición indicada por N.
      **/
    frecuencia.erase(frecuencia.begin() + posicion, frecuencia.begin() + N);

    // Ordenamos nuestro vector 'frecuencia' según la frecuencia de los elementos. 
    insertionSort(frecuencia);

    // Finalmente ordenamos 'frecuencia' según las especficaciones de lo pedido.
    bool respuesta=true;
    while (respuesta){
        respuesta = intercambiar(frecuencia);
    }

    // Imprimimos por la salida estándar nuestra respuesta.
    int i = frecuencia.size() - 1;
        while (i >= 0) {
            int j = frecuencia[i].first.second;
            while (j > 0) {
                cout << frecuencia[i].first.first << endl;
                j--;
            }
            i--;
        }
    cout << endl;          // :)
    
    return 0; //siempre
}