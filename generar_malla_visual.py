#!/usr/bin/env python3
"""
🎯 Generador de Coordenadas Optimizadas para Visualización de Triangulación
===========================================================================

Este script regenera el dataset malla_10k.csv con coordenadas optimizadas para:
- Visualización clara de triangulación
- Distribución uniforme en pantalla completa  
- Separación adecuada entre puntos
- Compatibilidad con sistema de viewport dinámico

Autor: GitHub Copilot
Fecha: 28 de julio de 2025
Propósito: Mejorar experiencia visual del proyecto AED

Uso:
    python3 generar_malla_visual.py

Salida:
    - Actualiza data/malla_10k.csv con nuevas coordenadas
    - 10,000 puntos distribuidos en área rectangular
    - Rango X: -10 a +10, Rango Y: -7.5 a +7.5
    - Triangulación optimizada para ~381 triángulos
"""
import math
import random

def generar_malla_visual():
    """
    Genera una malla con distribución optimizada para visualización de triangulación
    
    Características:
    - Área rectangular 20x15 unidades (relación 4:3)
    - Distribución en cuadrícula con variación natural
    - 10,000 puntos organizados en grid 100x100
    - Separación uniforme para triángulos visibles
    
    Returns:
        list: Lista de tuplas (x, y) con coordenadas optimizadas
    """
    
    # Configuración para visualización óptima
    # Área que cubre toda la pantalla con buena relación de aspecto
    min_x, max_x = -10.0, 10.0  # Rango X de 20 unidades
    min_y, max_y = -7.5, 7.5    # Rango Y de 15 unidades (relación 4:3)
    
    # Para 10,000 puntos, crear una cuadrícula base de 100x100
    # Esto asegura distribución uniforme y triangulación exitosa
    grid_size = 100
    puntos_por_fila = grid_size
    total_filas = grid_size
    
    coordenadas = []
    
    # Generar cuadrícula base con variación aleatoria para naturalidad
    for fila in range(total_filas):
        for col in range(puntos_por_fila):
            if len(coordenadas) >= 10000:  # Limitar a exactamente 10k puntos
                break
                
            # Calcular posición base en la cuadrícula regular
            base_x = min_x + (col / (puntos_por_fila - 1)) * (max_x - min_x)
            base_y = min_y + (fila / (total_filas - 1)) * (max_y - min_y)
            
            # Añadir variación aleatoria pequeña para naturalidad
            # Esto evita patrones demasiado rígidos pero mantiene estructura
            variacion_x = random.uniform(-0.05, 0.05)
            variacion_y = random.uniform(-0.05, 0.05)
            
            x = base_x + variacion_x
            y = base_y + variacion_y
            
            coordenadas.append((x, y))
            
        if len(coordenadas) >= 10000:
            break
    
    return coordenadas[:10000]  # Asegurar exactamente 10k puntos

def escribir_csv(coordenadas, archivo_salida):
    """
    Escribe las coordenadas al archivo CSV en formato compatible
    
    Args:
        coordenadas (list): Lista de tuplas (x, y)
        archivo_salida (str): Ruta del archivo CSV de salida
    """
    with open(archivo_salida, 'w') as f:
        # Header compatible con el sistema existente
        f.write("id,nombre,x,y,tipo\n")
        
        # Escribir cada punto con formato estándar
        for i, (x, y) in enumerate(coordenadas, 1):
            # Nomenclatura: Malla_fila_columna
            nombre = f"Malla_{i//100}_{i%100}"
            f.write(f"{i},{nombre},{x:.6f},{y:.6f},malla\n")

def main():
    """Función principal del generador"""
    print("🔄 Generando coordenadas optimizadas para visualización...")
    print("   • Target: 10,000 puntos en distribución rectangular")
    print("   • Área: 20x15 unidades (relación 4:3)")
    print("   • Patrón: Cuadrícula con variación natural")
    
    # Generar coordenadas optimizadas
    coordenadas = generar_malla_visual()
    
    # Estadísticas de las coordenadas generadas
    min_x = min(c[0] for c in coordenadas)
    max_x = max(c[0] for c in coordenadas)
    min_y = min(c[1] for c in coordenadas)
    max_y = max(c[1] for c in coordenadas)
    
    print(f"✅ Generadas {len(coordenadas)} coordenadas")
    print(f"📊 Rango X: {min_x:.3f} a {max_x:.3f} ({max_x-min_x:.1f} unidades)")
    print(f"📊 Rango Y: {min_y:.3f} a {max_y:.3f} ({max_y-min_y:.1f} unidades)")
    print(f"📐 Relación de aspecto: {(max_x-min_x)/(max_y-min_y):.2f}:1")
    
    # Escribir archivo de salida
    archivo_salida = "/home/lizard/Documentos/Algoritmos_y_Estructuras_de_Datos/3ra_Unidad/Proyecto/AED_Prueba/data/malla_10k.csv"
    escribir_csv(coordenadas, archivo_salida)
    
    print(f"✅ Archivo actualizado: {archivo_salida}")
    print("\n🎯 Coordenadas optimizadas para:")
    print("   • Distribución uniforme en pantalla completa")
    print("   • Visualización clara de triangulación") 
    print("   • Separación adecuada entre puntos")
    print("   • Compatibilidad con viewport dinámico")
    print("\n🚀 Listo para ejecutar: ./aed --data malla")

if __name__ == "__main__":
    # Configurar semilla para reproducibilidad si se desea
    # random.seed(42)  # Descomentar para resultados reproducibles
    main()
