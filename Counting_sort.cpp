/*
Counting Sort modificado: O(n+k) para cada caso. 

Es un algoritmo que no compara los datos directamente y es útil
cuando se conoce un rango en el valor de los datos (edades, notas, etc.). 

“n” como siempre es el largo del arreglo, mientras que “k”
es el rango que se tiene entre el valor mínimo y máximo.  

Con un arreglo desordenado, se crea un arreglo auxiliar que llevará las frecuencias de cada uno de los datos 
(Este arreglo considera el 0, por lo que tiene un tamaño de Rango + 1): 

[1, 2, 4, 3, 3, 7] -> [0, 1, 1, 2, 1, 0, 0, 1] 

Donde el índice indicará el valor, mientras que el dato indicará sus repeticiones.
Ya con el arreglo auxiliar, se guardan los valores en el nuevo arreglo, guardando un valor según índice por cada tamaño de dicho índice: 

[0, 1, 1, 2, 1, 0, 0, 1] -> [] 			[0, 0, 1, 2, 1, 0, 0, 1] -> [1] 

[0, 0, 0, 2, 1, 0, 0, 1]->[1,2] 			[0, 0, 0, 1, 1, 0, 0, 1]->[1,2,3] 

[0, 0, 0, 0, 1, 0, 0, 1] -> [1,2,3,3] 

. 
.
.

[0,0,0,0,0,0,0,0] -> [1,2,3,3,4,7] 


De esta forma solo hacen falta tres pasadas para ordenar el arreglo, 
una para buscar el valor máximo, la segunda para generar el arreglo de índices y valores,
y una tercera para ordenar el arreglo según el arreglo de índices. 

La modificación que le hicimos es que evitamos calcular el arreglo de suma, 
ya que eso toma otra iteración de tiempo “k”, y en vez de eso, 
nosotros ordenamos el arreglo simplemente con el arreglo de índices y 
basándonos en la cantidad que debemos agregar cada valor. 
*/

vector<int> counting_sort(vector<int> vec){
    int max = 0;
    //buscamos el maximo elemento 
    for(int i = 0; i < vec.size(); i++){
        if(max < vec[i]){
            max = vec[i];
        }
    }
    //creamos un vector que tenga todos los elementos posibles
    vector<int> val(max+1,0);
    
    //por cada aparicion de un elemento sumamos uno a su pocicion, y asi podemos repetirlos luego
    for(int i = 0; i < vec.size(); i++){
        val[vec[i]]++;
    }
    
    int j = 0;

    //copiamos en el vecor original todos los elementos y las veces q aparecen de manera ordenada
    for(int i = 0; i <= max; i++){
        while(val[i] > 0){
            vec[j] = i;
            j++;
            val[i]--;
        }
    }
    return vec;
}
