#include <iostream>
#include <string>

const int FILAS = 16;
const int COLS = 16;

char mapa[FILAS][COLS];
std::string placas[FILAS][COLS];

void mostrarMapa(char (*m)[COLS]) {
    std::cout<<"\nMAPA PARQUEADERO\n";
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

    std::cout<<"Fila y columna: ";
    std::cin>>x>>y;

    if (x >= 0 && x < FILAS && y >= 0 && y < COLS) {

        if (m[x][y] == 'L') {
            m[x][y] = 'O';
            p[x][y] = placa;
            std::cout<<"Vehiculo ingresado\n";
        } else {
            std::cout<<"Espacio ocupado\n";
        }

    } else {
        std::cout<<"Posicion invalida\n";
    }
}

void sacarVehiculo(char (*m)[COLS], std::string p[FILAS][COLS]) {
    int x, y;

    std::cout<<"Fila y columna a retirar: ";
    std::cin>>x>>y;

    if (x >= 0 && x < FILAS && y >= 0 && y < COLS) {

        if (m[x][y] == 'O') {
            std::cout<<"Vehiculo con placa: " <<p[x][y]<<" retirado\n";
            m[x][y] = 'L';
            p[x][y] = "";
        } else {
            std::cout<<"No hay vehiculo en esa posicion\n";
        }

    } else {
        std::cout<<"Posicion invalida\n";
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
        std::cout<<"\n--- PARQUEADERO ---\n";
        std::cout<<"1. Mostrar mapa\n";
        std::cout<<"2. Ingresar vehiculo\n";
        std::cout<<"3. Sacar vehiculo\n";
        std::cout<<"4. Salir\n";
        std::cout<<"Opcion: ";

        /* se puso esto porque
        al poner una opcion que no era valida
        el codigo se enloquecia */
        if (!(std::cin >> opcion)) {
            std::cout<<"Opcion invalida\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (opcion) {

            case 1:
                mostrarMapa(mapa);
                break;

            case 2:
                ingresarVehiculo(mapa, placas);
                break;

            case 3:
                sacarVehiculo(mapa, placas);
                break;

            case 4:
                std::cout<<"Saliendo...\n";
                break;

            default:
                std::cout<<"Opcion invalida\n";
        }

    } while (opcion != 4);

    return 0;
}

//arreglo de un bug que habia