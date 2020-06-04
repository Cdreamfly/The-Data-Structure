//
// Created by cmf on 2020/4/12.
//

#ifndef C___LOOPQUEUE_H
#define C___LOOPQUEUE_H
#include "ArrayQueue.h"
#include <iostream>
template<typename T>
class LoopQueue :public ArrayQueue<T>{

public:
    //无参构造
    LoopQueue();
    //有参构造
    LoopQueue(const int capacity);
    //返回大小
    int getSize()const;
    //返回容量
    int getCapacity()const;
    //判断是否为空
    bool isEmpty()const;
    //入队
    void enqueue(const T&e);
    //出队
    T dequeue();
    //打印
    void print()const;
    //返回队首
    T getFront()const;
    //析构
    ~LoopQueue();
private:
    void resize(const int newcapacity);
    T* data;
    int front,tail;
    int capacity;
};

template<typename T>
LoopQueue<T>::LoopQueue() {
    data = new T[10];
    front = tail = 0;
    capacity = 10;
}
template<typename T>
LoopQueue<T>::LoopQueue(const int capacity) {
    data = new T[capacity];
    front = tail = 0;
    this->capacity = capacity;
}

template<typename T>
int LoopQueue<T>::getSize() const {
    return (tail+capacity-front)%capacity;
}

template<typename T>
int LoopQueue<T>::getCapacity() const {
    return capacity;
}

template<typename T>
bool LoopQueue<T>::isEmpty() const {
    return front == tail;
}

template<typename T>
LoopQueue<T>::~LoopQueue() {
    delete[] data;
    data = nullptr;
}

template<typename T>
void LoopQueue<T>::enqueue(const T &e) {
    if((tail+1)%capacity == front)resize(capacity*2); //如果队列为满则扩容
    data[tail] = e; //入队元素放队尾
    tail = (tail+1)%capacity;
}

template<typename T>
void LoopQueue<T>::resize(const int newcapacity) {
    // 将数组空间的容量变成newCapacity大小
    T *newData = new T[newcapacity + 1];
    for (int i = 0; i < getSize(); ++i) {
        newData[i] = data[(i + front) % capacity];  //把元素放入新数组空间
    }
    data = newData; //数组空间指向新数组空间
    tail = getSize();   //更新
    front = 0;
    capacity = newcapacity;
    newData = nullptr;//新数组指向空
    delete []newData;//删除新数组
}

template<typename T>
T LoopQueue<T>::dequeue() {
    if(front!=tail) //如果队列不为空
    {
        T ret = data[front]; //暂存队首元素
        front = (front+1)%capacity; //front+1
        if(getSize() == capacity/4 && capacity/2 != 0){//如果元素个数只有容量的1/4且不为空
            resize(capacity/2); //缩减为原本1/2
        }
    }
}

template<typename T>
void LoopQueue<T>::print() const {
    std::cout << "LoopQueue: size = " << getSize() << ", capacity = " << capacity << std::endl;
    std::cout << "front [";
    for (int i = front; i != tail; i = (i + 1) % capacity) {
        std::cout << data[i];
        if ((i + 1) % capacity != tail) {
            std::cout << ", ";
        }
    }
    std::cout << "] tail" << std::endl;
}

template<typename T>
T LoopQueue<T>::getFront()const {
    if(front!=tail)return data[front];
}

#endif //C___LOOPQUEUE_H
