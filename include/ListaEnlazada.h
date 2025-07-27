#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

template<typename T>
struct NodoLista {
    T data;
    NodoLista<T>* next;
    
    NodoLista(const T& valor) : data(valor), next(nullptr) {}
};

template<typename T>
class ListaEnlazada {
private:
    NodoLista<T>* cabeza;
    int size_;

public:
    // Iteradores
    class iterator {
    private:
        NodoLista<T>* nodo_actual;
    public:
        iterator(NodoLista<T>* nodo);
        T& operator*();
        iterator& operator++();
        iterator operator++(int);
        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;
    };
    
    class const_iterator {
    private:
        const NodoLista<T>* nodo_actual;
    public:
        const_iterator(const NodoLista<T>* nodo);
        const T& operator*() const;
        const_iterator& operator++();
        const_iterator operator++(int);
        bool operator==(const const_iterator& other) const;
        bool operator!=(const const_iterator& other) const;
    };
    
    // Constructores y destructor
    ListaEnlazada();
    ~ListaEnlazada();
    ListaEnlazada(const ListaEnlazada<T>& other);
    ListaEnlazada<T>& operator=(const ListaEnlazada<T>& other);
    
    // Métodos principales
    void push_back(const T& elemento);
    void push_front(const T& elemento);
    void pop_back();
    void pop_front();
    
    // Acceso a elementos
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;
    
    // Información de estado
    bool empty() const;
    int size() const;
    void clear();
    void remove(const T& valor);
    
    // Iteradores
    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
};

#endif // LISTAENLAZADA_H