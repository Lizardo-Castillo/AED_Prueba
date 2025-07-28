#!/bin/bash

# Script simplificado para probar escalabilidad de datasets
echo "=== PRUEBAS DE ESCALABILIDAD - DATASETS DE MALLA ==="
echo ""

datasets=("malla_20" "malla_100" "malla_400" "malla_1k" "malla_5k")

for dataset in "${datasets[@]}"; do
    echo "--- Probando $dataset ---"
    
    # Verificar que el archivo existe
    if [ ! -f "data/${dataset}.csv" ]; then
        echo "ERROR: No se encontró data/${dataset}.csv"
        continue
    fi
    
    # Contar líneas del archivo (número de puntos)
    puntos=$(wc -l < "data/${dataset}.csv")
    echo "Puntos en dataset: $puntos"
    
    # Probar triangulación con timeout de 15 segundos
    echo "Probando triangulación..."
    timeout 15s bash -c "echo '4' | echo '0' | ./aed --data $dataset --no-gui" > /tmp/test_$dataset.log 2>&1
    
    if [ $? -eq 0 ]; then
        # Extraer información de la triangulación
        triangulos=$(grep "Triángulos generados:" /tmp/test_$dataset.log | tail -1 | cut -d' ' -f3)
        if [ -n "$triangulos" ]; then
            echo "✓ Triangulación exitosa: $triangulos triángulos"
        else
            echo "✓ Programa ejecutado (verificar log para detalles)"
        fi
    elif [ $? -eq 124 ]; then
        echo "⚠ Timeout (>15s) - posible problema de rendimiento"
    else
        echo "✗ Error en ejecución"
    fi
    
    echo ""
done

echo "=== RESUMEN DE ARCHIVOS ==="
echo "Tamaños de archivos CSV:"
ls -lh data/malla_*.csv | awk '{print $9 " - " $5}'

echo ""
echo "=== PRUEBAS COMPLETADAS ==="
