#include "Array.h"

// Implementaciones de métodos de la plantilla Array

template<typename T>
Array<T>::Array(int capacidad) : size_(0), capacity_(capacidad) {
    data_ = new T[capacidad];
}

template<typename T>
Array<T>::~Array() {
    delete[] data_;
}

template<typename T>
Array<T>::Array(const Array<T>& other) : size_(other.size_), capacity_(other.capacity_) {
    data_ = new T[capacity_];
    for (int i = 0; i < size_; i++) {
        data_[i] = other.data_[i];
    }
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
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
void Array<T>::push_back(const T& elemento) {
    if (size_ >= capacity_) {
        resize(capacity_ * 2);
    }
    data_[size_++] = elemento;
}

template<typename T>
void Array<T>::pop_back() {
    if (size_ > 0) {
        size_--;
    }
}

template<typename T>
T& Array<T>::operator[](int indice) {
    return data_[indice];
}

template<typename T>
const T& Array<T>::operator[](int indice) const {
    return data_[indice];
}

template<typename T>
int Array<T>::size() const {
    return size_;
}

template<typename T>
bool Array<T>::empty() const {
    return size_ == 0;
}

template<typename T>
void Array<T>::clear() {
    size_ = 0;
}

template<typename T>
void Array<T>::resize(int nuevaCapacidad) {
    T* nuevoData = new T[nuevaCapacidad];
    int elementosACopiar = (size_ < nuevaCapacidad) ? size_ : nuevaCapacidad;
    
    for (int i = 0; i < elementosACopiar; i++) {
        nuevoData[i] = data_[i];
    }
    
    delete[] data_;
    data_ = nuevoData;
    capacity_ = nuevaCapacidad;
    
    if (size_ > capacity_) {
        size_ = capacity_;
    }
}

template<typename T>
T& Array<T>::back() {
    return data_[size_ - 1];
}

template<typename T>
const T& Array<T>::back() const {
    return data_[size_ - 1];
}

template<typename T>
typename Array<T>::iterator Array<T>::begin() {
    return data_;
}

template<typename T>
typename Array<T>::iterator Array<T>::end() {
    return data_ + size_;
}

template<typename T>
typename Array<T>::const_iterator Array<T>::begin() const {
    return data_;
}

template<typename T>
typename Array<T>::const_iterator Array<T>::end() const {
    return data_ + size_;
}

template<typename T>
void Array<T>::insert(iterator pos, const T& value) {
    int index = pos - begin();
    if (size_ >= capacity_) {
        resize(capacity_ * 2);
    }
    
    for (int i = size_; i > index; i--) {
        data_[i] = data_[i-1];
    }
    data_[index] = value;
    size_++;
}

template<typename T>
typename Array<T>::iterator Array<T>::erase(iterator pos) {
    int index = pos - begin();
    for (int i = index; i < size_ - 1; i++) {
        data_[i] = data_[i + 1];
    }
    size_--;
    return begin() + index;
}

template<typename T>
void Array<T>::remove(const T& value) {
    int writeIndex = 0;
    for (int readIndex = 0; readIndex < size_; readIndex++) {
        if (!(data_[readIndex] == value)) {
            if (writeIndex != readIndex) {
                data_[writeIndex] = data_[readIndex];
            }
            writeIndex++;
        }
    }
    size_ = writeIndex;
}

// Instanciaciones explícitas para tipos comunes
template class Array<int>;
template class Array<double>;
template class Array<float>;
template class Array<char>;
template class Array<bool>;
