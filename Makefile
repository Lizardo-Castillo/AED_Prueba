CXX = g++
CXXFLAGS = -Wall -std=c++11 -Iinclude
LDFLAGS = -lGL -lGLU -lglut -lm

SRCDIR = src
OBJDIR = obj

SOURCES = $(filter-out $(SRCDIR)/pruebas_escalabilidad.cpp, $(wildcard $(SRCDIR)/*.cpp)) $(SRCDIR)/triangle.c
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
OBJECTS := $(OBJECTS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

TARGET = aed

all: $(OBJDIR) $(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/triangle.o: $(SRCDIR)/triangle.c
	gcc -DTRILIBRARY -Iinclude -c $< -o $@

clean:
	rm -rf $(OBJDIR) $(TARGET).PHONY: all clean
