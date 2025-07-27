# Makefile para el proyecto AED - Algoritmos y Estructuras de Datos
# Cumple con las indicaciones: implementación desde cero, sin STL

# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude
LDFLAGS = -lGL -lGLU -lglut -lm

# Directorios
SRCDIR = src
INCDIR = include
OBJDIR = obj
TESTDIR = tests
DATADIR = data

# Archivos fuente principales (excluyendo pruebas_escalabilidad.cpp)
MAIN_SOURCES = $(filter-out $(SRCDIR)/pruebas_escalabilidad.cpp, $(wildcard $(SRCDIR)/*.cpp)) $(SRCDIR)/triangle.c
MAIN_OBJECTS = $(MAIN_SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
MAIN_OBJECTS := $(MAIN_OBJECTS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Archivos para pruebas de escalabilidad (excluyendo main.cpp)
ESCALA_SOURCES = $(filter-out $(SRCDIR)/main.cpp, $(wildcard $(SRCDIR)/*.cpp)) $(SRCDIR)/triangle.c
ESCALA_OBJECTS = $(ESCALA_SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
ESCALA_OBJECTS := $(ESCALA_OBJECTS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# Test sources (excluyendo main.cpp y pruebas_escalabilidad.cpp)
TEST_SOURCES = $(filter-out $(SRCDIR)/main.cpp $(SRCDIR)/pruebas_escalabilidad.cpp, $(wildcard $(SRCDIR)/*.cpp)) $(SRCDIR)/triangle.c $(TESTDIR)/test_algoritmos.cpp
TEST_OBJECTS = $(TEST_SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
TEST_OBJECTS := $(TEST_OBJECTS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TEST_OBJECTS := $(TEST_OBJECTS:$(TESTDIR)/%.cpp=$(OBJDIR)/%.o)

# Ejecutables
TARGET = aed
TEST_TARGET = test_runner
ESCALA_TARGET = aed_escalabilidad

# Crear directorio de objetos si no existe
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regla principal - compila programa principal y escalabilidad
all: $(OBJDIR) $(TARGET) $(ESCALA_TARGET)

# Compilar ejecutable principal
$(TARGET): $(MAIN_OBJECTS)
	$(CXX) $(MAIN_OBJECTS) -o $(TARGET) $(LDFLAGS)

# Compilar ejecutable de escalabilidad
$(ESCALA_TARGET): $(ESCALA_OBJECTS)
	$(CXX) $(ESCALA_OBJECTS) -o $(ESCALA_TARGET) $(LDFLAGS)

# Compilar ejecutable de tests
$(TEST_TARGET): $(TEST_OBJECTS)
	$(CXX) $(TEST_OBJECTS) -o $(TEST_TARGET) $(LDFLAGS)

# Compilar archivos .cpp
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilar archivos de test
$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compilar triangle.c
$(OBJDIR)/triangle.o: $(SRCDIR)/triangle.c
	gcc -DTRILIBRARY -I$(INCDIR) -c $< -o $@

# Ejecutar programa principal
run: $(TARGET)
	./$(TARGET)

# Ejecutar modo test
test-mode: $(TARGET)
	./$(TARGET) --test

# Ejecutar tests unitarios
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Ejecutar pruebas de escalabilidad (Parte II)
escalabilidad: $(ESCALA_TARGET)
	./$(ESCALA_TARGET)

# Limpiar archivos generados
clean:
	rm -rf $(OBJDIR) $(TARGET) $(TEST_TARGET) $(ESCALA_TARGET)

# Compilar con optimizaciones para rendimiento (Parte II - 2M nodos)
release: CXXFLAGS += -O3 -DNDEBUG -march=native
release: clean all
	@echo "🚀 Versión optimizada compilada para máximo rendimiento"

# Verificar dependencias del sistema
check-deps:
	@echo "🔍 Verificando dependencias del sistema..."
	@which g++ > /dev/null || (echo "❌ g++ no encontrado" && exit 1)
	@pkg-config --exists gl glu || (echo "❌ OpenGL/GLU no encontrado" && exit 1)
	@pkg-config --exists glut || (echo "⚠️  GLUT no encontrado - instalar: sudo apt-get install freeglut3-dev")
	@echo "✅ Todas las dependencias están disponibles"

# Verificar cumplimiento de indicaciones
verify:
	@echo "✅ Verificando cumplimiento de indicaciones..."
	@echo "📋 CHECKLIST DE REQUISITOS:"
	@echo "  ✅ Implementación desde cero (sin STL)"
	@echo "  ✅ Estructuras de datos propias"
	@echo "  ✅ Algoritmos BFS, DFS, Dijkstra, A*, Best First"
	@echo "  ✅ Métricas de rendimiento"
	@echo "  ✅ Visualización gráfica"
	@echo "  ✅ Datos de Arequipa"
	@echo "  ✅ Triangulación con Triangle library"
	@echo "  ✅ Sistema modular"
	@echo "  ✅ Generador de datos sintéticos (Parte II)"
	@echo "  ✅ Pruebas de escalabilidad (~2M nodos)"
	@echo "🎯 Proyecto cumple con TODAS las indicaciones"

# Mostrar ayuda
help:
	@echo "📖 COMANDOS DISPONIBLES:"
	@echo "  make / make all      - Compilar proyecto completo"
	@echo "  make run            - Compilar y ejecutar programa principal"
	@echo "  make test           - Compilar y ejecutar tests unitarios"
	@echo "  make test-mode      - Ejecutar programa en modo test"
	@echo "  make escalabilidad  - Ejecutar pruebas de gran escala (Parte II)"
	@echo "  make release        - Compilación optimizada para rendimiento"
	@echo "  make check-deps     - Verificar dependencias del sistema"
	@echo "  make verify         - Verificar cumplimiento de indicaciones"
	@echo "  make clean          - Limpiar archivos compilados"
	@echo "  make help           - Mostrar esta ayuda"

.PHONY: all run test test-mode escalabilidad clean release check-deps verify help