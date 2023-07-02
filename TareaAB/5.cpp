//Calcular el rango (diferencia entre el valor mayor y el menor) de un ABB ingresado
#include <iostream>
#include "arbolbinario.h"

using namespace std;

int encontrarMinimo(NodoBinario* nodo) {
    if (nodo == nullptr)
        return INT_MAX;

    int valorActual = nodo->getDato();
    int valorIzq = encontrarMinimo(nodo->getIzq());
    int valorDer = encontrarMinimo(nodo->getDer());

    return min(valorActual, min(valorIzq, valorDer));
}

int encontrarMaximo(NodoBinario* nodo) {
    if (nodo == nullptr)
        return INT_MIN;

    int valorActual = nodo->getDato();
    int valorIzq = encontrarMaximo(nodo->getIzq());
    int valorDer = encontrarMaximo(nodo->getDer());

    return max(valorActual, max(valorIzq, valorDer));
}

int calcularRango(ArbolBinario& arbol) {
    NodoBinario* raiz = arbol.getRaiz();
    int minimo = encontrarMinimo(raiz);
    int maximo = encontrarMaximo(raiz);

    return maximo - minimo;
}

int main() {
    ArbolBinario arbol;
    arbol.leer();

    cout << "Árbol ingresado:" << endl;
    arbol.imprimirABJerarquia(arbol.getRaiz(), 0);

    int rango = calcularRango(arbol);

    cout << "\nRango del Árbol Binario de Búsqueda: " << rango << endl;

    return 0;
}
