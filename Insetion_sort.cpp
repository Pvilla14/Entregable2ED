/*
Insertion: O(n) / O(n2) 

Insertion Sort es un algoritmo de ordenamiento que iterativamente mueve cada elemento del segmento sin ordenar a su posición
correcta del segmento ordenado mediante la comparación con sus elementos, básicamente comenzamos de un lado digamos la izquierda en este caso, 
asumimos el primer elemento como ordenado entonces pasamos al siguiente, si es mayor entonces seguimos sino lo movemos a donde corresponde
comparando con nuestra sección ya ordenada (seria ahora el primer elemento intercambiando posición con nuestro primer elemento original) y seguimos hasta que quede todo ordenado. 
*/

vector<int> insertion_sort(vector<int> vec){
	int temp;
	for(int i = 1; i < vec.size(); i++){
		int key = vec[i];
		int j = i - 1;

		while(j >= 0 && vec[j] > key){
			vec[j+1] = vec[j];
			j = j-1;
		}
		vec[j+1] = key;
	}
	return vec;
}
