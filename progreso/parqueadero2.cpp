#include <iostream>
#include <string>

const int FILAS = 16;
const int COLS = 16;

char mapa[FILAS][COLS];
std::string placas[FILAS][COLS];

void mostrarMapa(char (*m)[COLS]) {
    std::cout << "\nMAPA PARQUEADERO\n";
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void ingresarVehiculo(char (*m)[COLS], std::string p[FILAS][COLS]) {
    int x, y;
    std::string placa;

    std::cout<<"Placa: ";
    std::cin>>placa;

    std::cout<<"Filas y columna: ";
    std::cin>>x>>y;

    if(x >=0 && x < FILAS && y >= 0 && y <COLS) {

        if(m[x][y] == 'L') {
           m[x][y] = 'O';
           p[x][y] = placa;
           std::cout<<"Vehiculo ingresado\n"; 
        } else {
            std::cout<<"Espacio Ocupado\n";
        }
    } else {
        std::cout<<"posicion invalida\n";
    }
}
int main() {

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            mapa[i][j] = 'L';
        }
    }

    int opcion;

do {
    std::cout << "\n1. Mostrar mapa\n";
    std::cout << "2. Ingresar vehiculo\n";
    std::cout << "3. Salir\n";
    std::cout << "Opcion: ";
    std::cin >> opcion;

    switch (opcion) {

        case 1:
            mostrarMapa(mapa);
            break;

        case 2:
            ingresarVehiculo(mapa, placas);
            break;

        case 3:
            std::cout << "Saliendo...\n";
            break;

        default:
            std::cout << "Opcion invalida\n";
    }

} while (opcion != 3);

    return 0;
}

// se puso el ingreso de vehiculos