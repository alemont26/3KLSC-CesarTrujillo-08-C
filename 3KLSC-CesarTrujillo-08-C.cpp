#include <iostream>

#define MaxTamC 10

typedef int TipoDato;

int main() {
    int frente = 0, final = 0;
    TipoDato A[MaxTamC];

    int contador = 0;
    char respuesta;

    std::cout << "Desea agregar elementos a la cola? (s/n): ";
    std::cin >> respuesta;

    while ((respuesta == 's' || respuesta == 'S') && contador < MaxTamC) {
        if ((final + 1) % MaxTamC == frente) {
            std::cout << "Desbordamiento de la cola" << std::endl;
            return 1;
        }

        std::cout << "Ingrese un elemento para la cola: ";
        TipoDato elemento;
        std::cin >> elemento;

        A[final] = elemento;
        final = (final + 1) % MaxTamC;
        contador++;

        std::cout << "Elemento " << contador << " agregado a la cola: " << elemento << std::endl;

        if (contador < MaxTamC) {
            std::cout << "Desea agregar más elementos a la cola? (s/n): ";
            std::cin >> respuesta;
        }
    }

    if (frente == final) {
        std::cout << "La cola está vacía." << std::endl;
        return 1;
    }

    TipoDato primerElemento = A[frente];
    std::cout << "El primer elemento de la cola es: " << primerElemento << std::endl;

    frente = (frente + 1) % MaxTamC;

    std::cout << "Elementos de la cola en el orden de ingreso: " << std::endl;
    for (int i = frente; i != final; i = (i + 1) % MaxTamC) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}