#ifndef NODO_H
#define NODO_H

#define MAX_VECINOS 10
#define MAX_NOMBRE 50

struct Vecino {
    int id;
    float distancia;
    Vecino* siguiente;
};

class Nodo {
private:
    int id;
    char nombre[MAX_NOMBRE];
    float x;
    float y;
    Vecino* vecinos;

public:
    Nodo();
    Nodo(int _id, const char* _nombre, float _x, float _y);
    ~Nodo();

    int getId();
    const char* getNombre();
    float getX();
    float getY();
    Vecino* getVecinos();

    void agregarVecino(int idVecino, float distancia);
    void imprimirVecinos();
};

#endif
