//  * MAIKEL DELGADO ---- 1610287 ---- UNIVERSIDAD SIMÓN BOLIVAR   
//  * LABORATORIO DE ALGORITMOS Y ESTRUCTURAS II 
//  * SEMANA 3: SPOJ
//  * EXCERSICE: AGGRCOW - Aggressive cows 

#include <iostream>
#include <vector>
using namespace std;

/** 
  * Primeramente, creamos una funcion denominada "merge" donde dividiremos nuestro arreglo en dos subarreglos (dividir).
  * Dado nuestro arreglo de entrada (matriz) queremos ordenarlo y lo  que se hará es dividir el arreglo e implementar
  * nuestro algoritmo de ordenamiento ya mencionado. Dividimos y fusionamos al compararlos. 
  **/
void merge(vector<int>& arreglo, int U, int m, int V) {
    // "U" primer elemento del arreglo, "m" mitad del arreglo, "V" elemento final del arreglo 
    int n1 = m - U + 1;
    int n2 = V - m;

    vector<int> L(n1); //subarreglo L de tamaño n1
    vector<int> R(n2); //subarreglo R de tamaño n2

    // Copiamos el arreglo original a los temporales: L y R 
    for (int i = 0; i < n1; i++)
        L[i] = arreglo[U + i];
    for (int j = 0; j < n2; j++)
        R[j] = arreglo[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = U;
    // Comparamos las posiciones de i y j de L y R respectivamente 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arreglo[k] = L[i];
            i++;
        } else {
            arreglo[k] = R[j];
            j++;
        }
        k++;
    }

    // Estos dos últimos bucles son importantes ya que si aún quedan elementos tanto en L y en R copia los elementos al "arreglo" 
    while (i < n1) {
        arreglo[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arreglo[k] = R[j];
        j++;
        k++;
    }
}

/** 
  * Con esta función aplicaremos las llamadas recursivas para dividir el arreglo en subarreglos más pequeños,
  * con ello ordenamos los subarreglos más pequeños y finalmente combinamos dichos subarreglos ya ordenados en un 
  * arreglo final utilizando la función merge.
  **/
void mergeSort(vector<int>& arreglo, int U, int V) {
    if (U < V) {
        int m = U + (V - U) / 2; //Calculamos el "m" punto medio del arreglo
        mergeSort(arreglo, U, m);
        mergeSort(arreglo, m + 1, V);
        // Combinamos los dos subarreglos ordenados en uno solo que va a cubrir el rango de U hasta V 
        merge(arreglo, U, m, V); //Finalmente conquistamos :) 
    }
}

/**  
  * Creamos una funcion llamada "chequeo" que se va encargar de verificar o chequear si se pueden colocar 
  * todas las vacas (C) con una distancia mínima dada en los establos (N).
  **/
bool chequeo(const vector<int>& arreglo, int N, int C, int distancia){
    int posicionEstablo = arreglo[0];
    int contador = 1;
    for(int i=1; i<N; i++){
        if(arreglo[i]-posicionEstablo>=distancia){
            contador++;
            posicionEstablo = arreglo[i];
        }    
    }
    return contador >= C;
}

/** 
  * Construimos nuestra funcion búsqueda binaria para encontrar el valor esperado. Una vez ordenado nuestro
  * arreglo utilizando nuestra función binarySearch nos va a permitir colocar el número de vacas especificado 
  * en un establo, dado las posiciones de las vacas en el establo. Recibimos como entrada el arreglo ordenado, 
  * el número de vacas (C) y la cantidad de establos (N). 
  **/
int binarySearch(const vector<int>& arreglo, int N, int C) {
    int low = 1; // Incializamos el valor de la busqueda binaria en 1 
    int high = arreglo[N - 1] - arreglo[0];  
    int ans = 0;

    /**
      * Nuestro ciclo while se va a ejecuar mientras el valor de low sea menor o igual al valor de high y esto nos
      * aesgura que la búsqueda binaria continúe hasta que se haya encontrado el valor ans. Al declarar m dividimos
      * el rango de búsqueda a la mitad en cada iteración.
      **/
    while (low <= high) {
        int m = low + (high - low) / 2; // Mitad del arreglo
        /**
          * Si chequeo retorna true, entonces SI se pueden colocar todas las vacas con una distancia mínima de m, 
          * por lo que actualiza nuestro resultado con m y mueve low a m + 1 para buscar una distancia mayor.
          * Si chequeo retorna false, entonces NO se pueden colocar todas las vacas con una distancia mínima de m, 
          * por lo que mueve high a m - 1 para buscar una distancia menor.
          **/
        if (chequeo(arreglo, N, C, m)) {
            ans = m;
            low = m + 1;
        } else {
            high = m - 1;
        }
    }
    return ans;
}

/**
  * Finalmente, ya teniendo nuestro algoritmo de ordenamiento (el cual es muy importante para poder aplicar 
  * la búsqueda binaria) y nuestras dos funciones fundamentales: la de chequeo y la función de búsqueda binaria, lo que queda
  * es declarar nuestras variables planteadas en el problema, almacenar nuestras N cantidad de establos en un arreglo para 
  * poder indicar por terminal dicho arreglo, el cual serán las distancias entre cada establo. 
  * Conquistamos aplicando búsqueda binaria.  
  **/
int main(){
    int t;
    cin >> t; // Casos de prueba
    while(t--){
        int N; // Cantidad de establos 
        cin >> N; 
        int C; // Vacas para asignar en los establos 
        cin >> C;

        vector <int> arreglo(N); // Distancia entre los establos 
        for(int i=0; i<N; i++){ // Almacenamos los N elementos dados por consola en un vector
            cin >> arreglo[i];
        }

        /**
          * Muy importante ordenar nuestro arreglo para poder aplicar búsqueda binaria es por ello que 
          * aplicamos nuestro algoritmo de ordenamiento mergeSort.
          **/
        mergeSort(arreglo, 0, N-1);

        /**
          * Finalmente declaramos un entero ans (respuesta) y llamamos nuestra función de búsqueda binaria
          * la cual nos dará como resultado la distancia mínima máxima en que se pueden colocar C vacas en 
          * las N cantidad de establos.                          :) 
          **/
        int ans = binarySearch(arreglo, N, C);
        cout << ans << endl;
    }
    return 0;
}