#include "MinHeap.h"

// Implementaciones de métodos de la plantilla MinHeap

template<typename T>
MinHeap<T>::MinHeap(int capacidad) : size_(0), capacity_(capacidad) {
    data_ = new T[capacidad];
}

template<typename T>
MinHeap<T>::~MinHeap() {
    delete[] data_;
}

template<typename T>
MinHeap<T>::MinHeap(const MinHeap<T>& other) : size_(other.size_), capacity_(other.capacity_) {
    data_ = new T[capacity_];
    for (int i = 0; i < size_; i++) {
        data_[i] = other.data_[i];
    }
}

template<typename T>
MinHeap<T>& MinHeap<T>::operator=(const MinHeap<T>& other) {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        data_ = new T[capacity_];
        for (int i = 0; i < size_; i++) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

template<typename T>
void MinHeap<T>::push(const T& elemento) {
    if (size_ >= capacity_) {
        resize(capacity_ * 2);
    }
    
    data_[size_] = elemento;
    int indice = size_;
    size_++;
    
    // Heapify hacia arriba
    while (indice > 0) {
        int padre = (indice - 1) / 2;
        if (data_[indice] < data_[padre]) {
            swap(data_[indice], data_[padre]);
            indice = padre;
        } else {
            break;
        }
    }
}

template<typename T>
void MinHeap<T>::pop() {
    if (empty()) return;
    
    data_[0] = data_[size_ - 1];
    size_--;
    
    if (size_ > 0) {
        heapifyDown(0);
    }
}

template<typename T>
const T& MinHeap<T>::top() const {
    return data_[0];
}

template<typename T>
bool MinHeap<T>::empty() const {
    return size_ == 0;
}

template<typename T>
int MinHeap<T>::size() const {
    return size_;
}

template<typename T>
void MinHeap<T>::heapifyDown(int indice) {
    while (true) {
        int menor = indice;
        int hijoIzq = 2 * indice + 1;
        int hijoDer = 2 * indice + 2;
        
        if (hijoIzq < size_ && data_[hijoIzq] < data_[menor]) {
            menor = hijoIzq;
        }
        
        if (hijoDer < size_ && data_[hijoDer] < data_[menor]) {
            menor = hijoDer;
        }
        
        if (menor != indice) {
            swap(data_[indice], data_[menor]);
            indice = menor;
        } else {
            break;
        }
    }
}

template<typename T>
void MinHeap<T>::resize(int nuevaCapacidad) {
    T* nuevoData = new T[nuevaCapacidad];
    for (int i = 0; i < size_; i++) {
        nuevoData[i] = data_[i];
    }
    delete[] data_;
    data_ = nuevoData;
    capacity_ = nuevaCapacidad;
}

template<typename T>
void MinHeap<T>::swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// Instanciaciones explícitas para tipos comunes
template class MinHeap<int>;
template class MinHeap<double>;
template class MinHeap<float>;
