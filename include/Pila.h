#ifndef PILA_H
#define PILA_H

template<typename T>
struct NodoPila {
    T data;
    NodoPila<T>* next;
    
    NodoPila(const T& valor) : data(valor), next(nullptr) {}
};

template<typename T>
class Pila {
private:
    NodoPila<T>* tope;
    int size_;

public:
    // Constructores y destructor
    Pila();
    ~Pila();
    Pila(const Pila<T>& other);
    Pila<T>& operator=(const Pila<T>& other);
    
    // Métodos principales
    void push(const T& elemento);
    void pop();
    T& top();
    const T& top() const;
    
    // Información de estado
    bool empty() const;
    int size() const;
};

#endif // PILA_H