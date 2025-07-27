#ifndef ARRAY_H
#define ARRAY_H

template<typename T>
class Array {
private:
    T* data_;
    int size_;
    int capacity_;
    
    void resize(int nuevaCapacidad);

public:
    typedef T* iterator;
    typedef const T* const_iterator;
    
    // Constructores y destructor
    Array(int capacidad = 10);
    ~Array();
    Array(const Array<T>& other);
    Array<T>& operator=(const Array<T>& other);
    
    // Métodos principales
    void push_back(const T& elemento);
    void pop_back();
    T& operator[](int indice);
    const T& operator[](int indice) const;
    
    // Información de tamaño
    int size() const;
    bool empty() const;
    void clear();
    
    // Acceso a elementos
    T& back();
    const T& back() const;
    
    // Iteradores
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    
    // Operaciones adicionales
    void insert(iterator pos, const T& value);
    iterator erase(iterator pos);
    void remove(const T& value);
};

#endif // ARRAY_H