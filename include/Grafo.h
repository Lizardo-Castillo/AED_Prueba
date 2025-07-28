#ifndef GRAFO_H
#define GRAFO_H

#include "Nodo.h"

#define MAX_NODOS 10000  // Aumentado para soportar datasets de escalabilidad

// Estructura simple para conexiones (simplificada)
struct ConexionSimple {
    int nodoDestino;
    double peso;
    
    ConexionSimple() : nodoDestino(-1), peso(0.0) {}
    ConexionSimple(int destino, double p) : nodoDestino(destino), peso(p) {}
};

class Grafo {
private:
    Nodo* nodos[MAX_NODOS];
    int numNodos;

public:
    Grafo();
    ~Grafo();

    // Métodos básicos
    bool agregarNodo(int id, const char* nombre, float x, float y);
    Nodo* obtenerNodoPorId(int id);
    Nodo* obtenerNodoPorNombre(const char* nombre);  // NUEVO: Búsqueda por nombre
    Nodo* obtenerNodoPorIndice(int i);
    int getNumNodos();
    
    // Métodos para algoritmos de búsqueda (simplificados)
    int obtenerNumeroNodos() const;
    Nodo* buscarNodoPorId(int id);
    double obtenerDistancia(int nodoA, int nodoB);

    // Métodos de conexión
    void conectarAutomaticamente();
    void imprimirGrafo();
};

float distanciaEuclidea(Nodo* a, Nodo* b);

#endif
