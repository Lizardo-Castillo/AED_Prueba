#ifndef COLA_H
#define COLA_H

template<typename T>
struct NodoCola {
    T data;
    NodoCola<T>* next;
    
    NodoCola(const T& valor) : data(valor), next(nullptr) {}
};

template<typename T>
class Cola {
private:
    NodoCola<T>* frente;
    NodoCola<T>* fin;
    int size_;

public:
    // Constructores y destructor
    Cola();
    ~Cola();
    Cola(const Cola<T>& other);
    Cola<T>& operator=(const Cola<T>& other);
    
    // Métodos principales
    void push(const T& elemento);
    void pop();
    T& front();
    const T& front() const;
    
    // Información de estado
    bool empty() const;
    int size() const;
};

#endif // COLA_H