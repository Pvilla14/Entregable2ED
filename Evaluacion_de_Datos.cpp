#include<iostream>
#include<vector>
#include<numeric>
#include<sstream>
#include<time.h>
#include<string>
#include<string.h>
#include<cstdlib> 
#include<ctime>
#include<chrono>
#include<fstream>
#include<cstdint>
#include<stack>
#include<random>
#include<climits>
#include<algorithm>

using namespace std;


int main() {
	srand(time(0));
	/*int size = 500000;
	vector<int32_t> vec*/;
	vector<double> duraciones_promedio;
	vector<double> duracionesqi, duracionesqr, duracionesi,  duracionesm, duracionesc, duracionesh, duracionesb, duracionesbo, duracionesio,
    duracionesmo, duracionesho, duracionesco, duracionesso, duracionesqio, duracionesqro, duracioness, duraciones;
	chrono::high_resolution_clock::time_point start, end;
    chrono::duration<double> duracion;
	int Tarchivo = 1;
	int automatico = 1; 
	while(automatico < 4){
		for(int i = 0; i < 30; i++){

			generarArchivo("vector.bin", Tarchivo);
			vector<int32_t> vec = leer_vector("vector.bin");
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			quick_sort_iterativo(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesqi.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesqi.size(); i++){
			cout << "quick_sort_iterativo;" << duracionesqi[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesqi.clear();

        for(int i = 0; i < 30; i++){

			generarArchivo("vector.bin", Tarchivo);
			vector<int32_t> vec = leer_vector("vector.bin");
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			quick_sort_recursivo(vec,0,vec.size()-1); 
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesqr.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesqr.size(); i++){
			cout << "quick_sort_recursivo;" << duracionesqr[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesqr.clear();

        for(int i = 0; i < 30; i++){

			generarArchivo("vector.bin", Tarchivo);
			vector<int32_t> vec = leer_vector("vector.bin");
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			merge_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesm.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesm.size(); i++){
			cout << "merge_sort;" << duracionesm[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesm.clear();

        for(int i = 0; i < 30; i++){

			generarArchivo("vector.bin", Tarchivo);
			vector<int32_t> vec = leer_vector("vector.bin");
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			counting_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesc.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesc.size(); i++){
			cout << "counting_sort; " << duracionesc[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesc.clear();

        for(int i = 0; i < 30; i++){

			generarArchivo("vector.bin", Tarchivo);
			vector<int32_t> vec = leer_vector("vector.bin");
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			sort(vec.begin(), vec.end());
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracioness.push_back(duracion.count());
		}
		for(int i = 0; i < duracioness.size(); i++){
			cout << "std_sort; " << duracioness[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracioness.clear();

        for(int i = 0; i < 30; i++){

			generarArchivo("vector.bin", Tarchivo);
			vector<int32_t> vec = leer_vector("vector.bin");
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			heap_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesh.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesh.size(); i++){
			cout << "heap_sort; " << duracionesh[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesh.clear();

        for(int i = 0; i < 30; i++){

			generarArchivo("vector.bin", Tarchivo);
			vector<int32_t> vec = leer_vector("vector.bin");
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			insertion_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesi.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesi.size(); i++){
			cout << "insertion_sort;" << duracionesi[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesi.clear();

        for(int i = 0; i < 30; i++){

			generarArchivo("vector.bin", Tarchivo);
			vector<int32_t> vec = leer_vector("vector.bin");
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			buble_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesb.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesb.size(); i++){
			cout << "buble_sort; " << duracionesb[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesb.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			quick_sort_recursivo(vec,0,vec.size()-1);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesqro.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesqro.size(); i++){
			cout << "quick_recursivo_sort_ordenado; " << duracionesqro[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesqro.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			quick_sort_iterativo(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesqio.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesqio.size(); i++){
			cout << "quick_iterativo_sort_ordenado; " << duracionesqio[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesqio.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			sort(vec.begin(), vec.end());
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesso.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesso.size(); i++){
			cout << "std_sort_ordenado; " << duracionesso[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesso.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			counting_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesco.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesco.size(); i++){
			cout << "counting_sort_ordenado; " << duracionesco[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesco.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			heap_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesho.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesho.size(); i++){
			cout << "heap_sort_ordenado; " << duracionesho[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesho.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			merge_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesmo.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesmo.size(); i++){
			cout << "merge_sort_ordenado; " << duracionesmo[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesmo.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			insertion_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesio.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesio.size(); i++){
			cout << "insertion_sort_ordenado; " << duracionesio[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesio.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			buble_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesbo.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesbo.size(); i++){
			cout << "buble_sort_ordenado; " << duracionesbo[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesbo.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_invertido(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			quick_sort_recursivo(vec,0,vec.size()-1);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesqro.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesqro.size(); i++){
			cout << "quick_recursivo_sort_inverso; " << duracionesqro[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesqro.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_invertido(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			quick_sort_iterativo(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesqio.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesqio.size(); i++){
			cout << "quick_iterativo_sort_inverso; " << duracionesqio[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesqio.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_invertido(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			sort(vec.begin(), vec.end());
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesso.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesso.size(); i++){
			cout << "std_sort_inverso; " << duracionesso[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesso.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_invertido(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			counting_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesco.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesco.size(); i++){
			cout << "counting_sort_inverso; " << duracionesco[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesco.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_invertido(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			heap_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesho.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesho.size(); i++){
			cout << "heap_sort_inverso; " << duracionesho[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesho.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_invertido(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			merge_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesmo.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesmo.size(); i++){
			cout << "merge_sort_inverso; " << duracionesmo[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesmo.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_invertido(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			insertion_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesio.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesio.size(); i++){
			cout << "insertion_sort_inverso; " << duracionesio[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesio.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_invertido(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			buble_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesbo.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesbo.size(); i++){
			cout << "buble_sort_inverso; " << duracionesbo[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesbo.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_parcialmente_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			quick_sort_recursivo(vec,0,vec.size()-1);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesqro.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesqro.size(); i++){
			cout << "quick_recursivo_sort_semi_ordenado; " << duracionesqro[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesqro.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_parcialmente_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			quick_sort_iterativo(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesqio.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesqio.size(); i++){
			cout << "quick_iterativo_sort_semi_ordenado; " << duracionesqio[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesqio.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_parcialmente_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			sort(vec.begin(), vec.end());
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesso.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesso.size(); i++){
			cout << "std_sort_semi_ordenado; " << duracionesso[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesso.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_parcialmente_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			counting_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesco.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesco.size(); i++){
			cout << "counting_sort_semi_ordenado; " << duracionesco[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesco.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_parcialmente_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			heap_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesho.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesho.size(); i++){
			cout << "heap_sort_semi_ordenado; " << duracionesho[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesho.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_parcialmente_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			merge_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesmo.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesmo.size(); i++){
			cout << "merge_sort_semi_ordenado; " << duracionesmo[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesmo.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_parcialmente_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			insertion_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesio.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesio.size(); i++){
			cout << "insertion_sort_semi_ordenado; " << duracionesio[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesio.clear();

        for(int i = 0; i < 30; i++){

			vector<int32_t> vec = crear_vector_parcialmente_ordenado(1024*1024*Tarchivo);//crea vector de Tarchivo megabytes ordenado
			start = chrono::high_resolution_clock::now(); //Toma el tiempo de ejecucion.
			buble_sort(vec);
			end = chrono::high_resolution_clock::now();
			duracion = end - start;
			duracionesbo.push_back(duracion.count());
		}
		for(int i = 0; i < duracionesbo.size(); i++){
			cout << "buble_sort_semi_ordenado; " << duracionesbo[i] << ";"<< Tarchivo << "mb"<< endl;
		}
        duracionesbo.clear();

	}
	
	return 0;
}
