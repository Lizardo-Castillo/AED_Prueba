# 🎮 INTERFAZ GRÁFICA INTERACTIVA

## ✨ Nueva Funcionalidad Implementada

¡Tu proyecto ahora incluye una **interfaz gráfica completamente interactiva** con **algoritmos de búsqueda REALES** que encuentran rutas a través del grafo!

## 🚀 Cómo Usar

### 1. Ejecutar el Programa
```bash
make run
# o
./aed
```

### 2. Controles de Ratón 🖱️

| Acción | Control | Resultado |
|--------|---------|-----------|
| **Seleccionar nodo INICIAL (A)** | `Click IZQUIERDO` | Nodo se vuelve **VERDE** |
| **Seleccionar nodo DESTINO (B)** | `Click DERECHO` | Nodo se vuelve **ROJO** |

### 3. Controles de Teclado ⌨️

| Tecla | Algoritmo | Descripción |
|-------|-----------|-------------|
| `1` | **BFS** | Breadth-First Search - Encuentra ruta más corta (nodos) |
| `2` | **DFS** | Depth-First Search - Explora profundidad primero |
| `3` | **Dijkstra** | Camino más corto - Distancia euclidiana óptima |
| `4` | **A*** | Búsqueda heurística - Más eficiente que Dijkstra |
| `5` | **Best First** | Búsqueda voraz - Solo usa heurística |
| `R` | **Reset** | Reiniciar selección |
| `H` | **Ayuda** | Mostrar controles |
| `ESC` | **Salir** | Cerrar programa |

## 🎯 Flujo de Uso

1. **🟢 Paso 1**: Click izquierdo en cualquier nodo → Se marca como **ORIGEN** (verde)
2. **🔴 Paso 2**: Click derecho en otro nodo → Se marca como **DESTINO** (rojo)  
3. **🔍 Paso 3**: Presiona una tecla (1-5) para elegir algoritmo
4. **🔵 Paso 4**: ¡La ruta **REAL** aparece en **AZUL** siguiendo las conexiones del grafo!

## 🎨 Colores del Sistema

- **🔘 Gris claro**: Nodos normales
- **🟢 Verde**: Nodo inicial/origen seleccionado
- **🔴 Rojo**: Nodo destino seleccionado  
- **🔵 Azul**: Ruta encontrada **siguiendo las aristas del grafo**
- **🔵 Azul claro**: Nodos intermedios de la ruta
- **⚫ Gris oscuro**: Conexiones normales entre nodos

## 📊 Información en Consola

Al ejecutar una búsqueda verás:
```
✅ BFS encontró ruta de Plaza de Armas a Cerro Colorado
   📏 Longitud: 5 nodos
   ⏱️  Tiempo: 0.003 ms
   📐 Distancia: 0.086 unidades
   🔍 Nodos visitados: 12
```

## 🔄 Comparación de Algoritmos **REALES**

Ahora puedes comparar algoritmos que **realmente buscan** en el grafo:
1. Selecciona nodos A y B
2. Prueba algoritmo 1 (BFS) - **Encuentra ruta más corta en número de nodos**
3. Prueba algoritmo 3 (Dijkstra) - **Encuentra ruta óptima en distancia**  
4. Prueba algoritmo 4 (A*) - **Más eficiente, misma ruta que Dijkstra**
5. Compara visualmente las **diferentes rutas**

## 🧠 Diferencias entre Algoritmos

- **BFS**: Garantiza la ruta con **menor número de nodos**
- **DFS**: Puede encontrar rutas más largas, explora profundidad
- **Dijkstra**: Garantiza la ruta con **menor distancia total**
- **A***: Como Dijkstra pero **más eficiente** (menos nodos visitados)
- **Best First**: Más rápido pero **no garantiza ruta óptima**

## 🎮 Características Avanzadas

- **Algoritmos reales**: Implementados desde cero, sin STL
- **Búsqueda real**: Siguen las conexiones del grafo
- **Rutas diferentes**: Cada algoritmo puede encontrar caminos distintos
- **Métricas precisas**: Tiempo real, nodos visitados, distancia exacta
- **Visualización correcta**: Las rutas siguen las aristas del grafo
- **Detección precisa**: Área de selección optimizada para nodos cercanos
- **Reset rápido**: Tecla R para limpiar y empezar de nuevo

## 🏗️ Implementación Técnica

- **BFS**: Cola para exploración por amplitud
- **DFS**: Pila (Array) para exploración por profundidad  
- **Dijkstra**: Array de distancias, selección de mínimo
- **A***: Función heurística + costo real (f = g + h)
- **Best First**: Solo heurística euclidiana al objetivo
- **Estructuras propias**: Cola, Array, sin STL
- **Métricas reales**: chrono para medición de tiempo

## ✅ **CORRECCIONES IMPLEMENTADAS**

1. **✅ Rutas reales**: Los algoritmos ahora buscan rutas **reales** siguiendo las aristas
2. **✅ Caminos diferentes**: Cada algoritmo puede encontrar rutas diferentes
3. **✅ Visualización correcta**: Las rutas azules siguen las conexiones del grafo
4. **✅ No más líneas directas**: Se acabaron los saltos directos entre nodos
5. **✅ Algoritmos funcionales**: Implementación completa de todos los algoritmos

## 🎉 ¡Disfruta!

Ahora tienes algoritmos de búsqueda **completamente funcionales** para:
- ✅ Entender cómo funcionan **realmente** los algoritmos
- ✅ Comparar rendimiento y rutas **diferentes** visualmente  
- ✅ Demostrar el proyecto con **algoritmos reales**
- ✅ Experimentar con **diferentes estrategias** de búsqueda
