#ifndef GRAFO_H
#define GRAFO_H

#include "Nodo.h"

#define MAX_NODOS 200

class Grafo {
private:
    Nodo* nodos[MAX_NODOS];
    int numNodos;

public:
    Grafo();
    ~Grafo();

    bool agregarNodo(int id, const char* nombre, float x, float y);
    Nodo* obtenerNodoPorId(int id);
    Nodo* obtenerNodoPorIndice(int i);
    int getNumNodos();

    void conectarAutomaticamente();
    void imprimirGrafo();
};

float distanciaEuclidea(Nodo* a, Nodo* b);

#endif
