//
// Created by cmf on 2020/4/11.
//

#ifndef C___ARRAYSTACK_H
#define C___ARRAYSTACK_H
#include "Array.h"

template<typename T>
class ArrayStack
{
public:
    ArrayStack();
    ArrayStack(const int capacity);
    //返回栈的大小
    int getSize()const;
    //判断栈是否为空
    bool isEmpty()const;
    //返回栈的容量
    int getCapacity()const;
    //入栈
    void push(T& t)const;
    //出栈
    T pop()const;
    //返回栈顶
    T peek()const;
    void print()const;
    ~ArrayStack();
private:
    Array<T>* arr;
};

template<typename T>
ArrayStack<T>::ArrayStack()
{
    arr = new Array<T>();
}

template<typename T>
ArrayStack<T>::ArrayStack(const int capacity)
{
    arr = new Array<T>(capacity);
}

template<typename T>
inline int ArrayStack<T>::getSize()const
{
    return arr->getSize();	//调用返回数组大小，也就是栈的大小
}

template<typename T>
inline bool ArrayStack<T>::isEmpty()const
{
    return arr->isEmpty();	//调用判断数组是否为空，也就是栈是否为空
}

template<typename T>
inline int ArrayStack<T>::getCapacity() const
{
    return arr->getCapacity();	//调用返回数组的容量
}

template<typename T>
inline void ArrayStack<T>::push(T& t) const
{
    arr->addLast(t);	//调用从数组尾部添加一个元素
}

template<typename T>
inline T ArrayStack<T>::pop()const
{
    return arr->removeLast();	//调用删除数组的最后一个元素
}

template<typename T>
inline T ArrayStack<T>::peek()const
{
    return arr->getLast();	//调用返回数组最后一个元素也就是栈顶
}

template<typename T>
inline void ArrayStack<T>::print() const
{
    std::cout << "ArrayStack: size = " << arr->getSize() << ", capacity = " << arr->getCapacity() << std::endl;
    std::cout << "bottom ";
    arr->print();
    std::cout << " top" << std::endl;
}

template<typename T>
ArrayStack<T>::~ArrayStack()
{
    delete arr;
    arr = nullptr;
}

#endif //C___ARRAYSTACK_H
