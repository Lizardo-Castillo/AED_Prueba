#ifndef CONTROL_USUARIO_H
#define CONTROL_USUARIO_H

// Control de entrada del usuario (clics y teclado)
namespace ControlUsuario {
    
    // Callbacks de entrada
    void mouse(int boton, int estado, int x, int y);
    void teclado(unsigned char tecla, int x, int y);
    void tecladoEspecial(int tecla, int x, int y);
    void movimientoMouse(int x, int y);
    
    // Variables de estado
    extern int mouseX, mouseY;
    extern bool mousePresionado;
    extern int nodoSeleccionado;
    
    // Funciones de utilidad
    int detectarNodoCercano(int x, int y);
    void establecerNodoSeleccionado(int id);
    int obtenerNodoSeleccionado();
    
    // Modos de interacción
    enum ModoInteraccion {
        SELECCION,
        AGREGAR_NODO,
        AGREGAR_ARISTA,
        ELIMINAR
    };
    
    extern ModoInteraccion modoActual;
    void establecerModo(ModoInteraccion modo);
    ModoInteraccion obtenerModo();
}

#endif