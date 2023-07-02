//Generar una lista con los nodos externos de un árbol previamente ingresado
#include <vector>
#include <iostream>
#include "ArbolBinario.h"

using namespace std;

void obtenerNodosExternos(NodoBinario* nodo, vector<Tipo>& nodosExternos) {
    if (nodo == NULL) {
        return;
    }

    if (nodo->getIzq() == NULL && nodo->getDer() == NULL) {
        nodosExternos.push_back(nodo->getDato());
    }

    obtenerNodosExternos(nodo->getIzq(), nodosExternos);
    obtenerNodosExternos(nodo->getDer(), nodosExternos);
}

int main() {
    ArbolBinario arbol;
    arbol.leer();

    vector<Tipo> nodosExternos;
    obtenerNodosExternos(arbol.getRaiz(), nodosExternos);

    cout << "Nodos externos del árbol:" << endl;
    for (const auto& nodo : nodosExternos) {
        cout << nodo << " ";
    }
    cout << endl;

    return 0;
}