#ifndef TRIANGLE_WRAPPER_H
#define TRIANGLE_WRAPPER_H

#include "triangle.h"

// Wrapper C++ para la función triangulate
extern "C" {
    void triangulate(char *triswitches, struct triangulateio *in,
                     struct triangulateio *out, struct triangulateio *vorout);
}

// Función wrapper para uso en C++
void ejecutarTriangulacion(char *switches, struct triangulateio *in,
                          struct triangulateio *out, struct triangulateio *vorout);

#endif
