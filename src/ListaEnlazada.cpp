#include "ListaEnlazada.h"

// Implementaciones de métodos de la plantilla ListaEnlazada

template<typename T>
ListaEnlazada<T>::ListaEnlazada() : cabeza(nullptr), size_(0) {}

template<typename T>
ListaEnlazada<T>::~ListaEnlazada() {
    clear();
}

template<typename T>
ListaEnlazada<T>::ListaEnlazada(const ListaEnlazada<T>& other) : cabeza(nullptr), size_(0) {
    NodoLista<T>* actual = other.cabeza;
    while (actual != nullptr) {
        push_back(actual->data);
        actual = actual->next;
    }
}

template<typename T>
ListaEnlazada<T>& ListaEnlazada<T>::operator=(const ListaEnlazada<T>& other) {
    if (this != &other) {
        clear();
        NodoLista<T>* actual = other.cabeza;
        while (actual != nullptr) {
            push_back(actual->data);
            actual = actual->next;
        }
    }
    return *this;
}

template<typename T>
void ListaEnlazada<T>::push_back(const T& elemento) {
    NodoLista<T>* nuevo = new NodoLista<T>(elemento);
    
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        NodoLista<T>* actual = cabeza;
        while (actual->next != nullptr) {
            actual = actual->next;
        }
        actual->next = nuevo;
    }
    size_++;
}

template<typename T>
void ListaEnlazada<T>::push_front(const T& elemento) {
    NodoLista<T>* nuevo = new NodoLista<T>(elemento);
    nuevo->next = cabeza;
    cabeza = nuevo;
    size_++;
}

template<typename T>
void ListaEnlazada<T>::pop_back() {
    if (cabeza == nullptr) return;
    
    if (cabeza->next == nullptr) {
        delete cabeza;
        cabeza = nullptr;
    } else {
        NodoLista<T>* actual = cabeza;
        while (actual->next->next != nullptr) {
            actual = actual->next;
        }
        delete actual->next;
        actual->next = nullptr;
    }
    size_--;
}

template<typename T>
void ListaEnlazada<T>::pop_front() {
    if (cabeza != nullptr) {
        NodoLista<T>* temp = cabeza;
        cabeza = cabeza->next;
        delete temp;
        size_--;
    }
}

template<typename T>
T& ListaEnlazada<T>::front() {
    return cabeza->data;
}

template<typename T>
const T& ListaEnlazada<T>::front() const {
    return cabeza->data;
}

template<typename T>
T& ListaEnlazada<T>::back() {
    NodoLista<T>* actual = cabeza;
    while (actual->next != nullptr) {
        actual = actual->next;
    }
    return actual->data;
}

template<typename T>
const T& ListaEnlazada<T>::back() const {
    NodoLista<T>* actual = cabeza;
    while (actual->next != nullptr) {
        actual = actual->next;
    }
    return actual->data;
}

template<typename T>
bool ListaEnlazada<T>::empty() const {
    return cabeza == nullptr;
}

template<typename T>
int ListaEnlazada<T>::size() const {
    return size_;
}

template<typename T>
void ListaEnlazada<T>::clear() {
    while (cabeza != nullptr) {
        NodoLista<T>* temp = cabeza;
        cabeza = cabeza->next;
        delete temp;
    }
    size_ = 0;
}

template<typename T>
void ListaEnlazada<T>::remove(const T& valor) {
    while (cabeza != nullptr && cabeza->data == valor) {
        NodoLista<T>* temp = cabeza;
        cabeza = cabeza->next;
        delete temp;
        size_--;
    }
    
    if (cabeza != nullptr) {
        NodoLista<T>* actual = cabeza;
        while (actual->next != nullptr) {
            if (actual->next->data == valor) {
                NodoLista<T>* temp = actual->next;
                actual->next = actual->next->next;
                delete temp;
                size_--;
            } else {
                actual = actual->next;
            }
        }
    }
}

template<typename T>
typename ListaEnlazada<T>::iterator ListaEnlazada<T>::begin() {
    return iterator(cabeza);
}

template<typename T>
typename ListaEnlazada<T>::iterator ListaEnlazada<T>::end() {
    return iterator(nullptr);
}

template<typename T>
typename ListaEnlazada<T>::const_iterator ListaEnlazada<T>::begin() const {
    return const_iterator(cabeza);
}

template<typename T>
typename ListaEnlazada<T>::const_iterator ListaEnlazada<T>::end() const {
    return const_iterator(nullptr);
}

// Implementaciones de iterator
template<typename T>
ListaEnlazada<T>::iterator::iterator(NodoLista<T>* nodo) : nodo_actual(nodo) {}

template<typename T>
T& ListaEnlazada<T>::iterator::operator*() {
    return nodo_actual->data;
}

template<typename T>
typename ListaEnlazada<T>::iterator& ListaEnlazada<T>::iterator::operator++() {
    nodo_actual = nodo_actual->next;
    return *this;
}

template<typename T>
typename ListaEnlazada<T>::iterator ListaEnlazada<T>::iterator::operator++(int) {
    iterator temp = *this;
    nodo_actual = nodo_actual->next;
    return temp;
}

template<typename T>
bool ListaEnlazada<T>::iterator::operator==(const iterator& other) const {
    return nodo_actual == other.nodo_actual;
}

template<typename T>
bool ListaEnlazada<T>::iterator::operator!=(const iterator& other) const {
    return nodo_actual != other.nodo_actual;
}

// Implementaciones de const_iterator
template<typename T>
ListaEnlazada<T>::const_iterator::const_iterator(const NodoLista<T>* nodo) : nodo_actual(nodo) {}

template<typename T>
const T& ListaEnlazada<T>::const_iterator::operator*() const {
    return nodo_actual->data;
}

template<typename T>
typename ListaEnlazada<T>::const_iterator& ListaEnlazada<T>::const_iterator::operator++() {
    nodo_actual = nodo_actual->next;
    return *this;
}

template<typename T>
typename ListaEnlazada<T>::const_iterator ListaEnlazada<T>::const_iterator::operator++(int) {
    const_iterator temp = *this;
    nodo_actual = nodo_actual->next;
    return temp;
}

template<typename T>
bool ListaEnlazada<T>::const_iterator::operator==(const const_iterator& other) const {
    return nodo_actual == other.nodo_actual;
}

template<typename T>
bool ListaEnlazada<T>::const_iterator::operator!=(const const_iterator& other) const {
    return nodo_actual != other.nodo_actual;
}

// Instanciaciones explícitas para tipos comunes
template class ListaEnlazada<int>;
template class ListaEnlazada<double>;
template class ListaEnlazada<float>;
template class ListaEnlazada<char>;
template class ListaEnlazada<bool>;
