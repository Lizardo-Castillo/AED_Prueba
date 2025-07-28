# 📊 Guía de Datasets del Proyecto AED

## **Resumen Ejecutivo**
El proyecto incluye **3 datasets diferentes** para demostrar la escalabilidad y versatilidad de los algoritmos implementados:

| Dataset | Nodos | Propósito | Visualización | Comando |
|---------|-------|-----------|---------------|---------|
| **Arequipa** | 20 | Demo visual interactiva | ✅ Óptima | `./aed --data arequipa` |
| **Malla 10K** | 200* | Testing de rendimiento | ⚡ Moderada | `./aed --data malla` |
| **Distribución 50K** | 50,000 | Pruebas de límites | ⚠️ Intensiva | `./aed --data distribucion` |

*El dataset de malla carga solo los primeros 200 nodos para mantener rendimiento visual.

---

## **1. 📍 Dataset Arequipa (20 nodos)**

### **Características:**
- **Datos reales**: 20 lugares turísticos de Arequipa, Perú
- **Coordenadas**: Latitud/longitud reales
- **Visualización**: Perfecta para interface gráfica
- **Algoritmos**: Todos funcionan fluidamente

### **Lugares incluidos:**
```
Plaza de Armas, Monasterio Santa Catalina, Mercado San Camilo,
Universidad San Agustín, Cerro Sachaca, Yanahuara, Cayma,
Paucarpata, Cerrillos, Mollebaya, Characato, Sabandía,
Tiabaya, Socabaya, Alto Selva Alegre, Miraflores,
Mariano Melgar, José Luis Bustamante, Hunter, Cerro Colorado
```

### **Uso recomendado:**
```bash
# Interfaz gráfica completa
./aed --data arequipa

# Solo consola para testing
./aed --data arequipa --no-gui
```

### **Conexiones típicas:**
- Cada nodo conecta con sus 3 vecinos más cercanos
- Distancias basadas en coordenadas geográficas reales
- Red bien balanceada para demostración

---

## **2. 🌐 Dataset Malla 10K (200 nodos mostrados)**

### **Características:**
- **Distribución**: Malla regular sintética
- **Coordenadas**: Generadas algorítmicamente
- **Patrón**: Cuadrícula uniforme con variación
- **Rendimiento**: Optimizado para visualización

### **Estructura de datos:**
```csv
id,nombre,x,y,tipo
1,Malla_0_0,0.016075,-0.0341059,malla
2,Malla_0_1,0.959975,0.0347211,malla
```

### **Uso recomendado:**
```bash
# Para probar algoritmos con más nodos
./aed --data malla

# Testing sin visualización (más nodos)
./aed --data malla --no-gui
```

### **Ventajas:**
- **Distribución uniforme**: Perfecto para análisis de rendimiento
- **Conexiones predecibles**: Cada nodo tiene vecinos en patrón de cuadrícula
- **Escalabilidad**: Demuestra manejo de datasets medianos

---

## **3. 📈 Dataset Distribución 50K (50,000 nodos)**

### **Características:**
- **Volumen masivo**: 50,000 nodos para pruebas de límites
- **Distribución normal**: Algoritmo estadístico con clusters
- **Memoria intensiva**: Requiere recursos significativos
- **Solo consola**: No recomendado para GUI

### **Estructura de datos:**
```csv
id,nombre,x,y,tipo
1,Centro_0_Nodo_0,38.9187,-46.126,cluster
2,Centro_0_Nodo_1,30.4366,-47.762,cluster
```

### **Uso recomendado:**
```bash
# SOLO modo consola (GUI sería muy lento)
./aed --data distribucion --no-gui

# Testing de algoritmos específicos
./aed --data 3 --no-gui
```

### **⚠️ Advertencias:**
- **Memoria**: Puede usar 100+ MB de RAM
- **Tiempo**: Algoritmos pueden tomar varios segundos
- **GUI**: No recomendado, puede bloquear la interfaz

---

## **🎮 Comandos Rápidos**

### **Selección por nombre:**
```bash
./aed --data arequipa      # 20 nodos reales
./aed --data malla         # 200 nodos sintéticos
./aed --data distribucion  # 50K nodos (solo consola)
```

### **Selección por número:**
```bash
./aed --data 1    # Arequipa
./aed --data 2    # Malla
./aed --data 3    # Distribución
```

### **Con opciones adicionales:**
```bash
./aed --data arequipa --test     # Arequipa + pruebas automáticas
./aed --data malla --no-gui      # Malla sin interfaz gráfica
./aed --data 3 --no-gui         # Distribución modo consola
```

---

## **📊 Comparación de Rendimiento**

| Algoritmo | Arequipa (20) | Malla (200) | Distribución (50K) |
|-----------|---------------|-------------|-------------------|
| **BFS** | < 1ms | 5-15ms | 100-500ms |
| **DFS** | < 1ms | 3-10ms | 50-300ms |
| **Dijkstra** | 1-2ms | 20-50ms | 1-5 segundos |
| **A*** | 1-2ms | 15-40ms | 500ms-3s |
| **Best First** | < 1ms | 10-30ms | 200ms-1s |

---

## **🎯 Recomendaciones de Uso**

### **Para Demostración:**
- **Usa Arequipa**: Visualización clara, todos los algoritmos visibles
- **Interface gráfica**: Interacción con mouse y teclado

### **Para Testing de Rendimiento:**
- **Usa Malla**: Volumen medio, patrones predecibles
- **Modo consola**: Medición precisa de tiempos

### **Para Pruebas de Límites:**
- **Usa Distribución**: Volumen real, casos extremos
- **Solo consola**: Evitar bloqueos de GUI

### **Para Desarrollo:**
- **Empieza con Arequipa**: Debug visual fácil
- **Escala a Malla**: Validación de algoritmos
- **Finaliza con Distribución**: Pruebas de estrés

---

## **🔧 Solución de Problemas**

### **Si el programa se cuelga:**
```bash
# Reducir dataset o usar modo consola
./aed --data arequipa --no-gui
```

### **Si los algoritmos son muy lentos:**
```bash
# Usar dataset más pequeño
./aed --data 1  # Arequipa es el más rápido
```

### **Para comparar rendimiento:**
```bash
# Modo test automático
./aed --data malla --test
```

---

## **📁 Archivos de Dataset**

```
data/
├── arequipa_puntos.csv    # 20 nodos reales (655 bytes)
├── malla_10k.csv          # 10K nodos sintéticos (385 KB)
└── distribucion_50k.csv   # 50K nodos distribuidos (2.4 MB)
```

¡Ahora puedes explorar diferentes escalas de datos con el mismo proyecto! 🚀
