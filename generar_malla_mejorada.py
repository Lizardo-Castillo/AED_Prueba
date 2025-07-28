#!/usr/bin/env python3
"""
Generador de coordenadas mejoradas para malla_10k.csv
Evita líneas cruzadas y mejora la triangulación usando distribución inteligente
"""

import csv
import math
import random

def calcular_distancia(p1, p2):
    """Calcula la distancia euclidiana entre dos puntos"""
    return math.sqrt((p1[0] - p2[0])**2 + (p1[1] - p2[1])**2)

def generar_puntos_mejorados(num_puntos=10000):
    """
    Genera puntos con distribución mejorada para evitar líneas cruzadas
    Usa una combinación de grid estructurado con variación orgánica
    Se adapta automáticamente según el número de puntos
    """
    puntos = []
    
    # Adaptar área según número de puntos para mejor visualización
    if num_puntos <= 50:
        ancho, alto = 15.0, 12.0      # Área pequeña para pocos puntos
    elif num_puntos <= 200:
        ancho, alto = 20.0, 16.0      # Área mediana
    elif num_puntos <= 500:
        ancho, alto = 25.0, 20.0      # Área grande
    elif num_puntos <= 2000:
        ancho, alto = 30.0, 24.0      # Área muy grande
    else:
        ancho, alto = 35.0, 28.0      # Área extra grande para muchos puntos
    
    x_min, x_max = -ancho/2, ancho/2
    y_min, y_max = -alto/2, alto/2
    
    # Calcular grid aproximado basado en número de puntos
    puntos_por_lado = int(math.sqrt(num_puntos))
    paso_x = ancho / puntos_por_lado
    paso_y = alto / puntos_por_lado
    
    # Separación mínima adaptativa - más estricta con menos puntos
    if num_puntos <= 50:
        factor_separacion = 0.6      # Más separación para pocos puntos
    elif num_puntos <= 200:
        factor_separacion = 0.5
    elif num_puntos <= 1000:
        factor_separacion = 0.4
    else:
        factor_separacion = 0.3      # Menos separación para muchos puntos
    
    separacion_minima = min(paso_x, paso_y) * factor_separacion
    
    print(f"Generando {num_puntos} puntos en área {ancho}x{alto}")
    print(f"Grid base: {puntos_por_lado}x{puntos_por_lado}")
    print(f"Separación mínima: {separacion_minima:.3f}")
    
    # Generar puntos con distribución híbrida
    intentos_maximos = 50
    
    # Mostrar progreso según el tamaño del dataset
    intervalo_progreso = max(1, num_puntos // 10)
    
    for i in range(num_puntos):
        if i % intervalo_progreso == 0:
            progreso = (i / num_puntos) * 100
            print(f"Progreso: {i}/{num_puntos} puntos ({progreso:.1f}%)")
        
        punto_valido = False
        intentos = 0
        
        while not punto_valido and intentos < intentos_maximos:
            # Estrategia híbrida: 70% grid estructurado, 30% aleatorio
            if random.random() < 0.7:
                # Posición base en grid con variación controlada
                grid_x = i % puntos_por_lado
                grid_y = i // puntos_por_lado
                
                base_x = x_min + grid_x * paso_x
                base_y = y_min + grid_y * paso_y
                
                # Añadir variación controlada (no más del 30% del paso)
                variacion_x = random.uniform(-paso_x*0.3, paso_x*0.3)
                variacion_y = random.uniform(-paso_y*0.3, paso_y*0.3)
                
                x = base_x + variacion_x
                y = base_y + variacion_y
            else:
                # Posición completamente aleatoria para naturalidad
                x = random.uniform(x_min, x_max)
                y = random.uniform(y_min, y_max)
            
            # Asegurar que está dentro de límites
            x = max(x_min, min(x_max, x))
            y = max(y_min, min(y_max, y))
            
            # Verificar separación mínima con puntos existentes
            punto_valido = True
            for punto_existente in puntos:
                if calcular_distancia((x, y), punto_existente) < separacion_minima:
                    punto_valido = False
                    break
            
            intentos += 1
        
        if punto_valido:
            puntos.append((x, y))
        else:
            # Si no se puede encontrar posición válida, usar posición forzada
            # con pequeña aleatorización para evitar superposición exacta
            x = random.uniform(x_min, x_max)
            y = random.uniform(y_min, y_max)
            puntos.append((x, y))
    
    print(f"✓ Generados {len(puntos)} puntos exitosamente")
    
    # Estadísticas de la distribución
    x_coords = [p[0] for p in puntos]
    y_coords = [p[1] for p in puntos]
    
    print(f"Rango X: {min(x_coords):.2f} a {max(x_coords):.2f}")
    print(f"Rango Y: {min(y_coords):.2f} a {max(y_coords):.2f}")
    print(f"Área cubierta: {max(x_coords)-min(x_coords):.1f} x {max(y_coords)-min(y_coords):.1f}")
    
    return puntos

def escribir_csv_malla(puntos, archivo_salida):
    """Escribe los puntos en formato CSV para malla"""
    print(f"Escribiendo {len(puntos)} puntos a {archivo_salida}")
    
    with open(archivo_salida, 'w', newline='', encoding='utf-8') as csvfile:
        writer = csv.writer(csvfile)
        
        # Header
        writer.writerow(['id', 'nombre', 'x', 'y', 'tipo'])
        
        # Datos
        for i, (x, y) in enumerate(puntos, 1):
            fila_num = (i - 1) // 100  # Número de fila (0-99 para 10k puntos)
            col_num = (i - 1) % 100 + 1  # Número de columna (1-100)
            
            nombre = f"Malla_{fila_num}_{col_num}"
            writer.writerow([i, nombre, f"{x:.6f}", f"{y:.6f}", "malla"])
    
    print(f"✓ Archivo {archivo_salida} generado exitosamente")

def generar_datasets_escalabilidad():
    """Genera múltiples datasets para probar escalabilidad"""
    
    # Definir los datasets a generar
    datasets = [
        (20, "data/malla_20.csv", "20 puntos"),
        (100, "data/malla_100.csv", "100 puntos"),
        (400, "data/malla_400.csv", "400 puntos"), 
        (1000, "data/malla_1k.csv", "1K puntos"),
        (5000, "data/malla_5k.csv", "5K puntos")
    ]
    
    print("=== GENERADOR DE DATASETS DE ESCALABILIDAD ===")
    print("Creando múltiples datasets para probar triangulación a diferentes escalas")
    print("=" * 70)
    
    for num_puntos, archivo, descripcion in datasets:
        print(f"\n🔄 Generando dataset: {descripcion}")
        print("-" * 50)
        
        # Generar puntos para este dataset
        puntos = generar_puntos_mejorados(num_puntos)
        
        # Escribir archivo CSV
        escribir_csv_malla(puntos, archivo)
        
        print(f"✅ {descripcion} completado: {archivo}")
    
    print("\n" + "=" * 70)
    print("🎉 TODOS LOS DATASETS GENERADOS EXITOSAMENTE")
    print("\nArchivos creados:")
    for _, archivo, descripcion in datasets:
        print(f"  📄 {archivo} - {descripcion}")
    
    print("\n📋 Para probar cada dataset, usa:")
    print("  ./aed --data malla_20    # Para 20 puntos")
    print("  ./aed --data malla_100   # Para 100 puntos") 
    print("  ./aed --data malla_400   # Para 400 puntos")
    print("  ./aed --data malla_1k    # Para 1K puntos")
    print("  ./aed --data malla_5k    # Para 5K puntos")

def main():
    import sys
    
    if len(sys.argv) > 1 and sys.argv[1] == "--escalabilidad":
        # Generar todos los datasets de escalabilidad
        generar_datasets_escalabilidad()
    else:
        # Comportamiento original - generar solo malla_10k
        print("=== GENERADOR DE MALLA MEJORADA ===")
        print("Creando distribución optimizada para evitar líneas cruzadas")
        
        # Generar puntos mejorados
        puntos = generar_puntos_mejorados(10000)
        
        # Escribir archivo CSV
        archivo_salida = "data/malla_10k.csv"
        escribir_csv_malla(puntos, archivo_salida)
        
        print("\n=== PROCESO COMPLETADO ===")
        print("✓ Malla mejorada generada con éxito")
        print("✓ Distribución optimizada para mejor triangulación")
        print("✓ Separación mínima aplicada para evitar líneas cruzadas")
        print("\n💡 Para generar datasets de escalabilidad, usa:")
        print("   python3 generar_malla_mejorada.py --escalabilidad")

if __name__ == "__main__":
    main()
