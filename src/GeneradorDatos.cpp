#include "GeneradorDatos.h"
#include <cmath>

void GeneradorDatos::generarMapaSintetico(int numNodos, double ancho, double alto, double obstaculos, const char* archivo) {
    std::ofstream file(archivo);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo crear el archivo " << archivo << std::endl;
        return;
    }
    
    // Header CSV
    file << "id,nombre,x,y,tipo\n";
    
    int nodosGenerados = 0;
    int intentos = 0;
    const int maxIntentos = numNodos * 2; // Evitar bucle infinito
    
    std::cout << "Generando mapa sintético con " << numNodos << " nodos..." << std::endl;
    
    while (nodosGenerados < numNodos && intentos < maxIntentos) {
        double x = numeroAleatorio(-ancho/2, ancho/2);
        double y = numeroAleatorio(-alto/2, alto/2);
        
        // Verificar si es obstáculo
        if (!esObstaculo(obstaculos)) {
            file << nodosGenerados + 1 << ",Nodo_" << nodosGenerados + 1 
                 << "," << x << "," << y << ",sintético\n";
            nodosGenerados++;
            
            if (nodosGenerados % 100000 == 0) {
                std::cout << "Progreso: " << nodosGenerados << "/" << numNodos << " nodos generados" << std::endl;
            }
        }
        intentos++;
    }
    
    file.close();
    std::cout << "✓ Archivo generado: " << archivo << " con " << nodosGenerados << " nodos" << std::endl;
}

void GeneradorDatos::generarMallaRegular(int filas, int columnas, double perturbacion, const char* archivo) {
    std::ofstream file(archivo);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo crear el archivo " << archivo << std::endl;
        return;
    }
    
    // Header CSV
    file << "id,nombre,x,y,tipo\n";
    
    int nodoId = 1;
    double espaciadoX = 1.0;
    double espaciadoY = 1.0;
    
    std::cout << "Generando malla regular " << filas << "x" << columnas << "..." << std::endl;
    
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            double x = j * espaciadoX + numeroAleatorio(-perturbacion, perturbacion);
            double y = i * espaciadoY + numeroAleatorio(-perturbacion, perturbacion);
            
            file << nodoId << ",Malla_" << i << "_" << j 
                 << "," << x << "," << y << ",malla\n";
            nodoId++;
        }
        
        if (i % 100 == 0) {
            std::cout << "Progreso: " << i << "/" << filas << " filas completadas" << std::endl;
        }
    }
    
    file.close();
    std::cout << "✓ Malla generada: " << archivo << " con " << (filas * columnas) << " nodos" << std::endl;
}

void GeneradorDatos::generarDistribucionNormal(int numNodos, int numCentros, const char* archivo) {
    std::ofstream file(archivo);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo crear el archivo " << archivo << std::endl;
        return;
    }
    
    // Header CSV
    file << "id,nombre,x,y,tipo\n";
    
    // Generar centros aleatorios
    struct Centro {
        double x, y;
        int nodos;
    };
    
    Centro centros[numCentros];
    int nodosPorCentro = numNodos / numCentros;
    
    for (int i = 0; i < numCentros; i++) {
        centros[i].x = numeroAleatorio(-50.0, 50.0);
        centros[i].y = numeroAleatorio(-50.0, 50.0);
        centros[i].nodos = nodosPorCentro;
    }
    
    // Distribuir nodos restantes
    int nodosRestantes = numNodos % numCentros;
    for (int i = 0; i < nodosRestantes; i++) {
        centros[i].nodos++;
    }
    
    std::cout << "Generando distribución normal con " << numCentros << " centros..." << std::endl;
    
    int nodoId = 1;
    for (int c = 0; c < numCentros; c++) {
        std::normal_distribution<double> distX(centros[c].x, 5.0);
        std::normal_distribution<double> distY(centros[c].y, 5.0);
        
        for (int n = 0; n < centros[c].nodos; n++) {
            double x = distX(generator);
            double y = distY(generator);
            
            file << nodoId << ",Centro_" << c << "_Nodo_" << n
                 << "," << x << "," << y << ",cluster\n";
            nodoId++;
        }
        
        std::cout << "Centro " << (c+1) << "/" << numCentros << " completado (" 
                  << centros[c].nodos << " nodos)" << std::endl;
    }
    
    file.close();
    std::cout << "✓ Distribución generada: " << archivo << " con " << numNodos << " nodos" << std::endl;
}

double GeneradorDatos::numeroAleatorio(double min, double max) {
    std::uniform_real_distribution<double> dist(min, max);
    return dist(generator);
}

bool GeneradorDatos::esObstaculo(double probabilidad) {
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(generator) < probabilidad;
}
