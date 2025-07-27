#ifndef GENERADOR_DATOS_H
#define GENERADOR_DATOS_H

#include <iostream>
#include <fstream>
#include <random>
#include <chrono>

/**
 * Generador de datos sintéticos para la Parte II del proyecto
 * Crea grafos grandes (~2M nodos) para pruebas de escalabilidad
 */
class GeneradorDatos {
private:
    std::mt19937 generator;
    
public:
    GeneradorDatos() : generator(std::chrono::steady_clock::now().time_since_epoch().count()) {}
    
    /**
     * Genera un mapa sintético con obstáculos
     * @param numNodos Número de nodos a generar (ej. 2000000)
     * @param ancho Ancho del mapa en unidades
     * @param alto Alto del mapa en unidades
     * @param obstaculos Porcentaje de obstáculos (0.0 - 1.0)
     * @param archivo Nombre del archivo de salida
     */
    void generarMapaSintetico(int numNodos, double ancho, double alto, double obstaculos, const char* archivo);
    
    /**
     * Genera una malla regular con perturbaciones
     * @param filas Número de filas de la malla
     * @param columnas Número de columnas de la malla
     * @param perturbacion Factor de perturbación aleatoria
     * @param archivo Nombre del archivo de salida
     */
    void generarMallaRegular(int filas, int columnas, double perturbacion, const char* archivo);
    
    /**
     * Genera nodos con distribución normal alrededor de centros
     * @param numNodos Total de nodos
     * @param numCentros Número de centros de población
     * @param archivo Nombre del archivo de salida
     */
    void generarDistribucionNormal(int numNodos, int numCentros, const char* archivo);
    
private:
    double numeroAleatorio(double min, double max);
    bool esObstaculo(double probabilidad);
};

#endif // GENERADOR_DATOS_H
