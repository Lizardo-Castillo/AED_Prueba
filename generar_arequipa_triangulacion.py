#!/usr/bin/env python3
"""
🎯 Generador de Coordenadas Optimizadas para Triangulación de Arequipa
===================================================================

Este script genera coordenadas que replican exactamente el patrón de 
triangulación mostrado en la imagen de referencia.

Características:
- 20 puntos distribuidos como en la imagen
- Evita cruces de líneas 
- Triangulación de Delaunay válida
- Distribución en forma elíptica natural
- Separación adecuada entre nodos

Autor: GitHub Copilot
Fecha: 30 de julio de 2025
"""
import math
# import matplotlib.pyplot as plt  # Comentado para evitar dependencias
# import numpy as np               # Comentado para evitar dependencias

def generar_coordenadas_triangulacion():
    """
    Genera coordenadas optimizadas basadas en la imagen de triangulación
    
    La imagen muestra:
    - Distribución roughly elíptica
    - Puntos en el perímetro marcados (A, B, C, D, E, F, P)
    - Puntos interiores bien espaciados
    - Triangulación sin cruces
    
    Returns:
        list: Lista de coordenadas (nombre, x, y)
    """
    
    # Nombres de lugares importantes de Arequipa
    nombres = [
        "Plaza de Armas",           # Centro de referencia
        "Monasterio Santa Catalina", # Cerca del centro
        "Mercado San Camilo",       # Noroeste
        "UNSA Campus",              # Sureste
        "Yanahuara",                # Oeste
        "Cayma",                    # Norte
        "Miraflores",               # Este
        "Mariano Melgar",           # Noreste
        "Paucarpata",               # Sur
        "Hunter",                   # Suroeste
        "Alto Selva Alegre",        # Norte
        "Cerro Colorado",           # Norte
        "Tiabaya",                  # Oeste lejano
        "Characato",                # Sur lejano
        "Sabandía",                 # Este lejano
        "Socabaya",                 # Sureste
        "Lambramani",               # Sur
        "Zamacola",                 # Suroeste
        "La Cantuta",               # Este
        "Centro Historico"          # Centro
    ]
    
    # Coordenadas optimizadas basadas en la imagen de triangulación
    # Siguiendo el patrón elíptico con puntos bien distribuidos
    
    coordenadas = [
        # Centro de referencia (como el punto central en la imagen)
        ("Plaza de Armas", 0.0, 0.0),
        
        # Puntos del perímetro exterior (como A, B, C, D, E, F en la imagen)
        ("Tiabaya", -4.5, 0.5),           # Extremo oeste (punto F)
        ("Sabandía", 4.2, -0.8),          # Extremo este (punto B)
        ("Cerro Colorado", -1.5, 3.8),    # Norte (punto similar a D)
        ("Characato", 2.0, -3.5),         # Sur (punto E)
        ("Cayma", -2.8, 2.5),             # Noroeste
        ("Paucarpata", 3.2, -2.2),        # Sureste
        
        # Anillo intermedio (puntos medios)
        ("Yanahuara", -2.5, 0.8),         # Oeste medio
        ("Miraflores", 2.8, 1.2),         # Este medio
        ("Alto Selva Alegre", -0.8, 2.5), # Norte medio
        ("Hunter", -1.2, -2.0),           # Suroeste medio
        ("Mariano Melgar", 1.8, 2.2),     # Noreste medio
        ("Socabaya", 2.2, -0.8),          # Sureste medio
        
        # Puntos interiores (como el área central de la imagen)
        ("Monasterio Santa Catalina", -1.0, -0.5),
        ("Mercado San Camilo", -1.5, 1.2),
        ("UNSA Campus", 1.5, -1.0),
        ("Lambramani", 0.8, -1.8),
        ("Zamacola", -1.8, -1.2),
        ("La Cantuta", 1.2, 0.8),
        ("Centro Historico", -0.3, 0.5)
    ]
    
    return coordenadas

def escribir_csv_optimizado(coordenadas, archivo):
    """Escribe las coordenadas al archivo CSV"""
    with open(archivo, 'w') as f:
        f.write("id,nombre,x,y\n")
        for i, (nombre, x, y) in enumerate(coordenadas, 1):
            f.write(f"{i},{nombre},{x:.3f},{y:.3f}\n")

def visualizar_triangulacion(coordenadas):
    """
    Información sobre los puntos generados (sin matplotlib)
    """
    print("\n📊 Información de la distribución generada:")
    print("=" * 50)
    
    # Extraer coordenadas
    x_coords = [coord[1] for coord in coordenadas]
    y_coords = [coord[2] for coord in coordenadas]
    nombres = [coord[0] for coord in coordenadas]
    
    # Mostrar información de cada punto
    print("ID | Nombre                    | X      | Y")
    print("-" * 50)
    for i, (nombre, x, y) in enumerate(coordenadas, 1):
        print(f"{i:2d} | {nombre:24s} | {x:6.3f} | {y:6.3f}")
    
    print(f"\n📈 Estadísticas:")
    print(f"   • Total de puntos: {len(coordenadas)}")
    print(f"   • Rango X: {min(x_coords):.3f} a {max(x_coords):.3f}")
    print(f"   • Rango Y: {min(y_coords):.3f} a {max(y_coords):.3f}")
    print(f"   • Área cubierta: {(max(x_coords)-min(x_coords)) * (max(y_coords)-min(y_coords)):.2f} unidades²")

def main():
    """Función principal"""
    print("🎯 Generando coordenadas optimizadas para triangulación de Arequipa...")
    print("   Basado en imagen de referencia de triangulación")
    
    # Generar coordenadas optimizadas
    coordenadas = generar_coordenadas_triangulacion()
    
    # Estadísticas
    x_coords = [coord[1] for coord in coordenadas]
    y_coords = [coord[2] for coord in coordenadas]
    
    print(f"✅ Generadas {len(coordenadas)} coordenadas")
    print(f"📊 Rango X: {min(x_coords):.1f} a {max(x_coords):.1f}")
    print(f"📊 Rango Y: {min(y_coords):.1f} a {max(y_coords):.1f}")
    
    # Verificar separación mínima
    distancia_min = float('inf')
    for i in range(len(coordenadas)):
        for j in range(i+1, len(coordenadas)):
            x1, y1 = coordenadas[i][1], coordenadas[i][2]
            x2, y2 = coordenadas[j][1], coordenadas[j][2]
            dist = math.sqrt((x2-x1)**2 + (y2-y1)**2)
            distancia_min = min(distancia_min, dist)
    
    print(f"🔍 Separación mínima entre puntos: {distancia_min:.3f}")
    
    # Escribir archivo
    archivo_salida = "data/arequipa_puntos.csv"
    escribir_csv_optimizado(coordenadas, archivo_salida)
    print(f"✅ Archivo actualizado: {archivo_salida}")
    
    # Crear visualización
    print("📊 Mostrando información de distribución...")
    visualizar_triangulacion(coordenadas)
    
    print("\n🎯 Coordenadas optimizadas para:")
    print("   • Triangulación sin cruces de líneas")
    print("   • Distribución elíptica natural")
    print("   • Separación adecuada entre nodos") 
    print("   • Visualización clara y estética")
    print("\n🚀 Listo para ejecutar con triangulación mejorada!")

if __name__ == "__main__":
    main()
