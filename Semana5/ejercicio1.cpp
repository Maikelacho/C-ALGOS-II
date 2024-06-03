// MAIKEL DELGADO --- 1610287 --- UNIVERSIDAD SIMÓN BOLIVAR 
// LABORATORIO DE ALGORITMOS Y ESTRUCTURAS II 
// SEMANA 5: SPOJ
// EXCERSICE: RKS - RK Sorting

#include <iostream>
#include <vector>
#include <utility> 
using namespace std;

/**
  * Primeramente, creamos una función llamada "intercambiar" que toma como argumento una referencia a un vector de pares de pares de enteros
  * y un entero. Esta función es fundamental dada las especificaciones de nuestro problema a resolver. 
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
  * Para este ejercicio se nos dió la oportunidad de realizarlo nuevamente utilizando los algoritmos de ordenamiento vistos en clases:
  * HeapSort o QuickSort. Para esta ocasión elegiremos HeapSort ya que para adaparlo a nuestro ejercicio puede ser un poco más conveniente.
  * 
  * Utilizando la teoría vista en clases y los pseudocodigos explicados procederemos a realizarlo.
  * 
  * Primero, vamos a proceder a escribir nuestra función HEAPIFY, que tiene como objetivo mantener la propiedad de un heap máximo en un arreglo.
  * 
  * Segundo, creamos dos funciones sencillas denominadas IZQUIERDA Y DERECHA, con la finalidad de saber las posiciones del hijo.
  * 
  * Tecero y último cremamos nuestro función denominada HEAPSORT donde llamamos a HEAPIFY para ordenar nuestro arreglo. 
  **/

// Función para obtener el índice del hijo izquierdo.
int LEFT(int i) {
    return 2 * i + 1;
}

// Función para obtener el índice del hijo derecho.
int RIGHT(int i) {
    return 2 * i + 2;
}

/** Haciendo uso del pseudocodigo visto en clases.
  * Tenemos como entrada un vector de pares, el tamaño del vector (n) y la posición del nodo (i).
  * Haremos usos de las funciones LEFT Y RIGHT para obtener las posciones.
  **/
void HEAPIFY(vector<pair<pair<int, int>,int>> &array, int n, int i) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int largest;

    // Comparamos el nodo actual con sus hijos para determinar si alguno de ellos es más grande:
  
    /**
      * Si l es menor o igual a n y el segundo elemento del par en la posición l es mayor que el segundo elemento 
      * del par en la posición i, se actualiza largest con el índice l.
      **/
    if (l <= n && array[l].first.second > array[i].first.second) {
        largest = l;
    }
    else {
        largest = i;
    }

    /** 
      * Si r es menor o igual a n y el segundo elemento del par en la posición r es mayor que el segundo 
      * elemento del par en la posición largest, se actualiza largest con el índice r. 
      **/
    if (r <= n && array[r].first.second > array[largest].first.second) {
        largest = r;
    }

    // Si el nodo actual NO es el más grande, intercambiamos con el hijo más grande y llamamos recursivamente a HEAPIFY
    if (largest != i) {
        swap(array[i], array[largest]);
        HEAPIFY(array, n, largest);
    }
}

/**
  * Haciendo uso del pseudocodigo visto en clases.
  * Tenemos como entrada un vector de pares y el tamaño del vector (n).
  **/
void HEAPSORT(vector <pair<pair<int,int>,int>> &array, int n) {
    
    // Dado nuestro vector lo convertimos en un max heap
    for (int i = n/2; i >= 0; i--){
        HEAPIFY(array, n, i);
    }

    /**
      * Se intercambia el nodo en la posición 0 con el nodo en la posición i.
      * Llamamos a HEAPIFY con el vector array, el tamaño i-1 y el índice 0. Esto asegura 
      * que el subarbol con raíz en el nodo en la posición 0 mantenga la propiedad del max heap.
      * Teoricamente se hace el intercambio de la raiz del max heap con el nodo con la menor clave 
      * y seguido de ello lo descarta. 
      **/
    for (int i = n - 1; i >= 1; i--) {
        swap(array[0], array[i]);
        HEAPIFY(array, i-1, 0);
    }
}

// Usamos la misma implementación cuando usamos InsertionSort
int main(){
    int N; // Longitud del mensaje
    cin >> N;
    int C; // Número de descripción de la tarea
    cin >> C;

    /** 
      * Creamos un vector pares de pares (para usar bubble Sort).
      * Nuestro primer elemento del par será otro par cuyo primer elemento será un elemento dado y el segundo elemento será el número de
      * frecuencias de dicho elemento. El segundo elemento del par indica la posición del elemento.
      **/
    vector<pair<pair<int, int>, int>> frecuencia(N); //Pares de elementos del vector "matriz" junto con su índice origina
    int posicion = 0; 

    // Con este ciclo lo que haremos es llenar el vector de pares (frecuencia)
    for(int i=0; i<N; i++){
        int vector;
        cin >> vector;
        bool a = false;

        // Iteramos nuestro vector (frecuencia)
        for (auto& par : frecuencia) {

            // Verificamos la frecuencia en el que aparece el elemento del vector 'frecuencia'
            if (par.first.first == vector) {
                par.first.second++;
                a = true;
                break;
            }
        }

        // Se ejecuta si y solo si no se haya ejecutado el bloque if del ciclo anterior ya que !a
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
    auto inicio = next(frecuencia.begin(), posicion);
    auto final = next(frecuencia.begin(), N);
    frecuencia.erase(inicio, final); // Eliminamos los elementos en el rango de 'inicio' y 'final' de nuestro vectir 'frecuencia'.

    // Ordenamos nuestro vector 'frecuencia' según la frecuencia de los elementos 
    HEAPSORT(frecuencia, frecuencia.size());

    // Finalmente ordenamos 'frecuencia' según las especficaciones de lo pedido
    bool respuesta=true;
    while (respuesta){
        respuesta = intercambiar(frecuencia);
    }

    // Imprimimos por la salida estándar nuestra respuesta
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