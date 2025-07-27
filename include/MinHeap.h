#ifndef MINHEAP_H
#define MINHEAP_H

template<typename T>
class MinHeap {
private:
    T* data_;
    int size_;
    int capacity_;
    
    void heapifyDown(int indice);
    void resize(int nuevaCapacidad);
    void swap(T& a, T& b);

public:
    // Constructores y destructor
    MinHeap(int capacidad = 100);
    ~MinHeap();
    MinHeap(const MinHeap<T>& other);
    MinHeap<T>& operator=(const MinHeap<T>& other);
    
    // Métodos principales
    void push(const T& elemento);
    void pop();
    const T& top() const;
    
    // Información de estado
    bool empty() const;
    int size() const;
};

#endif // MINHEAP_H