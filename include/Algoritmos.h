#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include "Grafo.h"
#include "Metricas.h"

namespace Algoritmos {
    // Algoritmos de búsqueda implementados desde cero (sin STL)
    
    // BFS - Breadth First Search
    ResultadoBusqueda BFS(Grafo& grafo, int nodoInicio, int nodoFin);
    
    // DFS - Depth First Search  
    ResultadoBusqueda DFS(Grafo& grafo, int nodoInicio, int nodoFin);
    
    // Dijkstra - Camino más corto
    ResultadoBusqueda Dijkstra(Grafo& grafo, int nodoInicio, int nodoFin);
    
    // A* - A Star con heurística
    ResultadoBusqueda AStar(Grafo& grafo, int nodoInicio, int nodoFin);
    
    // Best First Search
    ResultadoBusqueda BestFirstSearch(Grafo& grafo, int nodoInicio, int nodoFin);
    
    // Función auxiliar para reconstruir ruta
    RutaSimple reconstruirRuta(int inicio, int fin);
    
    // Función de heurística para A* (distancia euclidiana)
    double heuristica(const Nodo& actual, const Nodo& destino);
    
    // Función para comparar todos los algoritmos
    void compararTodosAlgoritmos(Grafo& grafo, int inicio, int fin);
}

#endif // ALGORITMOS_H