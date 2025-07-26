#include "Grafo.h"
#include <iostream>
#include <cmath>
#include <cstring>

Grafo::Grafo() {
    numNodos = 0;
    for (int i = 0; i < MAX_NODOS; ++i)
        nodos[i] = nullptr;
}

Grafo::~Grafo() {
    for (int i = 0; i < numNodos; ++i)
        delete nodos[i];
}

bool Grafo::agregarNodo(int id, const char* nombre, float x, float y) {
    if (numNodos >= MAX_NODOS) return false;

    nodos[numNodos++] = new Nodo(id, nombre, x, y);
    return true;
}

Nodo* Grafo::obtenerNodoPorId(int id) {
    for (int i = 0; i < numNodos; ++i)
        if (nodos[i]->getId() == id)
            return nodos[i];
    return nullptr;
}

Nodo* Grafo::obtenerNodoPorIndice(int i) {
    if (i >= 0 && i < numNodos)
        return nodos[i];
    return nullptr;
}

int Grafo::getNumNodos() {
    return numNodos;
}

float distanciaEuclidea(Nodo* a, Nodo* b) {
    float dx = a->getX() - b->getX();
    float dy = a->getY() - b->getY();
    return std::sqrt(dx * dx + dy * dy);
}

void Grafo::conectarAutomaticamente() {
    for (int i = 0; i < numNodos; ++i) {
        Nodo* actual = nodos[i];

        int vecinos[3] = {-1, -1, -1};
        float distancias[3] = {1e9, 1e9, 1e9};

        for (int j = 0; j < numNodos; ++j) {
            if (i == j) continue;
            float d = distanciaEuclidea(actual, nodos[j]);

            for (int k = 0; k < 3; ++k) {
                if (d < distancias[k]) {
                    for (int m = 2; m > k; --m) {
                        distancias[m] = distancias[m - 1];
                        vecinos[m] = vecinos[m - 1];
                    }
                    distancias[k] = d;
                    vecinos[k] = j;
                    break;
                }
            }
        }

        for (int k = 0; k < 3; ++k) {
            if (vecinos[k] != -1) {
                actual->agregarVecino(nodos[vecinos[k]]->getId(), distancias[k]);
            }
        }
    }
}

void Grafo::imprimirGrafo() {
    for (int i = 0; i < numNodos; ++i) {
        Nodo* nodo = nodos[i];
        std::cout << "Nodo " << nodo->getId() << " - " << nodo->getNombre() << " (" << nodo->getX() << ", " << nodo->getY() << ")\n";
        nodo->imprimirVecinos();
        std::cout << "---------------------------\n";
    }
}
