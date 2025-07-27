#ifndef INTERFAZ_GLUT_H
#define INTERFAZ_GLUT_H

#include "Grafo.h"

// Funciones para la interfaz gráfica con GLUT
namespace InterfazGLUT {
    
    // Inicialización
    void inicializar(int argc, char** argv);
    void configurarVentana(int ancho, int alto, const char* titulo);
    
    // Callbacks de dibujo
    void display();
    void reshape(int ancho, int alto);
    
    // Funciones de dibujo
    void dibujarGrafo(Grafo& grafo);
    void dibujarNodo(float x, float y, float r, float g, float b);
    void dibujarLinea(float x1, float y1, float x2, float y2);
    void dibujarTexto(float x, float y, const char* texto);
    
    // Configuración de colores
    void establecerColorFondo(float r, float g, float b);
    void establecerColorNodo(float r, float g, float b);
    void establecerColorArista(float r, float g, float b);
    
    // Control del bucle principal
    void iniciarBuclePrincipal();
}

#endif