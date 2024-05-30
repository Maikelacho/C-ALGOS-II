// MAIKEL DELGADO -- 1610287 -- UNIVERSIDAD SIMÓN BOLIVAR 
// LABORATORIO DE ALGORITMOS Y ESTRUCTURAS II 
// SEMANA 3: CODEFORCES
// EXCERSICE: B. Collecting Game 

#include <iostream>
#include <vector>
#include <utility>  
using namespace std;

/** 
  * Primeramente, creamos una funcion denominada "merge" donde dividiremos nuestro arreglo en dos subarreglos (dividir).
  * Dado nuestro arreglo de entrada (matriz) queremos ordenarlo y lo  que se hará es dividir el arreglo e implementar 
  * nuestro algoritmo de ordenamiento ya mencionado. Dividimos y fusionamos al compararlos. 
  **/
void merge(vector<pair<long long, int>>& arreglo, int U, int m, int V) {
    // "U" primer elemento del arreglo, "m" mitad del arreglo, "V" elemento final del arreglo 
    int n1 = m - U + 1; //Tamaño del primer subarreglo
    int n2 = V - m; //Tamaño del segundo subarreglo

    vector<pair<long long, int>> L(n1); //subarreglo L de tamaño n1
    vector<pair<long long, int>> R(n2); //subarreglo R de tamaño n2

    // Copiamos el arreglo original a los temporales: L y R 
    for (int i = 0; i < n1; i++) 
        L[i] = arreglo[U + i]; //Desde U hasta U+n1-1 
    for (int j = 0; j < n2; j++)
        R[j] = arreglo[m + 1 + j]; //Desde m+1 hasta n2

    int i = 0;
    int j = 0;
    int k = U;
    // Comparamos las posiciones de i y j de L y R respectivamente 
    while (i < n1 && j < n2) {
        if (L[i].first <= R[j].first) {
            arreglo[k] = L[i]; //Caso 1: copiamos L[i] en el arreglo
            i++;
        } else {
            arreglo[k] = R[j]; //Caso 2: copiamos R[j] en el arreglo
            j++;
        }
        k++;
    }

    //Estos dos últimos bucles son importantes ya que si aún quedan elementos tanto  en L y en R copia los elementos al "arreglo" 
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
void mergeSort(vector<pair<long long, int>>& arreglo, int U, int V) {
    if (U < V) {
        int m = U + (V - U) / 2; //Calculamos el "m" punto medio del arreglo 
        
        mergeSort(arreglo, U, m); //Llamamos recursivamente: de U hasta m
        
        mergeSort(arreglo, m + 1, V); //Llamamos recurisvamente: de m+1 hasta V
        
        //Combinamos los dos subarreglos ordenados en uno solo que va a cubrir el rango de U hasta V 
        merge(arreglo, U, m, V); //Finalmente conquistamos :) 
    }
}

/** 
  * Primeramente dadas las reglas que se nos indicó, lo que se hará es ordenar nuestro arreglo de tamaño n,
  * para así poder comparar termino a termino, para determinar en la comparación que número es mayor para aplicarle 
  * las reglas dadas en el enunciado. Para nuestro main se crearon dos funciones importantes que utilizaremos en el mismo. 
  * El algoritmo de ordenamiento mergeSort nos va a ordenar de forma ascendente nuestro arreglo introducido por terminal. 
  * Debemos crear un nuevo vector nuevo (que difiere del vector que almacena lo n elementos) que va almacenar pares de elementos 
  * del vector "matriz" junto con su índice original. Luego, se utiliza el algoritmo de ordenamiento mergeSort para ordenar el 
  * vector nuevo basado en los valores de los elementos. 
  **/
int main (){
    int t;
    cin >> t; //Casos de prueba
    while(t--){
        int n; //Longitud de la matriz
        cin >> n;

        vector <long long> matriz(n); //Elementos de la matriz(array)
        for(int i=0; i<n; i++){ //Almacenamos los n elementos dados por consola en un vector
            cin >> matriz[i];
        }

        vector<pair<long long, int>> matriz_index(n); //Pares de elementos del vector "matriz" junto con su índice original
        for(int i=0; i<n; i++){
            matriz_index[i] = make_pair(matriz[i], i); 
        }

        mergeSort(matriz_index, 0, n-1);

        /*cout << "Arreglo ordenado:" << endl;
        for (int i = 0; i < n; i++) {
            cout << matriz_index[i].first << " ";
        }
        cout << endl;*/

        /** 
          * Este paso es para calcular los valores acumulados del vector "matriz_index" y los almacenamos en un vector 
          * llamado "acumulado". La idea de hacer esto es que cada elemento de nuestro vector "acumulado" sea la suma de 
          * todos los elementos anteriores del vector llamado "matriz_index.
          **/
        vector<long long> acumulado(n); 
        acumulado[0] = matriz_index[0].first; 
        for (int i = 1; i < n; i++) { 
            acumulado[i] = acumulado[i-1] + matriz_index[i].first; 
        } 
         
        /** 
          * Creamos dos vectores:
          * vector index: se utiliza para almacenar temporalmente los índices de los elementos de matriz_index.
          * vector resultado: este vector almacena los resultados finales y Cada elemento se inicializa con -1 y 
          * esto significa que aún no se encuentra el índice más reciente para ese elemento. 
          **/
        vector<int> index; 
        vector<long long> resultado(n, -1);

        /**
          * Este for es importante ya que recorrecremos el vector matriz_index y va actualizando el vector resultado 
          * con el índice más reciente en el que aparece cada elemento de matriz_index. Esto lo logramos manteniendo un 
          * vector temporal (index) que almacena los índices de los elementos,y actualiza el resultado cada vez que se llega 
          * a un punto en el que se han encontrado todos los elementos más recientes.
          **/
        for (int i = 0; i < n; i++) { 
            index.push_back(matriz_index[i].second);
            if (i == n-1 || acumulado[i] < matriz_index[i+1].first) { 
                /**
                  * Se recorre el vector index y se asigna el valor de i a cada elemento correspondiente 
                  * en el vector resultado. Finalmente, se limpia el vector index para hacer el siguiente recorrido.
                  **/
                for (int encontrado : index) { 
                    resultado[encontrado] = i; 
                } 
                index.clear(); 
            } 
        } 
        
        for (int i = 0; i < resultado.size(); i++) {
            cout << resultado[i] << endl;
        }
        cout << endl;
    } 
    return 0; 
}