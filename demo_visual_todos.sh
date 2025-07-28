#!/bin/bash

echo "🎮 DEMOSTRACIÓN VISUAL DE TODOS LOS DATASETS CSV"
echo "================================================================"
echo "Este script abrirá cada dataset para que puedas ver las diferencias"
echo "de escalabilidad y distribución visual."
echo ""
echo "📋 Datasets disponibles:"
echo "  1. malla_20  - 20 puntos   (Pequeño - ideal para ver estructura)"
echo "  2. malla_100 - 100 puntos  (Mediano - buena distribución)"
echo "  3. malla_400 - 400 puntos  (Grande - densidad media)"
echo "  4. malla_1k  - 1000 puntos (Muy grande - alta densidad)"
echo "  5. malla_5k  - 5000 puntos (Enorme - máxima densidad)"
echo ""

datasets=("malla_20:20 puntos:Pequeño - Ideal para entender la estructura"
          "malla_100:100 puntos:Mediano - Buena distribución visual"
          "malla_400:400 puntos:Grande - Densidad media perfecta"
          "malla_1k:1000 puntos:Muy grande - Alta densidad"
          "malla_5k:5000 puntos:Enorme - Máxima densidad soportada")

for i in "${!datasets[@]}"; do
    IFS=':' read -r dataset puntos descripcion <<< "${datasets[$i]}"
    num=$((i + 1))
    
    echo "🔸 [$num/5] DATASET: $dataset"
    echo "    📊 Tamaño: $puntos"
    echo "    📝 Descripción: $descripcion"
    echo ""
    
    echo "    Presiona ENTER para abrir $dataset en modo gráfico..."
    read -r
    
    echo "    🚀 Iniciando visualización de $dataset..."
    echo "    💡 Controles en la ventana:"
    echo "       - Click izquierdo: Seleccionar nodos"
    echo "       - Teclas 1-4: Algoritmos de búsqueda"
    echo "       - Tecla T: Triangulación"
    echo "       - ESC: Cerrar ventana"
    echo ""
    
    # Abrir el dataset
    ./aed --data $dataset
    
    echo ""
    echo "    ✅ $dataset cerrado"
    echo "    ⏯️  Continuando con el siguiente dataset..."
    echo ""
    echo "================================================================"
    echo ""
done

echo "🎉 DEMOSTRACIÓN COMPLETADA"
echo ""
echo "📈 Resumen de lo que acabas de ver:"
echo "   • malla_20:  Estructura clara, pocos puntos, fácil de analizar"
echo "   • malla_100: Distribución equilibrada, good para tests"
echo "   • malla_400: Densidad media, triangulación más compleja"
echo "   • malla_1k:  Alta densidad, muchos triángulos"
echo "   • malla_5k:  Máxima complejidad, rendimiento límite"
echo ""
echo "💡 Cada dataset usa distribución híbrida (70% grid + 30% random)"
echo "💡 La separación entre puntos se adapta automáticamente"
echo "💡 Todos evitan líneas cruzadas en la triangulación"
echo ""
echo "🔧 Para abrir individualmente:"
echo "   ./aed --data malla_20"
echo "   ./aed --data malla_100"
echo "   ./aed --data malla_400"
echo "   ./aed --data malla_1k"
echo "   ./aed --data malla_5k"
