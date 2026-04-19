#include <iostream>
#include <string>

const int FILAS = 16;
const int COLS = 16;

char mapa[FILAS][COLS];
std::string placas[FILAS][COLS];
int tiempoEntrada[FILAS][COLS];

bool esLetra(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

bool esNumero(char c) {
    return (c >= '0' && c <= '9');
}

bool validarCarro(std::string placa) {
    if (placa.length() !=6) 
        return false;

    return esLetra(placa[0]) &&
           esLetra(placa[1]) &&
           esLetra(placa[2]) &&
           esNumero(placa[3]) &&
           esNumero(placa[4]) &&
           esNumero(placa[5]);
}

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
    int x, y, t;   
    std::string placa;

    std::cout<<"Placa (ej: AAA000): ";
    std::cin>>placa;

    if(!validarCarro(placa)) {
        std::cout<<"Placa invalida (Toca poner la placa bien ej: AAA000)\n";
        return;
    }

    std::cout<<"Fila y columna: ";
    std::cin>>x>>y;

    if (x >= 0 && x < FILAS && y >= 0 && y < COLS) {

        if (m[x][y] == 'L') {

            std::cout<<"Tiempo de entrada: ";
            std::cin>>t;

            tiempoEntrada[x][y] = t; //agrege esto, porque vi que me falto la operacion apra hacer bien el cobro

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
            
            int salida;
            std::cout<<"Tiempo de salida: ";
            std::cin>>salida;

            int tiempo = salida - tiempoEntrada[x][y];
            int pago = tiempo * 1000;

            std::cout<<"Vehiculo: "<<p[x][y]<<"\n";
            std::cout<<"Tiempo: "<<tiempo<<"\n";
            std::cout<<"Total a pagar: $"<<pago<<"\n";

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
