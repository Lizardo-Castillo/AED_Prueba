#include "ControlUsuario.h"
#include <iostream>

// Implementación de ControlUsuario
namespace ControlUsuario {
    
    // Variables de estado
    int mouseX = 0, mouseY = 0;
    bool mousePresionado = false;
    int nodoSeleccionado = -1;
    ModoInteraccion modoActual = SELECCION;
    
    void mouse(int boton, int estado, int x, int y) {
        mouseX = x;
        mouseY = y;
        mousePresionado = (estado == 0); // Asumiendo que 0 es presionado
        std::cout << "ControlUsuario: Mouse - botón " << boton << " estado " << estado << " en (" << x << ", " << y << ")" << std::endl;
    }
    
    void teclado(unsigned char tecla, int x, int y) {
        std::cout << "ControlUsuario: Tecla '" << tecla << "' presionada en (" << x << ", " << y << ")" << std::endl;
    }
    
    void tecladoEspecial(int tecla, int x, int y) {
        std::cout << "ControlUsuario: Tecla especial " << tecla << " presionada en (" << x << ", " << y << ")" << std::endl;
    }
    
    void movimientoMouse(int x, int y) {
        mouseX = x;
        mouseY = y;
    }
    
    int detectarNodoCercano(int x, int y) {
        std::cout << "ControlUsuario: Detectando nodo cercano a (" << x << ", " << y << ")" << std::endl;
        return -1; // Implementación básica
    }
    
    void establecerNodoSeleccionado(int id) {
        nodoSeleccionado = id;
        std::cout << "ControlUsuario: Nodo seleccionado: " << id << std::endl;
    }
    
    int obtenerNodoSeleccionado() {
        return nodoSeleccionado;
    }
    
    void establecerModo(ModoInteraccion modo) {
        modoActual = modo;
        const char* nombres[] = {"SELECCION", "AGREGAR_NODO", "AGREGAR_ARISTA", "ELIMINAR"};
        std::cout << "ControlUsuario: Modo cambiado a " << nombres[modo] << std::endl;
    }
    
    ModoInteraccion obtenerModo() {
        return modoActual;
    }
}
