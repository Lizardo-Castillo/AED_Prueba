#ifndef METRICAS_H
#define METRICAS_H

#include <chrono>
#include <iostream>

// Estructura simple para rutas
struct RutaSimple {
    int nodos[100];
    int longitud;
    
    RutaSimple();
    void agregar(int nodo);
    int size() const;
    int operator[](int i) const;
};

// Estructura para almacenar métricas de rendimiento
struct Metricas {
    double tiempoEjecucion;    // En milisegundos
    int nodosVisitados;
    int longitudRuta;
    double distanciaTotal;
    size_t memoriaUsada;       // En bytes (aproximado)
    
    Metricas();
};

// Estructura para almacenar el resultado de un algoritmo
struct ResultadoBusqueda {
    RutaSimple ruta;           // Secuencia de nodos en la ruta
    bool rutaEncontrada;
    Metricas metricas;
    
    ResultadoBusqueda();
};

// Clase para medir tiempo de ejecución
class MedidorTiempo {
private:
    std::chrono::high_resolution_clock::time_point inicio;
    
public:
    void comenzar();
    double terminar();
};

// Función para imprimir métricas
void imprimirMetricas(const Metricas& m);

#endif // METRICAS_H
