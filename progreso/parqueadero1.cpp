#include <iostream>
#include <string>

const int FILAS = 16;
const int COLS = 16;

char mapa[FILAS][COLS];

void mostrarMapa(char (*m)[COLS]) {
    std::cout << "\nMAPA PARQUEADERO\n";
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
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
        std::cout << "2. Salir\n";
        std::cout << "Opcion: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarMapa(mapa);
                break;

            case 2:
                std::cout << "Saliendo...\n";
                break;

            default:
                std::cout << "Opcion invalida\n";
        }

    } while (opcion != 2);

    return 0;
}