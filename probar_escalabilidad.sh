#!/bin/bash
"""
Script para probar todos los datasets de escalabilidad
Genera reportes de triangulación y rendimiento
"""

echo "=== PRUEBAS DE ESCALABILIDAD AED ==="
echo "Comparando rendimiento de triangulación en diferentes escalas"
echo "================================================================"

# Array de datasets a probar
datasets=("malla_20" "malla_100" "malla_400" "malla_1k" "malla_5k")
descriptions=("20 puntos" "100 puntos" "400 puntos" "1K puntos" "5K puntos")

# Archivo de reporte
REPORTE="reporte_escalabilidad.txt"
echo "REPORTE DE ESCALABILIDAD - $(date)" > $REPORTE
echo "=============================================" >> $REPORTE

echo -e "\n🔬 INICIANDO PRUEBAS AUTOMÁTICAS..."

for i in "${!datasets[@]}"; do
    dataset="${datasets[i]}"
    description="${descriptions[i]}"
    
    echo -e "\n📊 Probando dataset: $description ($dataset)"
    echo "---------------------------------------------------"
    
    # Añadir al reporte
    echo -e "\n=== DATASET: $description ===" >> $REPORTE
    
    # Probar triangulación (opción 4 del menú)
    echo "Ejecutando triangulación..."
    timeout 30s bash -c "echo '4' | ./aed --data $dataset --no-gui" >> $REPORTE 2>&1
    
    if [ $? -eq 0 ]; then
        echo "✅ $description - Triangulación completada"
    else
        echo "❌ $description - Error o timeout"
        echo "ERROR: Timeout o fallo en $dataset" >> $REPORTE
    fi
    
    echo "---------------------------------------------------" >> $REPORTE
done

echo -e "\n🎉 PRUEBAS COMPLETADAS"
echo "📄 Reporte generado en: $REPORTE"

# Extraer estadísticas clave del reporte
echo -e "\n📈 RESUMEN RÁPIDO:"
echo "=================="

for i in "${!datasets[@]}"; do
    dataset="${datasets[i]}"
    description="${descriptions[i]}"
    
    # Extraer número de triángulos del reporte
    triangulos=$(grep -A 5 "=== DATASET: $description ===" $REPORTE | grep "Triángulos generados:" | grep -o '[0-9]\+' | head -1)
    
    if [ ! -z "$triangulos" ]; then
        echo "📐 $description: $triangulos triángulos"
    else
        echo "⚠️  $description: No se pudo obtener información"
    fi
done

echo -e "\n💡 Para ver detalles completos:"
echo "   cat $REPORTE"

echo -e "\n🖥️  Para probar visualmente cada dataset:"
echo "   ./aed --data malla_20    # 20 puntos"
echo "   ./aed --data malla_100   # 100 puntos"
echo "   ./aed --data malla_400   # 400 puntos" 
echo "   ./aed --data malla_1k    # 1K puntos"
echo "   ./aed --data malla_5k    # 5K puntos"
