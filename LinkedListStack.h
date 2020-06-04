//
// Created by cmf on 2020/4/15.
//

#ifndef C___LINKEDLISTSTACK_H
#define C___LINKEDLISTSTACK_H
#include "LinkedList.h"
template<typename T>
class Stack {
public:
    virtual int getSize()const = 0;
    virtual bool isEmpty()const = 0;
    virtual void push(T& e) = 0;
    virtual T pop() = 0;
    virtual T peek()const = 0;
};

template<typename T>
class LinkedListStack : public Stack<T> {
public:
    LinkedListStack();
    int getSize()const;
    bool isEmpty()const;
    void push(T&e);
    T pop();
    T peek()const;
    void print()const;
private:
    LinkedList<T>*list;
};

template<typename T>
int LinkedListStack<T>::getSize() const {
    return list->getSize();
}

template<typename T>
bool LinkedListStack<T>::isEmpty() const {
    return list->isEmpty();
}

template<typename T>
void LinkedListStack<T>::push(T& e) {
    list->addFirst(e);
}

template<typename T>
T LinkedListStack<T>::pop() {
    return list->removeFirst();
}

template<typename T>
T LinkedListStack<T>::peek()const {
    return list->getFirst();
}

template<typename T>
void LinkedListStack<T>::print() const {
    std::cout << "Stack: size = " << list->getSize() << std::endl;
    std::cout << "bottom ";
    list->print();
    std::cout << " top" << std::endl;
}

template<typename T>
LinkedListStack<T>::LinkedListStack() {
    list = new LinkedList<T>();
}


#endif //C___LINKEDLISTSTACK_H
