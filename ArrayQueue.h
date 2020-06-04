//
// Created by cmf on 2020/4/11.
//

#ifndef C___ARRAYQUEUE_H
#define C___ARRAYQUEUE_H
#include "Array.h"

template<typename T>
class ArrayQueue{

public:
    ArrayQueue();
    ArrayQueue(const int capacity);
    int getSize()const;
    int getCapacity()const;
    bool isEmpty()const;
    void enqueue(const T&t);
    T dequeue();
    T getFront();
    void print()const;
    virtual ~ArrayQueue();
private:
    Array<T>*arr;
};

template<typename T>
ArrayQueue<T>::ArrayQueue() {
    arr = new Array<T>();
}

template<typename T>
ArrayQueue<T>::ArrayQueue(const int capacity) {
    arr = new Array<T>(capacity);
}

template<typename T>
int ArrayQueue<T>::getSize()const {
    return arr->getSize();
}

template<typename T>
int ArrayQueue<T>::getCapacity()const{
    return arr->getCapacity();
}

template<typename T>
bool ArrayQueue<T>::isEmpty()const {
    return arr->isEmpty();
}

template<typename T>
void ArrayQueue<T>::enqueue(const T &t) {
    arr->addLast(t);
}

template<typename T>
T ArrayQueue<T>::dequeue() {
    return arr->removeFirst();
}

template<typename T>
T ArrayQueue<T>::getFront() {
    return arr->getFirst();
}

template<typename T>
void ArrayQueue<T>::print() const {
    std::cout << "ArrayQueue: size = " << arr->getSize() << ", capacity = " << arr->getCapacity() << std::endl;
    std::cout << "bottom ";
    arr->print();
}

template<typename T>
ArrayQueue<T>::~ArrayQueue() {
    delete[] arr;
    arr = nullptr;
}

#endif //C___ARRAYQUEUE_H
