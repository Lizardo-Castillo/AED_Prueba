#include <iostream>
#include <chrono>
#include <fstream>
#include <functional>
#include <string>
#include "Grafo.h"
#include "Algoritmos.h"
#include "GeneradorDatos.h"
#include "Metricas.h"
#include "lector_csv.h"

/**
 * Programa para pruebas de escalabilidad - Parte II del proyecto
 * Maneja grafos grandes (~2M nodos) y mide rendimiento
 */
class PruebasEscalabilidad {
private:
    Grafo* grafo;
    
public:
    PruebasEscalabilidad() : grafo(nullptr) {}
    
    ~PruebasEscalabilidad() {
        delete grafo;
    }
    
    void ejecutarPruebasCompletas() {
        std::cout << "=== PRUEBAS DE ESCALABILIDAD - PARTE II ===" << std::endl;
        std::cout << "Grafos grandes (~2M nodos)" << std::endl;
        std::cout << "==========================================" << std::endl;
        
        // Prueba 1: Malla pequeña (prueba inicial)
        pruebaInicial();
        
        // Prueba 2: Grafos medianos
        pruebasMedianas();
        
        // Prueba 3: Grafos grandes (si hay suficiente memoria)
        pruebasGrandes();
        
        std::cout << "\n=== PRUEBAS COMPLETADAS ===" << std::endl;
    }
    
private:
    void pruebaInicial() {
        std::cout << "\n--- PRUEBA INICIAL: Malla 100x100 (10,000 nodos) ---" << std::endl;
        
        GeneradorDatos generador;
        generador.generarMallaRegular(100, 100, 0.1, "data/malla_10k.csv");
        
        auto inicio = std::chrono::high_resolution_clock::now();
        
        // Cargar y construir grafo
        grafo = new Grafo();
        if (!leerCSV("data/malla_10k.csv", *grafo)) {
            std::cout << "❌ Error cargando archivo CSV. Usando datos de prueba..." << std::endl;
            // Agregar algunos nodos de prueba
            for (int i = 1; i <= 100; i++) {
                std::string nombre = "Nodo_" + std::to_string(i);
                grafo->agregarNodo(i, nombre.c_str(), i * 0.1f, i * 0.1f);
            }
        }
        grafo->conectarAutomaticamente(); // Usar método disponible
        
        auto finConstruccion = std::chrono::high_resolution_clock::now();
        auto tiempoConstruccion = std::chrono::duration_cast<std::chrono::milliseconds>(finConstruccion - inicio).count();
        
        std::cout << "⏱️  Tiempo de construcción del grafo: " << tiempoConstruccion << " ms" << std::endl;
        std::cout << "📊 Nodos: " << grafo->getNumNodos() << std::endl;
        
        // Ejecutar algoritmos usando métodos estáticos
        ejecutarPruebassAlgoritmos(1, grafo->getNumNodos() / 2);
        
        delete grafo;
        grafo = nullptr;
    }
    
    void pruebasMedianas() {
        std::cout << "\n--- PRUEBAS MEDIANAS: 50,000 nodos ---" << std::endl;
        
        GeneradorDatos generador;
        generador.generarDistribucionNormal(50000, 10, "data/distribucion_50k.csv");
        
        auto inicio = std::chrono::high_resolution_clock::now();
        
        grafo = new Grafo();
        if (!leerCSV("data/distribucion_50k.csv", *grafo)) {
            std::cout << "❌ Error cargando archivo CSV. Usando datos de prueba..." << std::endl;
            // Agregar nodos de prueba
            for (int i = 1; i <= 1000; i++) {
                std::string nombre = "Nodo_" + std::to_string(i);
                grafo->agregarNodo(i, nombre.c_str(), i * 0.05f, i * 0.05f);
            }
        }
        grafo->conectarAutomaticamente();
        
        auto finConstruccion = std::chrono::high_resolution_clock::now();
        auto tiempoConstruccion = std::chrono::duration_cast<std::chrono::milliseconds>(finConstruccion - inicio).count();
        
        std::cout << "⏱️  Tiempo de construcción: " << tiempoConstruccion << " ms" << std::endl;
        std::cout << "📊 Nodos: " << grafo->getNumNodos() << std::endl;
        
        ejecutarPruebassAlgoritmos(1, 500);
        
        delete grafo;
        grafo = nullptr;
    }
    
    void pruebasGrandes() {
        std::cout << "\n--- PRUEBAS GRANDES: 500,000 nodos ---" << std::endl;
        std::cout << "⚠️  Esta prueba puede consumir mucha memoria y tiempo..." << std::endl;
        
        char respuesta;
        std::cout << "¿Continuar con la prueba de 500k nodos? (y/n): ";
        std::cin >> respuesta;
        
        if (respuesta != 'y' && respuesta != 'Y') {
            std::cout << "Prueba de gran escala omitida por el usuario." << std::endl;
            return;
        }
        
        GeneradorDatos generador;
        generador.generarMapaSintetico(500000, 1000.0, 1000.0, 0.1, "data/mapa_500k.csv");
        
        auto inicio = std::chrono::high_resolution_clock::now();
        
        grafo = new Grafo();
        if (!leerCSV("data/mapa_500k.csv", *grafo)) {
            std::cout << "❌ Error cargando archivo CSV. Usando datos de prueba extendidos..." << std::endl;
            // Agregar más nodos de prueba para simular gran escala
            for (int i = 1; i <= 5000; i++) {
                std::string nombre = "Nodo_" + std::to_string(i);
                grafo->agregarNodo(i, nombre.c_str(), i * 0.01f, i * 0.01f);
            }
        }
        
        // Conexión automática
        grafo->conectarAutomaticamente();
        
        auto finConstruccion = std::chrono::high_resolution_clock::now();
        auto tiempoConstruccion = std::chrono::duration_cast<std::chrono::seconds>(finConstruccion - inicio).count();
        
        std::cout << "⏱️  Tiempo de construcción: " << tiempoConstruccion << " segundos" << std::endl;
        std::cout << "📊 Nodos: " << grafo->getNumNodos() << std::endl;
        
        ejecutarPruebassAlgoritmos(1, grafo->getNumNodos() / 10);
        
        delete grafo;
        grafo = nullptr;
    }
    
    void ejecutarPruebassAlgoritmos(int nodoInicio, int nodoFin) {
        std::cout << "\n🔬 Ejecutando algoritmos desde nodo " << nodoInicio << " hasta " << nodoFin << std::endl;
        
        // Función para medir tiempo de ejecución
        auto medirTiempo = [](const std::string& nombre, std::function<ResultadoBusqueda()> funcion) {
            auto inicio = std::chrono::high_resolution_clock::now();
            ResultadoBusqueda resultado = funcion();
            auto fin = std::chrono::high_resolution_clock::now();
            
            auto tiempo = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();
            
            std::cout << "📈 " << nombre << ":" << std::endl;
            std::cout << "   ⏱️  Tiempo: " << tiempo << " ms" << std::endl;
            std::cout << "   ✅ Ruta encontrada: " << (resultado.rutaEncontrada ? "Sí" : "No") << std::endl;
            if (resultado.rutaEncontrada) {
                std::cout << "   🔍 Nodos visitados: " << resultado.metricas.nodosVisitados << std::endl;
                std::cout << "   📏 Longitud ruta: " << resultado.metricas.longitudRuta << std::endl;
                std::cout << "   💾 Memoria estimada: " << resultado.metricas.memoriaUsada << " bytes" << std::endl;
            }
        };
        
        try {
            medirTiempo("BFS", [&]() { return Algoritmos::BFS(*grafo, nodoInicio, nodoFin); });
            medirTiempo("DFS", [&]() { return Algoritmos::DFS(*grafo, nodoInicio, nodoFin); });
            medirTiempo("Dijkstra", [&]() { return Algoritmos::Dijkstra(*grafo, nodoInicio, nodoFin); });
            medirTiempo("A*", [&]() { return Algoritmos::AStar(*grafo, nodoInicio, nodoFin); });
            medirTiempo("Best First", [&]() { return Algoritmos::BestFirstSearch(*grafo, nodoInicio, nodoFin); });
        } catch (const std::exception& e) {
            std::cout << "❌ Error durante la ejecución: " << e.what() << std::endl;
        }
    }
};

int main(int argc, char* argv[]) {
    std::cout << "🔬 PRUEBAS DE ESCALABILIDAD - AED PROYECTO" << std::endl;
    std::cout << "Parte II: Grafos grandes (~2M nodos)" << std::endl;
    std::cout << "========================================" << std::endl;
    
    try {
        PruebasEscalabilidad pruebas;
        pruebas.ejecutarPruebasCompletas();
    } catch (const std::exception& e) {
        std::cerr << "❌ Error crítico: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
