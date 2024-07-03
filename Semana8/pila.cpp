// MAIKEL DELGADO --- 1610287 --- UNIVERSIDAD SIMON BOLIVAR
// LABORATORIO DE ALGORITMOS Y ESTRUCTURAS II 
// WEEK 8: EXCERCISE - SPOJ
// EXCERSICE: STACKEZ - Easy Stack

#include <iostream>
using namespace std;

// Definimos una estructura que representa un nodo de una lista enlazada.
struct Node{
    int data;
    Node* next;
};

/**
  * Primeramente, definimos una estructura llamada Stack que implementa una pila utilizando una lista enlazada.
  * La estructura Stack tiene un único campo: cima, que es un puntero al nodo en la cima de la pila. Además,
  * esta estructura nos va a permitir crear los metodos que utilizaremos para resolver lo planteado en el enunciado
  * de nuestro problema, tal que podamos agregar, eliminar y consultar elementos en la pila.
  **/
struct Stack{

    // Apuntador al elemento que está encima de la pila: 
    Node* cima;

    /** Creamos "el constructor" de la estructura Stack donde inicializamos 
      * el puntero cima a nullptr, lo que indica que la pila está vacía.
      **/
    Stack(){
        cima = nullptr;
    }

    /** Creamos el método que elimina el elemento en la cima de la pila.
      * Primero, verificamos si la pila está vacía, si no lo está, guardamos el puntero al 
      * nodo en la cima en una variable temporal y actualizamos el puntero cima para que 
      * apunte al siguiente nodo, y luego elimina el nodo en la cima. 
      **/
    void pop(){
        if (cima == nullptr) {
            return;
        }
        Node* temporal = cima;
        cima = cima -> next;
        delete temporal;
    }

    /** Creamos el método que agrega un nuevo elemento a la cima de la pila.
      * Se agrega un nuevo elemento a la cima de la pila. Además, creamos un nuevo nodo
      * que asigna el valor del elemento a su campo data, y lo enlazamos al inicio de la lista 
      * (apuntando al nodo que anteriormente estaba en la cima). Por últino actualizamos el 
      * puntero 'cima' para que apunte al nuevo nodo en la cima.
      **/
    void push(int a){
        Node* nuevoNode = new Node;
        nuevoNode -> data = a;
        nuevoNode -> next = cima;
        cima = nuevoNode;
    }

    /** Creamos el método que devuelve el valor del elemento en la cima de la pila.
      * Primero verificamos si la pila está vacía, si no lo está, devolvemos el valor 
      * del campo data del nodo en la cima.
      **/
    int peek(){
        if (cima == nullptr) {
            return -1;
        }
        return cima -> data;
    }

    // Creamos el método que verifica si la pila está vacía.
    bool pila_vacia() {
        return cima == nullptr;
    }
};

int main() {
    int t; //Número de casos
    scanf("%d", &t);
    Stack pila;

    while (t--) {
        // Declaramos la opcion de la consulta:
        int query;
        scanf("%d", &query);

        // Añadimos el elemento a la pila.
        if (query == 1) {
            int n;
            scanf("%d", &n);
            pila.push(n);
        } 
        // Eliminamos el elemento en la cima de la pila. 
        else if (query == 2) {
            pila.pop();
        } 
        
        // Imprimimos por consola "Empty!" si la pila está vacía.
        else {
            if (pila.pila_vacia()) {
                printf("Empty!\n");
            } 
            // Si no está vacia imprimimos el valor del elemento en la cima.
            else {
                printf("%d\n", pila.peek());
            }
        }
    }
    return 0;
}