//Determinar el valor numéricamente menor más cercano a la hoja más alejada de la raíz de un AB ingresado
#include <iostream>
#include <climits>
#include "arbolbinario.h"

using namespace std;

int encontrarValorMenor(NodoBinario* nodo, int nivel, int& nivelMaximo) {
    if (nodo == nullptr)
        return INT_MAX;

    if (nodo->getIzq() == nullptr && nodo->getDer() == nullptr) {
        if (nivel > nivelMaximo) {
            nivelMaximo = nivel;
            return nodo->getDato();
        } else {
            return INT_MAX;
        }
    }

    int valorIzq = encontrarValorMenor(nodo->getIzq(), nivel + 1, nivelMaximo);
    int valorDer = encontrarValorMenor(nodo->getDer(), nivel + 1, nivelMaximo);

    return min(valorIzq, valorDer);
}

int main() {
    ArbolBinario arbol;
    arbol.leer();

    cout << "Árbol ingresado:" << endl;
    arbol.imprimirABJerarquia(arbol.getRaiz(), 0);

    int nivelMaximo = 0;
    int valorMenor = encontrarValorMenor(arbol.getRaiz(), 0, nivelMaximo);

    if (valorMenor != INT_MAX) {
        cout << "\nValor numéricamente menor más cercano a la hoja más alejada: " << valorMenor << endl;
    } else {
        cout << "\nNo se encontró ningún valor numéricamente menor." << endl;
    }

    return 0;
}