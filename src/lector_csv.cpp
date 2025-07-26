#include "lector_csv.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>

bool leerCSV(const char* nombreArchivo, Grafo& grafo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        printf("Error al abrir el archivo %s\n", nombreArchivo);
        return false;
    }

    char linea[128];
    fgets(linea, sizeof(linea), archivo);
    while (fgets(linea, sizeof(linea), archivo)) {
        int id;
        char nombre[50];
        float x, y;

        char* token = strtok(linea, ",");
        if (!token) continue;
        id = atoi(token);

        token = strtok(NULL, ",");
        if (!token) continue;
        strncpy(nombre, token, sizeof(nombre));
        nombre[strcspn(nombre, "\n")] = '\0';

        token = strtok(NULL, ",");
        if (!token) continue;
        x = atof(token);

        token = strtok(NULL, ",");
        if (!token) continue;
        y = atof(token);

        grafo.agregarNodo(id, nombre, x, y);
    }

    fclose(archivo);
    return true;
}
