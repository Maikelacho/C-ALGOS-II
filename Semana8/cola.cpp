// MAIKEL DELGADO --- 1610287 --- UNIVERSIDAD SIMON BOLIVAR
// LABORATORIO DE ALGORITMOS Y ESTRUCTURAS II 
// WEEK 8: EXCERCISE - SPOJ
// EXCERSICE: QUEUEEZ - Easy Queue

#include <iostream>
using namespace std;

// Definimos la estructura de un nodo de la cola.
struct Node{
    int data;
    Node* next;
};

/**
  * Primeramente, definimos una estrcutura que implementa una cola utilizando una lista enlazada. 
  * Además, esta estructura nos va a permitir exactamente lo que se nos plantea en rl problema: agregar elementos al final 
  * de la cola (enqueue), eliminar elementos del frente de la cola (dequeue), obtener el valor del elemento en el frente de 
  * la cola (cola_frente), y verificar si la cola está vacía (cola_vacia).
  **/
struct Queue{

    // Apuntador al primer elemento de la cola: (frente)
    Node *frente;
    // Apuntador al último elemento de la cola: (parte trasera)
    Node *parte_trasera; 

    /**
      * Creamos "el constructor" de la estructura donde inicializamos ambos punteros 
      * (frente y parte_trasera) a nullptr, lo que significa que la cola está vacía inicialmente.
      **/
    Queue(){
        frente = nullptr;
        parte_trasera = nullptr;
    }

    // Creamos el método que elimina un elemento de la cola.
    void dequeue(){
        
        if (frente == nullptr){  //Verificamos que la cola esta vacia.
          return;
        }

        Node *temporal = frente; //Creamos un puntero temporal llamado 'temporal' y se le asigna el valor de frente.
        frente = frente -> next; //Se actualiza frente para que apunte al siguiente elemento de la cola (si existe).
        
        /**
          * Si después de eliminar el elemento, la cola queda vacía (si frente es nullptr), se actualiza parte_trasera 
          * a nullptr para indicar que la cola está vacía y se elimina el nodo apuntado por temporal utilizando delete.
          **/
        if (frente == nullptr){
            parte_trasera = nullptr;
        }
        delete temporal; 
    }

    // Creamos el método para agregar un elemento a la cola.
    void enqueue(int a){

        Node* nuevoNode = new Node; //Creamos un nuevo elemento para la cola
        nuevoNode -> data = a;
        nuevoNode -> next = nullptr; //Ya que será el último elemento de la cola.

        /**
          * Si la cola está vacía, se asigna s nuevoNode ambos punteros (frente y parte_trasera), 
          * ya que es el único elemento en la cola.
          * 
          * Si la cola no está vacía, se actualiza el campo next del último elemento (apuntado por parte_trasera) 
          * para que apunte al nuevo nodo. Luego, se actualiza parte_trasera para que apunte al nuevo nodo, 
          * convirtiéndolo en el nuevo último elemento de la cola.
          **/
        if (frente == nullptr) {
            frente = nuevoNode;
            parte_trasera = nuevoNode;
        } else {   
            parte_trasera -> next = nuevoNode;
            parte_trasera = nuevoNode;
        }
    }

    // Creamos el método que retorna el primer elemento de la cola.
    int cola_frente() {
        return frente -> data;
    }

    // Creamos el método que verifica si la cola está vacia.
    bool cola_vacia() {
        return frente == nullptr;
    }
};

int main() {
    int t; // Número de casos
    scanf("%d", &t);
    Queue cola; 
    
    while (t--) {
        // Declaramos la opcion de la consulta:
        int querry; 
        scanf("%d", &querry);

        // Añadimos el elemento a la cola.
        if (querry == 1){
            int n; 
            scanf("%d", &n); 
            cola.enqueue(n); 
        } 
        // Eliminamos el primer elemento de la cola
        else if (querry == 2){
            cola.dequeue(); 
        } 
        // Imprimimos por consola el 'Vacio!' si la cola es vacía.
        else{    
            if (cola.cola_vacia()){
                printf("Empty!\n"); 
            } 
            // Si no está vacia, imprimimos el valor del primer elemento de la cola.
            else{
                printf("%d\n", cola.cola_frente()); 
            }
        }
    }
    return 0;
}