#include "Cola.h"

// Implementaciones de métodos de la plantilla Cola

template<typename T>
Cola<T>::Cola() : frente(nullptr), fin(nullptr), size_(0) {}

template<typename T>
Cola<T>::~Cola() {
    while (!empty()) {
        pop();
    }
}

template<typename T>
Cola<T>::Cola(const Cola<T>& other) : frente(nullptr), fin(nullptr), size_(0) {
    // Copiamos elemento por elemento
    NodoCola<T>* actual = other.frente;
    while (actual != nullptr) {
        push(actual->data);
        actual = actual->next;
    }
}

template<typename T>
Cola<T>& Cola<T>::operator=(const Cola<T>& other) {
    if (this != &other) {
        // Limpiar cola actual
        while (!empty()) {
            pop();
        }
        
        // Copiar elementos
        NodoCola<T>* actual = other.frente;
        while (actual != nullptr) {
            push(actual->data);
            actual = actual->next;
        }
    }
    return *this;
}

template<typename T>
void Cola<T>::push(const T& elemento) {
    NodoCola<T>* nuevo = new NodoCola<T>(elemento);
    
    if (empty()) {
        frente = fin = nuevo;
    } else {
        fin->next = nuevo;
        fin = nuevo;
    }
    size_++;
}

template<typename T>
void Cola<T>::pop() {
    if (!empty()) {
        NodoCola<T>* temp = frente;
        frente = frente->next;
        if (frente == nullptr) {
            fin = nullptr;
        }
        delete temp;
        size_--;
    }
}

template<typename T>
T& Cola<T>::front() {
    return frente->data;
}

template<typename T>
const T& Cola<T>::front() const {
    return frente->data;
}

template<typename T>
bool Cola<T>::empty() const {
    return frente == nullptr;
}

template<typename T>
int Cola<T>::size() const {
    return size_;
}

// Instanciaciones explícitas para tipos comunes
template class Cola<int>;
template class Cola<double>;
template class Cola<float>;
template class Cola<char>;
template class Cola<bool>;
