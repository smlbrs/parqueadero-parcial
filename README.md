# Parqueadero en C++

## Estudiantes

* Samuel David Barbosa Morales
* Samuel Mauricio España


## Descripción del proyecto

Este programa simula un parqueadero desarrollado en C++.
Permite registrar vehículos, controlar su ubicación dentro de una matriz, calcular el tiempo de permanencia y generar el cobro correspondiente.

El sistema maneja dos tipos de vehículos:

* Carros (si o si placa: AAA000)
* Motos (si o si placa: AAA00A)


## Funcionalidades

* Mostrar el mapa del parqueadero (16x16)
* Ingresar vehículo con validación de placa
* Evitar registro de placas duplicadas
* Registrar tiempo de entrada
* Retirar vehículo y calcular tiempo de uso
* Generar cobro automático:

  * Carro: $1000 por unidad de tiempo
  * Moto: $500 por unidad de tiempo
* Validación de errores (posición inválida, tiempo incorrecto, etc.)


## Compilación

Para compilar el programa, usa el siguiente comando en la terminal:

g++ src/main.cpp -o parqueadero


## Ejecución

Después de compilar, ejecuta el programa con:

./parqueadero


## Decisiones de diseño

* Se utilizó una **matriz de 16x16** para representar el parqueadero.
* Se emplearon **punteros** para manejar la matriz en funciones.
* Se usó 'std::string' para manejar placas y facilitar su validación.
* Se implementaron funciones separadas para:

  * Validar placas
  * Ingresar vehículos
  * Retirar vehículos
* Se agregaron validaciones para mejorar el sistema:

  * Formato de placa correcto
  * Evitar duplicados
  * Validación de tiempo de salida
* Se diferenció el cobro según el tipo de vehículo.



## Estructura del proyecto


parqueadero/
│
├── main/
│   └── parqueadero.cpp
│
├── progreso/
│   ├── parqueadero1.cpp
│   ├── parqueadero2.cpp
│   ├── parqueadero3.cpp
│   ├── parqueadero4.cpp
│   ├── parqueadero5.cpp
│   └── parqueadero6.cpp
│   └── parqueadero7.cpp 
│
├── README.md
└── .gitignore


## Ejemplo de uso

Tipo (1=Carro, 2=Moto): 1
Placa: ABC123
Fila y columna: 2 3
Tiempo de entrada: 5


Salida:

Vehiculo: ABC123
Tiempo: 3
Total a pagar: $3000

## Conclusión

Este proyecto permite aplicar conceptos fundamentales de programación como:

* Manejo de matrices
* Uso de punteros
* Validación de datos
* Modularizarían con funciones

Además, simula un caso real de gestión de parqueaderos, integrando lógica y control de errores.