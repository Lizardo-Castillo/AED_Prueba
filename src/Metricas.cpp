#include "Metricas.h"

// Implementación de RutaSimple
RutaSimple::RutaSimple() : longitud(0) {}

void RutaSimple::agregar(int nodo) {
    if (longitud < 100) {
        nodos[longitud++] = nodo;
    }
}

int RutaSimple::size() const { 
    return longitud; 
}

int RutaSimple::operator[](int i) const { 
    return nodos[i]; 
}

// Implementación de Metricas
Metricas::Metricas() : tiempoEjecucion(0), nodosVisitados(0), 
                      longitudRuta(0), distanciaTotal(0), memoriaUsada(0) {}

// Implementación de ResultadoBusqueda
ResultadoBusqueda::ResultadoBusqueda() : rutaEncontrada(false) {}

// Implementación de MedidorTiempo
void MedidorTiempo::comenzar() {
    inicio = std::chrono::high_resolution_clock::now();
}

double MedidorTiempo::terminar() {
    auto fin = std::chrono::high_resolution_clock::now();
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio);
    return duracion.count() / 1000.0; // Convertir a milisegundos
}

// Función para imprimir métricas
void imprimirMetricas(const Metricas& m) {
    std::cout << "\n=== MÉTRICAS DE RENDIMIENTO ===" << std::endl;
    std::cout << "⏱️  Tiempo de ejecución: " << m.tiempoEjecucion << " ms" << std::endl;
    std::cout << "🔍 Nodos visitados: " << m.nodosVisitados << std::endl;
    std::cout << "📏 Longitud de ruta: " << m.longitudRuta << " nodos" << std::endl;
    std::cout << "📐 Distancia total: " << m.distanciaTotal << " unidades" << std::endl;
    std::cout << "💾 Memoria estimada: " << m.memoriaUsada << " bytes" << std::endl;
    std::cout << "==============================\n" << std::endl;
}
