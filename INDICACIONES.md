# 📍 Algoritmos y Estructura de Datos

## 🛠 Proyecto Práctico

### 🎯 Objetivo General

Diseñar e implementar desde cero un sistema de navegación basado en grafos que permita:

- Visualizar rutas sobre un mapa pequeño (ej. ciudad de Arequipa).
- Calcular rutas óptimas entre dos puntos sobre un mapa con aproximadamente 2 millones de nodos (a gran escala).

---

## 1. 📝 Descripción

El proyecto consiste en implementar un sistema de rutas tipo Google Maps usando grafos en C++.  
Se debe **priorizar eficiencia y rendimiento**.

> ⚠️ El uso de librerías externas está **permitido solo para**:
- Leer archivos (ej. CSV, JSON, binario)
- Generar la malla (Triangularización de Delaunay, Voronoi, etc.)

La estructura de grafo y los algoritmos deben implementarse **desde cero (sin STL)**.

---

## 1.1 Parte I: Visualización y búsqueda en un grafo pequeño (Arequipa)

### 🔹 Objetivo

Construir un grafo pequeño con los puntos principales de Arequipa (plazas, avenidas, universidades, etc.), visualizarlo gráficamente y permitir la búsqueda de rutas.

### 📌 Requisitos

- Implementación de grafos desde cero en C++ (**sin STL**).
- Representación mediante listas de adyacencia o matriz de adyacencia.
- Visualización con una librería gráfica.
- Implementar al menos los siguientes algoritmos de búsqueda:
  - Depth First Search (DFS)
  - Breadth First Search (BFS)
  - Dijkstra
  - Best First Search
  - A* (A estrella)

### 🔁 Funcionamiento

- **Entrada:** nodo A y nodo B (por ID, nombre o clic), selección del algoritmo de búsqueda.
- **Salida visual:** ruta óptima marcada en el grafo.

> 📚 Recursos útiles:
- [Triangulación de Delaunay 2](https://graphics.stanford.edu/courses/cs368-06-spring/handouts/Delaunay_2.pdf)
- [Triangulación de Delaunay 1](https://graphics.stanford.edu/courses/cs368-06-spring/handouts/Delaunay_1.pdf)
- [STL (prohibido)](https://cplusplus.com/)
- [OpenStreetMap](https://wiki.openstreetmap.org/wiki/Software_libraries)

---

## 1.2 Parte II: Cálculo de rutas óptimas en mapas grandes (~2M de nodos)

### 📌 Requisitos

- Grafo generado a partir de una malla sintética (con obstáculos) o un mapa real (OpenStreetMap).
- Comparar eficiencia entre los algoritmos implementados.
- Medir y reportar:
  - ⏱ Tiempo de construcción del grafo
  - 🔍 Tiempo de búsqueda
  - 📏 Tamaño de la ruta encontrada
  - 💾 Memoria usada

> Visualización de esta parte es **opcional**.

---

## 2. 📆 Etapas y Fecha Límite

El proyecto debe desarrollar al menos los siguientes pasos:

1. Creación del grafo  
2. Visualización del grafo  
3. Algoritmos de búsqueda  
4. Métricas de rendimiento  
5. Descripción de un informe final del proyecto  

### 📌 Fechas:
- **Entrega:** 31 de Julio (13:09), 2025  
- **Revisión:** 31 de Julio (13:10), 2025  

---

## 3. 📄 Informe Técnico

Se debe elaborar un informe descriptivo del proyecto práctico.  
> *(Este README puede cumplir ese rol si está bien elaborado.)*

### 🔍 Incluir:

- Identificación de los estudiantes (Nombre y CUI)
- Nombre del sistema
- Entrega en formato digital (PDF)
- Partes/Secciones importantes:
  - Explicación de la solución
  - Algoritmos usados
  - Complejidad computacional
  - Capturas de pantalla o gifs del funcionamiento
  - Métricas de rendimiento

> El informe debe ir acompañado de todos los códigos y artefactos generados.

---

## 4. 🧾 Criterios de Evaluación

- La **complejidad** e **integridad** del proyecto
- **Aplicación adecuada** de las técnicas
- **Métricas de rendimiento**
- **Entrega puntual**
- **Informe** y artefactos generados

---

## 5. ℹ️ Información Adicional

### 📦 El entregable debe estar compuesto por módulos independientes que gestionen:

- Operaciones principales de búsqueda de rutas óptimas.

### 🔧 Especificaciones Técnicas

- Implementado íntegramente en **C++ desde cero** (sin STL).
- Código **comentado** y siguiendo buenas prácticas (modularidad, reutilización).
- Uso obligatorio de **GitHub** (con commits de todos los participantes).
- Presentar evidencias del funcionamiento en el README.
- Describir la **secuencia lógica** del sistema.

---

## ✅ Recomendaciones

- Comenzar representando el grafo correctamente y probar en consola antes de usar GUI.
- Usar estructuras propias como:
  - `Array`, `Vector`, `LinkedList`
  - `MinHeap`, `PriorityQueue`
  - `Queue`, `Stack`
  - `AVLTree`, `RedBlackTree`
  - `HashTable`, `Graph`
- Probar primero con datos pequeños antes de cargar millones de nodos.
- Para la Parte I usar datos de **OpenStreetMap**, para la Parte II usar un **generador sintético**.
- Medir tiempo con `chrono` y verificar el uso de memoria.

---

> 🧠 **Nota final:** La calidad del proyecto depende no solo de que funcione, sino de cómo está diseñado, estructurado, probado y explicado.

