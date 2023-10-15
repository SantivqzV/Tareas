/**
 * Santiago Vázquez Villarreal
 * A01177850
 * v1
 * 
 * Fecha de creación: 13/10/2023
 * Fecha de modificación: 15/10/2023
 * 
 * Descripción:
 * El programa implementa una cola de prioridad utilizando un árbol Heap. La clase PriorityQueue proporciona métodos para insertar
 * eliminar y mostrar los elementos del arbol. Este programa crea un objeto de la clase PriorityQueue y lo utiliza para 
 * insertar una serie de elementos, eliminarlos, y mostrar el estado del árbol despues de cada eliminación. 
 * 
 * Referencias:
 * Binary Heap. (2014, November). GeeksforGeeks; GeeksforGeeks. https://www.geeksforgeeks.org/binary-heap/
 * 
*/

#include <iostream>
using namespace std;

/**
 * @class PriorityQueue
 * 
 * @brief Clase que representa un árbol Heap
 * 
 * Esta clase proporciona una implementación de un árbol Heap que puede ser utilizado como una cola de prioridad.
 * Esta clase incluye métodos para insertar, eliminar y mostrar los elementos del árbol.
 * 
 * @tparam T Tipo de dato de los elementos del árbol
 * @param heapArray Arreglo que almacena los elementos del árbol, al igual que muestra su tamaño máximo
 * @param size Tamaño actual del árbol
*/
template <class T>
class PriorityQueue{
    public:
        int heapArray[1000];
        int size = 0;

        //Constructor por defecto de un heap
        PriorityQueue(){

        }

        //Destructor del Heap
        ~PriorityQueue(){
            delete heapArray;
        }

        /**
         * @brief Método que inserta un elemento en el árbol
         * 
         * Este método inserta un elemento en el árbol, y lo acomoda en la posición correcta de acuerdo a su prioridad.
         * 
         * @param value Valor del elemento a insertar
         * @return void
         * 
         * @note Complejidad de tiempo: O(log(n))
         * @note Complejidad de espacio: O(n)
        */
        void push(int value){
            heapArray[size] = value;
            size++;

            //Acomodar el heap
            if(size > 1){
                swiftUp((size/2)-1);
            }
        }

        /**
         * @brief Método que elimina el elemento con mayor prioridad del árbol
         * 
         * Este método elimina el elemento con mayor prioridad del árbol, y lo acomoda en la posición correcta de acuerdo a su prioridad.   
         * 
         * @return void
         * 
         * @note Complejidad de tiempo: O(log(n))
         * @note Complejidad de espacio: O(n)
        */
        void pop(){
            //Checar si el heap está vacío
            if(empty()){
                cout << "No hay datos a eliminar" << endl;
                return;
            }

            //Intercambiar valores para eliminar lista
            cout << "Eliminando dato..." << endl;
            int temp = heapArray[size-1];
            heapArray[size-1] = heapArray[0];
            heapArray[0] = temp;
            size--;

            //Acomodar el heap
            if(size > 1){
                swiftDown(0);
            }
        }

        /**
         * @brief Método auxiliar swap
         * 
         * Este método auxiliar intercambia dos elementos del árbol.
         * 
         * @param x Índice del primer elemento a intercambiar
         * @param y Índice del segundo elemento a intercambiar
         * 
         * @return void
         * 
         * @note Complejidad de tiempo: O(1)
         * @note Complejidad de espacio: O(1)
        */
        void swap(int x, int y){
            int temp = heapArray[x];
            heapArray[x] = heapArray[y];
            heapArray[y] = temp;
        }

        /**
         * @brief Método auxiliar SwiftUp
         * 
         * Este método auxiliar acomoda un elemento en la posición correcta de acuerdo a su prioridad.
         * 
         * @param index Índice del elemento a acomodar
         * @return void
         * 
         * @note Complejidad de tiempo: O(log(n))
         * @note Complejidad de espacio: O(n)
        */
        void swiftUp(int index){
            int max = index;
            int left = (2 * index) + 1;
            int right = (2 * index) + 2;
            if(left < size && heapArray[left] > heapArray[max]){
                max = left;
            }
            if(right < size && heapArray[right] > heapArray[max]){
                max = right;
            }
            if(max != index){
                swap(max,index);
                swiftUp((index-1)/2);
            }
        }

        /**
         * @brief Método auxiliar SwiftDown
         * 
         * Este método auxiliar acomoda un elemento en la posición correcta de acuerdo a su prioridad.
         * 
         * @param index Índice del elemento a acomodar
         * @return void
         * 
         * @note Complejidad de tiempo: O(log(n))
         * @note Complejidad de espacio: O(n)
        */
        void swiftDown(int index){
            int max = index;
            int left = (2 * index) + 1;
            int right = (2 * index) + 2;
            if(left < size && heapArray[left] > heapArray[max]){
                max = left;
            }
            if(right < size && heapArray[right] > heapArray[max]){
                max = right;
            }
            if(max != index){
                swap(index, max);
                swiftDown(max);
            }
        }

       /**
        * @brief Método que muestra el elemento con mayor prioridad del árbol
        * 
        * Este método muestra el elemento con mayor prioridad del árbol, sin eliminarlo.
        * 
        * @return void
        * 
        * @note Complejidad de tiempo: O(1)
        * @note Complejidad de espacio: O(1)
       */
        void top(){
            if(empty()){
                cout << "La lista está vacía" << endl;
                return;
            }
            cout << heapArray[0] << endl;
        }

        /**
         * @brief Método que muestra todos los elementos del árbol
         * 
         * Este método muestra todos los elementos del árbol, sin eliminarlos.
         * 
         * @return void
         * 
         * @note Complejidad de tiempo: O(n)
         * @note Complejidad de espacio: O(1)
        */
        void print(){
            if(empty()){
                cout << "La lista no contiene elementos" << endl;
                return;
            }
            for(int i = 0; i < size; i++){
                cout << heapArray[i] << " ";
            }
            cout << endl;
        }

        /**
         * @brief Método que muestra el tamaño del árbol
         * 
         * Este método muestra el tamaño del árbol.
         * 
         * @return void
         * 
         * @note Complejidad de tiempo: O(1)
         * @note Complejidad de espacio: O(1)
        */
        void getSize(){
            cout << size << endl;
        }

        /**
         * @brief Método que muestra si el árbol está vacío
         * 
         * Este método muestra si el árbol está vacío.
         * 
         * @return true si el árbol está vacío, false si el árbol no está vacío
         * 
         * @note Complejidad de tiempo: O(1)
         * @note Complejidad de espacio: O(1)
        */
        bool empty(){
            if(size == 0){
                return true;
            }
            return false;
        }
};

int main(){
    //Crear Heap
    PriorityQueue<int>* heap = new PriorityQueue<int>();

    //Insertar elementos
    int elementos[] = {7,6,5,4,3,2,1};
    int size = sizeof(elementos)/sizeof(elementos[0]);
    for(int i = 0; i < size; i++){
        heap->push(elementos[i]);
    }

    //Mostrar Heap Completo
    cout << "Comienza Procesamiento de datos" << endl << "********************************************" << endl;
    cout << "Heap Original: ";
    heap -> print();
    cout << endl;
    
    //Checar el elementos salir
    cout << "Valor a salir (TOP): ";
    heap -> top();
    cout << endl;

    //Eliminar elemento
    heap -> pop();
    cout << endl;

    //Mostrar Heap actualizado
    cout << "Árbol actualizado: ";
    heap -> print();
    cout << endl;

    //Mostrar el tañano del nuevo 
    cout << "Tamaño del árbol actualizado: ";
    heap -> getSize();
    cout << endl;

    //Mostar si la lista está vacía
    cout << "¿El árbol está vacío? ";
    if(heap -> empty()){
        cout << "Sí" << endl;
    }
    else{
        cout << "No" << endl;
    }
    cout << endl;
} 