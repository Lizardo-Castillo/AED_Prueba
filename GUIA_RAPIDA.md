# 🚀 GUÍA RÁPIDA - AED Proyecto

## ⚡ **INICIO RÁPIDO (30 segundos)**

```bash
# 1. Compilar
make

# 2. Ejecutar interfaz gráfica
./aed

# 3. Usar:
# - Click IZQUIERDO en nodo → Verde (origen)
# - Click DERECHO en nodo → Rojo (destino)  
# - Tecla "3" → Dijkstra (ruta azul automática)
# - Tecla "1" → BFS (ruta diferente)
# - Tecla "R" → Reset
```

## 🎯 **CONTROLES PRINCIPALES**

| Acción | Control | Resultado |
|--------|---------|-----------|
| 🟢 **Seleccionar ORIGEN** | `Click IZQUIERDO` | Nodo verde |
| 🔴 **Seleccionar DESTINO** | `Click DERECHO` | Nodo rojo |
| 🔍 **BFS** | `Tecla 1` | Ruta menos saltos |
| 🔍 **Dijkstra** | `Tecla 3` | Ruta más corta |
| 🔍 **A*** | `Tecla 4` | Ruta eficiente |
| 🔄 **Reset** | `Tecla R` | Limpiar todo |
| ❌ **Salir** | `ESC` | Cerrar |

## 🧪 **MODOS DE EJECUCIÓN**

```bash
# Interfaz gráfica (RECOMENDADO)
./aed

# Modo consola
./aed --no-gui

# Tests automáticos
./aed --test

# Pruebas de escalabilidad
make aed_escalabilidad
./aed_escalabilidad
```

## 🗺️ **LUGARES DISPONIBLES (Arequipa)**

1. **Plaza de Armas** - Centro histórico
2. **Monasterio Santa Catalina** - Patrimonio
3. **Mercado San Camilo** - Comercial
4. **Universidad San Agustín** - Educativo
5. **Cerro Sachaca** - Mirador
6. **Yanahuara** - Turístico
7. **Cayma** - Residencial
8. **Paucarpata** - Industrial
9. **Cerrillos** - Periférico
10. **Mollebaya** - Rural
... **y 10 más**

## 🔬 **ALGORITMOS DISPONIBLES**

- **1️⃣ BFS**: Menor número de nodos
- **2️⃣ DFS**: Exploración profunda  
- **3️⃣ Dijkstra**: Distancia mínima
- **4️⃣ A***: Heurística optimizada
- **5️⃣ Best First**: Búsqueda rápida

## ✅ **VERIFICAR FUNCIONAMIENTO**

### **Test básico:**
```bash
./aed --test
```
**Debe mostrar:** ✅ Tests de algoritmos, estructuras, CSV

### **Test visual:**
```bash
./aed
```
**Debe mostrar:** Ventana gráfica con 20 nodos grises conectados

### **Test interactivo:**
1. Click izquierdo en nodo → Verde ✅
2. Click derecho en otro nodo → Rojo ✅  
3. Tecla "1" → Ruta azul BFS ✅
4. Tecla "3" → Ruta azul Dijkstra (puede ser diferente) ✅

## 🆘 **PROBLEMAS COMUNES**

### **Error de compilación:**
```bash
sudo apt-get install freeglut3-dev libgl1-mesa-dev
make clean && make
```

### **No aparece ventana gráfica:**
```bash
# Probar modo consola
./aed --no-gui
```

### **Archivo CSV no encontrado:**
```bash
# El programa crea datos automáticamente
# Verificar que existe: ls data/arequipa_puntos.csv
```

## 🏆 **DEMOSTRACIÓN COMPLETA**

### **Para mostrar TODO el proyecto:**

1. **Compilación:** `make` ✅
2. **Carga de datos:** Automática desde CSV ✅
3. **Interfaz gráfica:** `./aed` ✅
4. **Algoritmos:** Teclas 1-5 ✅
5. **Visualización:** Rutas azules reales ✅
6. **Tests:** `./aed --test` ✅
7. **Escalabilidad:** `./aed_escalabilidad` ✅

### **Resultados esperados:**
- ✅ 20 nodos de Arequipa cargados
- ✅ Conexiones automáticas entre nodos
- ✅ 5 algoritmos funcionando diferentes
- ✅ Rutas siguiendo conexiones reales
- ✅ Métricas en consola (tiempo, nodos, distancia)
- ✅ Interfaz interactiva responsiva

---

**🎯 OBJETIVO:** Demostrar algoritmos de búsqueda REALES con interfaz interactiva funcional.
