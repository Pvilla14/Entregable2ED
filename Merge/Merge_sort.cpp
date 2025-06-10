/*
Merge: O(n log(n)) para cada caso. 

Merge sort es un algoritmo basado en la división del trabajo a realizar. Comenzando con un array desordenado que se divide en dos partes iguales, 
se repite este proceso varias veces hasta que solamente quedan arreglos de un elemento, en este punto los arreglos contienen un único dato “ordenado”.
Cuando se tienen los arreglos simples, se empiezan a combinar (mergear), haciendo comparaciones mientras combina los elementos de cada mitad en un arreglo más grande, 
repitiendo este proceso hasta que se consigue el arreglo original ordenado. 
*/
#include <vector>

using namespace std;

vector<int> merge(const std::vector<int>& A, const std::vector<int>& B) {
    vector<int> C;
    int i = 0, j = 0;

    //copiamos los elementos en orden
    while (i < A.size() && j < B.size()) {
        if (A[i] < B[j]) {
            C.push_back(A[i++]);
        } else {
            C.push_back(B[j++]);
        }
    }
    //copiamos lo que falto de A
    while (i < A.size()) {
        C.push_back(A[i++]);
    }
    //copiamos lo que falto de B
    while (j < B.size()) {
        C.push_back(B[j++]);
    }

    return C;
}

vector<int> merge_sort(const std::vector<int>& A) {
    int size = A.size();
    if (size < 2) {
        return A;
    }
    //copiamos la mitad del vector en uno y la otra mitad en el otro, no importa si son pares o impares
    int mid = size / 2;
    vector<int> left(A.begin(), A.begin() + mid);
    vector<int> right(A.begin() + mid, A.end());
    //ordenamos cada uno de manera recursiva
    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);
}
