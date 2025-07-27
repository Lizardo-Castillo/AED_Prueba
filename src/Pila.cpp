#include "Pila.h"

// Implementaciones de métodos de la plantilla Pila

template<typename T>
Pila<T>::Pila() : tope(nullptr), size_(0) {}

template<typename T>
Pila<T>::~Pila() {
    while (!empty()) {
        pop();
    }
}

template<typename T>
Pila<T>::Pila(const Pila<T>& other) : tope(nullptr), size_(0) {
    // Usamos una pila temporal para mantener el orden
    Pila<T> temp;
    NodoPila<T>* actual = other.tope;
    
    // Primero invertimos en temp
    while (actual != nullptr) {
        temp.push(actual->data);
        actual = actual->next;
    }
    
    // Luego copiamos de temp a this (restaurando orden original)
    while (!temp.empty()) {
        push(temp.top());
        temp.pop();
    }
}

template<typename T>
Pila<T>& Pila<T>::operator=(const Pila<T>& other) {
    if (this != &other) {
        // Limpiar pila actual
        while (!empty()) {
            pop();
        }
        
        // Copiar elementos manteniendo orden
        Pila<T> temp;
        NodoPila<T>* actual = other.tope;
        
        while (actual != nullptr) {
            temp.push(actual->data);
            actual = actual->next;
        }
        
        while (!temp.empty()) {
            push(temp.top());
            temp.pop();
        }
    }
    return *this;
}

template<typename T>
void Pila<T>::push(const T& elemento) {
    NodoPila<T>* nuevo = new NodoPila<T>(elemento);
    nuevo->next = tope;
    tope = nuevo;
    size_++;
}

template<typename T>
void Pila<T>::pop() {
    if (!empty()) {
        NodoPila<T>* temp = tope;
        tope = tope->next;
        delete temp;
        size_--;
    }
}

template<typename T>
T& Pila<T>::top() {
    return tope->data;
}

template<typename T>
const T& Pila<T>::top() const {
    return tope->data;
}

template<typename T>
bool Pila<T>::empty() const {
    return tope == nullptr;
}

template<typename T>
int Pila<T>::size() const {
    return size_;
}

// Instanciaciones explícitas para tipos comunes
template class Pila<int>;
template class Pila<double>;
template class Pila<float>;
template class Pila<char>;
template class Pila<bool>;
