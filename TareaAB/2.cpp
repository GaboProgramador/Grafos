//Determinar el valor mayor de cada nivel de un AB
#include <iostream>
#include <vector>
#include "arbolbinario.h"

using namespace std;

void encontrarMayorPorNivel(NodoBinario* raiz) {
    if (raiz == nullptr) {
        cout << "El árbol está vacío." << endl;
        return;
    }

    vector<NodoBinario*> nivelActual;
    vector<NodoBinario*> nivelSiguiente;
    nivelActual.push_back(raiz);

    while (!nivelActual.empty()) {
        Tipo mayorValor = nivelActual[0]->getDato();

        for (NodoBinario* nodo : nivelActual) {
            if (nodo->getDato() > mayorValor) {
                mayorValor = nodo->getDato();
            }

            if (nodo->getIzq() != nullptr) {
                nivelSiguiente.push_back(nodo->getIzq());
            }
            if (nodo->getDer() != nullptr) {
                nivelSiguiente.push_back(nodo->getDer());
            }
        }

        cout << "Mayor valor del nivel: " << mayorValor << endl;

        nivelActual = nivelSiguiente;
        nivelSiguiente.clear();
    }
}

int main() {
    ArbolBinario arbol;
    arbol.leer();

    cout << "Árbol ingresado:" << endl;
    arbol.imprimirABJerarquia(arbol.getRaiz(), 0);

    cout << "\nMayor valor por nivel:" << endl;
    encontrarMayorPorNivel(arbol.getRaiz());

    return 0;
}