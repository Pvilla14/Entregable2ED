//-----Creacion de archivos-----

void generarArchivo(const std::string& nombreArchivo, int megabytes) {
    const int bytesPorMB = 1024 * 1024;
    const int bytesPorEntero = sizeof(int32_t);
    const int totalEnteros = (megabytes * bytesPorMB) / bytesPorEntero;

    std::ofstream archivo(nombreArchivo, std::ios::binary);
    if (!archivo) {
        std::cerr << "Error al crear el archivo" << std::endl;
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> distrib(INT32_MIN, INT32_MAX);

    for (int i = 0; i < totalEnteros; ++i) {
        int32_t num = distrib(gen);
        archivo.write(reinterpret_cast<const char*>(&num), sizeof(num));
    }

    std::cout << "Archivo generado: " << nombreArchivo 
              << " - Tamano: " << megabytes << " MB"
              << " - Enteros: " << totalEnteros << std::endl;
}

vector<int32_t> crear_vector_ordenado(int size){
	vector<int32_t> vec;
	for(int i = 0; i < size; i++){
		vec.push_back(i);
	}
	return vec;
}

vector<int32_t> crear_vector_invertido(int size){
	vector<int32_t> vec;
	for(int i = size; i > 0; i--){
		vec.push_back(i);
	}
	return vec;
}

vector<int> crear_vector_parcialmente_ordenado(int size){
	vector<int32_t> vec;
	for(int i = 0; i < size; i+=5){
		vec.push_back(1 + rand() % 100);
		vec.push_back(vec[i] + rand() % 10);
		vec.push_back(vec[i+1] + rand() % 10);
		vec.push_back(vec[i+2] + rand() % 10);
		vec.push_back(vec[i+3] + rand() % 10);
	}
    return vec;
}
