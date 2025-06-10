/*
Quick sort: O(n log(n)) / O(n2) 

*Su peor complejidad es cuadrática, pero es tan poco probable que realísticamente es O(n log(n)) 

Quick sort también se basa en la división del trabajo, pero en su caso utiliza un pivote para hacer comparaciones,
este pivote es un elemento aleatorio (o no) del arreglo, tras elegirlo compara los elementos tal que los menores al pivote 
están a la izquierda y los mayores a la derecha, este proceso se repite con el lado derecho e izquierdo del pivote hasta que 
cada elemento quede en el orden correcto. 

Su peor caso ocurre cuando durante todo el algoritmo, el pivote escogido es siempre el mayor o el menor elemento del arreglo. 

En nuestra investigación y experimentación logramos implementar 2 tipos de Quick Sort distintos,
el recursivo que llama a la misma función y el iterativo que usa un Stack para simular las llamadas a la función. 

Recursivo: Es la forma más directa para el uso del algoritmo, se divide en el lado izquierdo y derecho según el pivote
y luego se repite en cada lado hasta que queden elementos de tamaño 1. Esta implementación crea problemas ya que 
tiene que hacer muchas llamadas a la misma función, lo que provoca problemas de memoria y tiempo. 

Iterativo: Usa un Stack para simular el rango de inicio y fin que queda por ordenar y 
realizar la división de ambos lados del pivote (se eligió la mitad del arreglo en la implementación),
esto evita realizar muchas operaciones complejas y salvar en memoria y tiempo,
por lo que se ve una gran diferencia de tiempo entre cada implementación. 
*/

void quick_sort_recursivo(vector<int32_t>& vec, int inicio, int fin){ //vec,0,size-1
	int temp;
	int p;
	int i;
	int pivote;
	if(inicio < fin){
		pivote = vec[rand() % (fin-inicio + 1) + inicio];
		i = inicio - 1;
		for(int j = inicio; j < fin; j++){
			if(vec[j] <= pivote){
				i = i + 1;
				temp = vec[i];
				vec[i] = vec[j];
				vec[j] = temp;
			}
		}
		temp = vec[i+1];
		vec[i+1] = vec[fin];
		vec[fin] = temp;
		p = i+1;

	quick_sort_recursivo(vec, inicio, p-1);
	quick_sort_recursivo(vec, p+1, fin);
	}
}

void quick_sort_iterativo(vector<int32_t>& vec) {
    stack<pair<int, int>> stack;
    stack.push({0, (int)vec.size() - 1});

    while (!stack.empty()) {
        pair<int, int> current = stack.top();
        stack.pop();
        
        int inicio = current.first;
        int fin = current.second;

        if (inicio >= fin) continue;

        int pivote = vec[(inicio + fin) / 2];
        int i = inicio, j = fin;

        while (i <= j) {
            while (vec[i] < pivote) i++;
            while (vec[j] > pivote) j--;
            if (i <= j) swap(vec[i++], vec[j--]);
        }

        if (inicio < j) stack.push({inicio, j});
        if (i < fin) stack.push({i, fin});
    }
}
