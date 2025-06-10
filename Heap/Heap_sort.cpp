/*
Heap: O(n log(n)) para cada caso. 

Heap sort es un ordenamiento basado en un árbol binario Heap, un árbol binario Heap es un árbol binario completo
que permite acceso rápido al elemento máximo o mínimo, esto dependiendo si es Max Heap o Min Heap, en un Min Heap 
el elemento de la raíz es el mínimo y así la propiedad debe cumplirse recursivamente para los nodos sucesivos,
en un Max Heap seria al revés, una vez sabido esto Heap sort  podríamos decir que Heap sort funciona como una 
optimización de selección sort en la que podemos encontrar y mover el elemento mayor en menor tiempo. 
*/
#include <vector>

using namespace std;



void heapify(vector<int>& vec, int n, int i){

    // Iniciamos el mas grande como raiz
    int largest = i;

    // index izquierdo = 2*i + 1
    int l = 2 * i + 1;

    // index derecho = 2*i + 2
    int r = 2 * i + 2;

    // SI el hijo izquiedo es mas grande que la raiz
    if (l < n && vec[l] > vec[largest])
        largest = l;

    // SI el hijo derecho es mas grande que la raiz
    if (r < n && vec[r] > vec[largest])
        largest = r;

    // Si el mas grande no es raiz
    if (largest != i) {
        swap(vec[i], vec[largest]);

        // Recursivamente hace heapify al sub-arbol afectado
        heapify(vec, n, largest);
    }
}

vector<int> heap_sort(vector<int> vec){
    // Construimos el heap (reordenamos el vector)
    for (int i = vec.size() / 2 - 1; i >= 0; i--)
        heapify(vec, vec.size(), i);

    // uno por uno eliminamos un elemento del heap
    for (int i = vec.size() - 1; i > 0; i--) {

        // Mover la raiz actual al final
        swap(vec[0], vec[i]);

        // Llamamos max-heapify en el heap reducido
        heapify(vec, i, 0);
    }

    return vec;
}
