#!/bin/bash

echo "=== REPORTE FINAL DE ESCALABILIDAD AED ==="
echo "Fecha: $(date)"
echo "Límite MAX_NODOS: 10000"
echo ""

datasets=("malla_20:20" "malla_100:100" "malla_400:400" "malla_1k:1000" "malla_5k:5000")

echo "┌─────────────┬───────────┬────────────┬─────────────┬──────────────┬───────────┐"
echo "│ Dataset     │ Puntos    │ Triangulos │ Archivo CSV │ Tiempo (est) │ Estado    │"
echo "├─────────────┼───────────┼────────────┼─────────────┼──────────────┼───────────┤"

for entry in "${datasets[@]}"; do
    dataset=$(echo $entry | cut -d: -f1)
    expected_points=$(echo $entry | cut -d: -f2)
    
    csv_file="data/${dataset}.csv"
    if [ ! -f "$csv_file" ]; then
        printf "│ %-11s │ %-9s │ %-10s │ %-11s │ %-12s │ %-9s │\n" \
               "$dataset" "ERROR" "-" "FALTANTE" "-" "✗ FALLO"
        continue
    fi
    
    # Obtener tamaño del archivo
    size=$(du -h "$csv_file" | cut -f1)
    
    # Medir tiempo y ejecutar triangulación
    start_time=$(date +%s.%N)
    output=$(timeout 60s bash -c "echo -e '4\n0' | ./aed --data $dataset --no-gui" 2>/dev/null)
    end_time=$(date +%s.%N)
    exit_code=$?
    
    # Calcular tiempo transcurrido
    time_taken=$(echo "$end_time - $start_time" | bc 2>/dev/null || echo "?")
    if [[ "$time_taken" =~ ^[0-9]+\.[0-9]+$ ]]; then
        time_str=$(printf "%.2fs" "$time_taken")
    else
        time_str="?"
    fi
    
    if [ $exit_code -eq 0 ]; then
        # Extraer estadísticas
        points_loaded=$(echo "$output" | grep "Número de nodos cargados:" | sed 's/.*: //')
        triangles=$(echo "$output" | grep -o "Triángulos generados: [0-9]*" | sed 's/.*: //')
        
        if [ -n "$triangles" ] && [ "$points_loaded" = "$expected_points" ]; then
            status="✓ OK"
        elif [ -n "$triangles" ]; then
            status="⚠ Parcial"
        else
            status="⚠ Sin Δ"
            triangles="-"
        fi
        
        if [ -z "$points_loaded" ]; then
            points_loaded="?"
        fi
    elif [ $exit_code -eq 124 ]; then
        points_loaded="TIMEOUT"
        triangles="TIMEOUT"
        status="⚠ >60s"
        time_str=">60s"
    else
        points_loaded="ERROR"
        triangles="ERROR"
        status="✗ FALLO"
    fi
    
    printf "│ %-11s │ %-9s │ %-10s │ %-11s │ %-12s │ %-9s │\n" \
           "$dataset" "$points_loaded" "$triangles" "$size" "$time_str" "$status"
done

echo "└─────────────┴───────────┴────────────┴─────────────┴──────────────┴───────────┘"
echo ""
echo "=== ANÁLISIS DE ESCALABILIDAD ==="
echo "✓ OK:      Triangulación completa y exitosa"
echo "⚠ Parcial: Triangulación exitosa pero puntos cargados ≠ esperados"  
echo "⚠ Sin Δ:  Sin triangulación generada"
echo "⚠ >60s:   Timeout después de 60 segundos"
echo "✗ FALLO:  Error en ejecución"
echo ""
echo "Δ = Triángulos"
