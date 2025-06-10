/*
Bubble Sort: O(n) / O(n2) 

El algoritmo realiza pasadas del arreglo, comenzando por el primer elemento y comparándolo al segundo,
luego compara el segundo al tercero, continuando hasta penúltimo y ultimo elemento, 
si el elemento siguiente es mayor al elemento previo se intercambian los 2: 

5, 1, 2 --> (5, 1), 2 --> 1, (5, 2) --> 1, 2, 5 

Este algoritmo continúa hasta que no ocurra ningún intercambio, 
lo logra realizando una última pasada revisando que cada número esté en su lugar. 
*/
#include <vector>

using namespace std;

vector<int> buble_sort(vector<int> vec){
    bool cambio = true;
    int ultimo_ordenado = vec.size();
    while(ultimo_ordenado > 0 && cambio == true){
        cambio = false;
        for(int i = 0; i < ultimo_ordenado - 1; i++){
            if(vec[i] > vec[i+1]){
                swap(vec[i], vec[i+1]);
                cambio = true;
            }
        }
        ultimo_ordenado--;
    }
    return vec;
}
