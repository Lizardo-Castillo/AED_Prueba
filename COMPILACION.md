# 🔧 COMPILACIÓN Y EJECUCIÓN - AED Proyecto

## ⚡ **COMPILACIÓN RÁPIDA**

```bash
# Limpiar y compilar todo
make clean && make

# Compilar y ejecutar inmediatamente (RECOMENDADO)
make run

# Solo compilar
make
```

## 🧪 **MODOS DE EJECUCIÓN**

### **🎮 Modo Gráfico Interactivo (PRINCIPAL)**
```bash
./aed
```
- ✅ **Interfaz OpenGL/GLUT funcional**
- ✅ **Click izquierdo**: Seleccionar nodo origen (verde)
- ✅ **Click derecho**: Seleccionar nodo destino (rojo)
- ✅ **Teclas 1-5**: Ejecutar algoritmos (BFS, DFS, Dijkstra, A*, Best First)
- ✅ **Visualización en tiempo real**: Rutas azules reales

### **🖥️ Modo Consola**
```bash
./aed --no-gui
```
- ✅ **Menú interactivo** por consola
- ✅ **Todas las funcionalidades** disponibles sin gráficos

### **🧪 Modo Test Automático**
```bash
./aed --test
```
- ✅ **Pruebas completas** de algoritmos y estructuras
- ✅ **Verificación** de funcionamiento

### **📈 Pruebas de Escalabilidad**
```bash
make aed_escalabilidad
./aed_escalabilidad
```
- ✅ **Grafos grandes** (hasta 500K nodos)
- ✅ **Métricas de rendimiento**

### **🔍 Ayuda**
```bash
./aed --help
```

## 🛠️ **COMANDOS DEL MAKEFILE**

```bash
# Compilación básica
make                    # Compilar proyecto principal
make clean             # Limpiar archivos objeto
make clean && make     # Recompilar desde cero

# Ejecución
make run               # Compilar + ejecutar modo gráfico
make test              # Ejecutar tests unitarios
make test-mode         # Ejecutar en modo test automático

# Targets específicos
make aed               # Ejecutable principal
make aed_escalabilidad # Ejecutable de escalabilidad
make test_runner       # Ejecutable de tests

# Información
make help              # Mostrar ayuda del makefile
```

## 📋 **REQUISITOS DEL SISTEMA**

### **Ubuntu/Debian:**
```bash
sudo apt-get update
sudo apt-get install build-essential
sudo apt-get install freeglut3-dev libgl1-mesa-dev libglu1-mesa-dev
```

### **Arch Linux:**
```bash
sudo pacman -S base-devel
sudo pacman -S freeglut mesa
```

### **CentOS/RHEL:**
```bash
sudo yum groupinstall "Development Tools"
sudo yum install freeglut-devel mesa-libGL-devel mesa-libGLU-devel
```

## ✅ **VERIFICACIÓN DE COMPILACIÓN**

### **Test básico:**
```bash
make clean && make
echo $?  # Debe ser 0 (éxito)
```

### **Test funcional:**
```bash
./aed --test
# Debe mostrar: ✓ Tests completados exitosamente
```

### **Test gráfico:**
```bash
./aed &
# Debe abrir ventana con 20 nodos grises conectados
```

## 🐛 **RESOLUCIÓN DE PROBLEMAS**

### **Error: "GL/glut.h: No such file"**
```bash
sudo apt-get install freeglut3-dev
```

### **Error: "undefined reference to glut"**
```bash
# Verificar que las librerías estén instaladas
sudo apt-get install libgl1-mesa-dev libglu1-mesa-dev
```

### **Error: "Permission denied"**
```bash
chmod +x aed
./aed
```

### **Segmentation fault**
```bash
# Probar modo consola primero
./aed --no-gui

# Verificar dependencias
ldd ./aed
```

### **No aparece ventana gráfica**
```bash
# Verificar X11
echo $DISPLAY

# Si es SSH, usar X forwarding
ssh -X usuario@servidor
```

## 📊 **VERIFICACIÓN DE FUNCIONALIDAD**

### **Checklist de compilación exitosa:**
- ✅ **Compilación sin warnings**: `make` termina sin errores
- ✅ **Ejecutable generado**: `ls -la aed` muestra el archivo
- ✅ **Tests pasan**: `./aed --test` muestra resultados positivos
- ✅ **Interfaz gráfica abre**: `./aed` muestra ventana OpenGL
- ✅ **Datos cargados**: Consola muestra "20 nodos cargados"

### **Resultados esperados:**
```bash
$ make clean && make
rm -rf obj aed test_runner aed_escalabilidad
mkdir -p obj
g++ -Wall -std=c++11 -Iinclude -c src/Algoritmos.cpp -o obj/Algoritmos.o
[...compilación exitosa...]
g++ obj/*.o -o aed -lGL -lGLU -lglut -lm

$ ./aed --test
=== PROYECTO AED - ALGORITMOS Y ESTRUCTURAS DE DATOS ===
✓ Datos cargados exitosamente desde arequipa_puntos.csv
✓ Grafo conectado automáticamente
=== TODAS LAS PRUEBAS COMPLETADAS ===

$ ./aed
--- Iniciando interfaz gráfica ---
✓ Interfaz gráfica inicializada
[Ventana OpenGL se abre con 20 nodos]
```

---

**🎯 OBJETIVO**: Compilación y ejecución exitosa del proyecto AED con algoritmos reales funcionales.