#!/usr/bin/env python3
"""
🎯 Generador de Coordenadas Estilo Triangulación Orgánica para Arequipa
=====================================================================

Este script modifica arequipa_puntos.csv para crear una distribución similar
a la imagen de triangulación mostrada, con:
- Distribución orgánica (no cuadrícula rígida)
- Puntos bien espaciados para triangulación clara
- Cobertura completa del área de visualización
- Triángulos bien formados y visibles

Inspirado en la imagen de triangulación de Delaunay mostrada por el usuario.
"""
import random
import math

def generar_distribucion_organica():
    """
    Genera una distribución orgánica similar a la imagen de triangulación
    
    Características:
    - 20 puntos distribuidos de manera natural
    - Sin patrones rígidos de cuadrícula
    - Buena separación para triangulación visible
    - Algunos puntos en el perímetro, otros interiores
    
    Returns:
        list: Lista de tuplas (nombre, x, y) con distribución orgánica
    """
    
    # Configuración del área de visualización
    min_x, max_x = -8.0, 8.0    # Rango X balanceado
    min_y, max_y = -6.0, 6.0    # Rango Y balanceado
    
    # Nombres de lugares de Arequipa (mantenemos los originales)
    nombres = [
        "Plaza de Armas", "Monasterio Santa Catalina", "Mercado San Camilo",
        "Universidad San Agustin", "Cerro Sachaca", "Yanahuara", "Cayma",
        "Paucarpata", "Cerrillos", "Mollebaya", "Characato", "Sabandía",
        "Tiabaya", "Socabaya", "Alto Selva Alegre", "Miraflores",
        "Mariano Melgar", "José Luis Bustamante", "Hunter", "Cerro Colorado"
    ]
    
    coordenadas = []
    
    # Estrategia de distribución orgánica similar a la imagen
    
    # 1. Algunos puntos en el perímetro (borde del área)
    puntos_perimetro = [
        # Esquinas y bordes
        (-7.5, -5.5),   # Esquina inferior izquierda
        (7.2, -5.8),    # Esquina inferior derecha  
        (-7.8, 5.2),    # Esquina superior izquierda
        (7.5, 5.5),     # Esquina superior derecha
        (-7.0, 0.5),    # Borde izquierdo
        (7.3, -0.8),    # Borde derecho
        (0.2, 5.7),     # Borde superior
        (-1.5, -5.9),   # Borde inferior
    ]
    
    # 2. Puntos en zonas intermedias (distribución natural)
    puntos_intermedios = [
        (-5.2, 3.1),    (-3.8, -2.4),   (2.5, 4.2),
        (-2.1, 1.8),    (4.3, -3.1),    (-4.7, -0.9),
        (1.2, -1.5),    (5.8, 2.3),     (-1.8, -4.2),
        (3.9, 0.7),     (-0.5, 3.8),    (6.1, -1.2)
    ]
    
    # Combinar todos los puntos
    todas_coordenadas = puntos_perimetro + puntos_intermedios
    
    # Asegurar que tenemos exactamente 20 puntos
    while len(todas_coordenadas) < 20:
        # Generar puntos adicionales de manera orgánica
        x = random.uniform(min_x + 1, max_x - 1)
        y = random.uniform(min_y + 1, max_y - 1)
        
        # Verificar que no esté muy cerca de otros puntos
        muy_cerca = False
        for ex_x, ex_y in todas_coordenadas:
            distancia = math.sqrt((x - ex_x)**2 + (y - ex_y)**2)
            if distancia < 1.5:  # Distancia mínima para buena triangulación
                muy_cerca = True
                break
        
        if not muy_cerca:
            todas_coordenadas.append((x, y))
    
    # Tomar exactamente 20 puntos
    coordenadas_finales = todas_coordenadas[:20]
    
    # Combinar con nombres
    resultado = []
    for i, (x, y) in enumerate(coordenadas_finales):
        nombre = nombres[i] if i < len(nombres) else f"Punto_{i+1}"
        resultado.append((nombre, x, y))
    
    return resultado

def escribir_csv_arequipa(coordenadas, archivo_salida):
    """
    Escribe las coordenadas al archivo CSV en formato de Arequipa
    
    Args:
        coordenadas (list): Lista de tuplas (nombre, x, y)
        archivo_salida (str): Ruta del archivo CSV de salida
    """
    with open(archivo_salida, 'w') as f:
        # Header compatible con el formato original de Arequipa
        f.write("id,nombre,x,y\n")
        
        # Escribir cada punto con formato estándar
        for i, (nombre, x, y) in enumerate(coordenadas, 1):
            f.write(f"{i},{nombre},{x:.3f},{y:.3f}\n")

def main():
    """Función principal del generador"""
    print("🎯 Generando distribución orgánica para Arequipa...")
    print("   • Inspirado en imagen de triangulación de Delaunay")
    print("   • 20 puntos con distribución natural")
    print("   • Optimizado para triangulación visible")
    
    # Configurar semilla para reproducibilidad
    random.seed(42)
    
    # Generar coordenadas orgánicas
    coordenadas = generar_distribucion_organica()
    
    # Estadísticas de las coordenadas generadas
    xs = [c[1] for c in coordenadas]
    ys = [c[2] for c in coordenadas]
    min_x, max_x = min(xs), max(xs)
    min_y, max_y = min(ys), max(ys)
    
    print(f"✅ Generadas {len(coordenadas)} coordenadas")
    print(f"📊 Rango X: {min_x:.3f} a {max_x:.3f} ({max_x-min_x:.1f} unidades)")
    print(f"📊 Rango Y: {min_y:.3f} a {max_y:.3f} ({max_y-min_y:.1f} unidades)")
    print(f"📐 Distribución: Orgánica con buena separación")
    
    # Escribir archivo de salida
    archivo_salida = "/home/lizard/Documentos/Algoritmos_y_Estructuras_de_Datos/3ra_Unidad/Proyecto/AED_Prueba/data/arequipa_puntos.csv"
    escribir_csv_arequipa(coordenadas, archivo_salida)
    
    print(f"✅ Archivo actualizado: {archivo_salida}")
    print("\n🎯 Coordenadas optimizadas para:")
    print("   • Distribución orgánica similar a imagen mostrada")
    print("   • Triangulación clara y visible") 
    print("   • Separación adecuada entre puntos")
    print("   • Cobertura completa del área de visualización")
    print("\n🚀 Listo para ejecutar: ./aed --data arequipa")
    
    print("\n📍 Primeros 5 puntos generados:")
    for i, (nombre, x, y) in enumerate(coordenadas[:5], 1):
        print(f"   {i}. {nombre}: ({x:.3f}, {y:.3f})")

if __name__ == "__main__":
    main()
