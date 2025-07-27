#include <iostream>
#include <cassert>
#include "Grafo.h"
#include "Array.h"
#include "Cola.h"
#include "Pila.h"
#include "MinHeap.h"
#include "ListaEnlazada.h"
#include "Algoritmos.h"

using namespace std;

void testArray() {
    cout << "=== Test Array ===" << endl;
    Array<int> arr;
    
    // Test agregar elementos
    for (int i = 0; i < 5; i++) {
        arr.agregar(i * 10);
    }
    
    cout << "Tamaño del array: " << arr.obtenerTamaño() << endl;
    assert(arr.obtenerTamaño() == 5);
    
    // Test acceso a elementos
    for (int i = 0; i < arr.obtenerTamaño(); i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
        assert(arr[i] == i * 10);
    }
    
    // Test insertar
    arr.insertar(2, 99);
    assert(arr[2] == 99);
    assert(arr.obtenerTamaño() == 6);
    
    cout << "✓ Array test pasado" << endl;
}

void testCola() {
    cout << "\n=== Test Cola ===" << endl;
    Cola<int> cola;
    
    // Test encolar
    for (int i = 1; i <= 5; i++) {
        cola.encolar(i);
    }
    
    cout << "Tamaño de la cola: " << cola.obtenerTamaño() << endl;
    assert(cola.obtenerTamaño() == 5);
    
    // Test desencolar
    cout << "Desencolando elementos: ";
    while (!cola.estaVacia()) {
        cout << cola.desencolar() << " ";
    }
    cout << endl;
    
    assert(cola.estaVacia());
    cout << "✓ Cola test pasado" << endl;
}

void testPila() {
    cout << "\n=== Test Pila ===" << endl;
    Pila<int> pila;
    
    // Test apilar
    for (int i = 1; i <= 5; i++) {
        pila.apilar(i);
    }
    
    cout << "Tamaño de la pila: " << pila.obtenerTamaño() << endl;
    assert(pila.obtenerTamaño() == 5);
    
    // Test desapilar
    cout << "Desapilando elementos: ";
    while (!pila.estaVacia()) {
        cout << pila.desapilar() << " ";
    }
    cout << endl;
    
    assert(pila.estaVacia());
    cout << "✓ Pila test pasado" << endl;
}

void testMinHeap() {
    cout << "\n=== Test MinHeap ===" << endl;
    MinHeap<int> heap;
    
    // Test insertar
    int valores[] = {10, 5, 20, 1, 15, 30, 8};
    for (int i = 0; i < 7; i++) {
        heap.insertar(valores[i]);
    }
    
    cout << "Tamaño del heap: " << heap.obtenerTamaño() << endl;
    assert(heap.obtenerTamaño() == 7);
    
    // Test extraer mínimo
    cout << "Extrayendo elementos en orden: ";
    while (!heap.estaVacio()) {
        cout << heap.extraerMinimo() << " ";
    }
    cout << endl;
    
    cout << "✓ MinHeap test pasado" << endl;
}

void testListaEnlazada() {
    cout << "\n=== Test ListaEnlazada ===" << endl;
    ListaEnlazada<int> lista;
    
    // Test agregar
    for (int i = 1; i <= 5; i++) {
        lista.agregarAlFinal(i);
    }
    
    cout << "Tamaño de la lista: " << lista.obtenerTamaño() << endl;
    assert(lista.obtenerTamaño() == 5);
    
    // Test acceso
    cout << "Elementos de la lista: ";
    for (int i = 0; i < lista.obtenerTamaño(); i++) {
        cout << lista.obtener(i) << " ";
    }
    cout << endl;
    
    // Test buscar
    int indice = lista.buscar(3);
    cout << "Elemento 3 encontrado en índice: " << indice << endl;
    assert(indice == 2);
    
    cout << "✓ ListaEnlazada test pasado" << endl;
}

void testGrafo() {
    cout << "\n=== Test Grafo ===" << endl;
    Grafo grafo;
    
    // Test agregar nodos
    grafo.agregarNodo(1, "Nodo A", 0.0f, 0.0f);
    grafo.agregarNodo(2, "Nodo B", 1.0f, 0.0f);
    grafo.agregarNodo(3, "Nodo C", 0.5f, 1.0f);
    
    cout << "Número de nodos: " << grafo.getNumNodos() << endl;
    assert(grafo.getNumNodos() == 3);
    
    // Test buscar nodo
    Nodo* nodo = grafo.obtenerNodoPorId(2);
    assert(nodo != nullptr);
    cout << "Nodo encontrado: " << nodo->getNombre() << endl;
    
    // Test conectar automáticamente
    grafo.conectarAutomaticamente();
    cout << "Grafo conectado automáticamente" << endl;
    
    cout << "✓ Grafo test pasado" << endl;
}

void testAlgoritmos() {
    cout << "\n=== Test Algoritmos ===" << endl;
    Grafo grafo;
    
    // Crear un grafo simple
    grafo.agregarNodo(1, "A", 0.0f, 0.0f);
    grafo.agregarNodo(2, "B", 1.0f, 0.0f);
    grafo.agregarNodo(3, "C", 0.5f, 1.0f);
    grafo.conectarAutomaticamente();
    
    // Test algoritmos (solo verificar que se ejecuten sin errores)
    cout << "Probando algoritmos de búsqueda..." << endl;
    Algoritmos::BFS(grafo, 1, 3);
    Algoritmos::DFS(grafo, 1, 3);
    Algoritmos::Dijkstra(grafo, 1, 3);
    Algoritmos::AStar(grafo, 1, 3);
    Algoritmos::BestFirstSearch(grafo, 1, 3);
    
    cout << "✓ Algoritmos test pasado" << endl;
}

int main() {
    cout << "=== EJECUTANDO TESTS UNITARIOS ===" << endl;
    
    try {
        testArray();
        testCola();
        testPila();
        testMinHeap();
        testListaEnlazada();
        testGrafo();
        testAlgoritmos();
        
        cout << "\n🎉 TODOS LOS TESTS PASARON EXITOSAMENTE 🎉" << endl;
        
    } catch (const exception& e) {
        cout << "\n❌ ERROR EN TEST: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
