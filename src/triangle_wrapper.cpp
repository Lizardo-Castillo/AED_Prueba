#include "triangle_wrapper.h"

// Función wrapper para uso en C++
void ejecutarTriangulacion(char *switches, struct triangulateio *in,
                          struct triangulateio *out, struct triangulateio *vorout) {
    triangulate(switches, in, out, vorout);
}
