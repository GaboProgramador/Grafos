//Imprimir el subárbol que tiene como nodo raíz el valor menor de un AB ingresado
#include <iostream>
#include "arbolbinario.h"

using namespace std;

NodoBinario* encontrarNodoMenor(NodoBinario* nodo) {
    if (nodo == nullptr)
        return nullptr;

    NodoBinario* nodoMenorIzq = encontrarNodoMenor(nodo->getIzq());
    NodoBinario* nodoMenorDer = encontrarNodoMenor(nodo->getDer());

    NodoBinario* nodoMenorActual = nodo;

    if (nodoMenorIzq != nullptr && nodoMenorIzq->getDato() < nodoMenorActual->getDato()) {
        nodoMenorActual = nodoMenorIzq;
    }

    if (nodoMenorDer != nullptr && nodoMenorDer->getDato() < nodoMenorActual->getDato()) {
        nodoMenorActual = nodoMenorDer;
    }

    return nodoMenorActual;
}

void imprimirSubarbol(NodoBinario* nodo) {
    if (nodo == nullptr)
        return;

    cout << nodo->getDato() << " ";
    imprimirSubarbol(nodo->getIzq());
    imprimirSubarbol(nodo->getDer());
}

int main() {
    ArbolBinario arbol;
    arbol.leer();

    cout << "Árbol ingresado:" << endl;
    arbol.imprimirABJerarquia(arbol.getRaiz(), 0);

    NodoBinario* nodoMenor = encontrarNodoMenor(arbol.getRaiz());

    if (nodoMenor != nullptr) {
        cout << "\nSubárbol con nodo raíz de valor menor (" << nodoMenor->getDato() << "):" << endl;
        imprimirSubarbol(nodoMenor);
        cout << endl;
    } else {
        cout << "\nNo se encontró ningún nodo raíz en el árbol." << endl;
    }

    return 0;
}