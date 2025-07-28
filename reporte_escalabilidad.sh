#!/bin/bash

echo "=== REPORTE COMPLETO DE ESCALABILIDAD ==="
echo "Fecha: $(date)"
echo ""

datasets=("malla_20" "malla_100" "malla_400" "malla_1k" "malla_5k")

echo "| Dataset  | Archivo CSV | Nodos CSV | Nodos Cargados | Triángulos | Estado |"
echo "|----------|-------------|-----------|----------------|------------|--------|"

for dataset in "${datasets[@]}"; do
    csv_file="data/${dataset}.csv"
    
    if [ ! -f "$csv_file" ]; then
        echo "| $dataset | FALTANTE | - | - | - | ERROR |"
        continue
    fi
    
    # Contar líneas del CSV (excluyendo header)
    csv_lines=$(($(wc -l < "$csv_file") - 1))
    
    # Ejecutar el programa y capturar salida
    output=$(timeout 20s bash -c "echo -e '4\n0' | ./aed --data $dataset --no-gui" 2>/dev/null)
    
    if [ $? -eq 0 ]; then
        # Extraer nodos cargados
        nodos_cargados=$(echo "$output" | grep "Número de nodos cargados:" | sed 's/.*: //')
        
        # Extraer triángulos generados
        triangulos=$(echo "$output" | grep "Triángulos generados:" | tail -1 | sed 's/.*: //')
        
        if [ -n "$triangulos" ]; then
            status="✓ OK"
        else
            status="⚠ Sin triangulación"
            triangulos="-"
        fi
        
        if [ -z "$nodos_cargados" ]; then
            nodos_cargados="?"
        fi
    else
        nodos_cargados="ERROR"
        triangulos="ERROR"
        status="✗ FALLO"
    fi
    
    printf "| %-8s | %-11s | %-9s | %-14s | %-10s | %-6s |\n" \
           "$dataset" "$(basename $csv_file)" "$csv_lines" "$nodos_cargados" "$triangulos" "$status"
done

echo ""
echo "=== INFORMACIÓN DE ARCHIVOS ==="
echo "Tamaños de archivos:"
ls -lh data/malla_*.csv | awk '{printf "%-15s %8s\n", $9, $5}'

echo ""
echo "=== NOTAS ==="
echo "- CSV Lines: Número de líneas en el archivo CSV (sin contar header)"
echo "- Nodos Cargados: Número de nodos que el programa realmente carga"
echo "- Si 'Nodos Cargados' < 'CSV Lines', hay nodos duplicados o filtrados"
