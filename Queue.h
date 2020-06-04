//
// Created by cmf on 2020/5/28.
//

#ifndef C___QUEUE_H
#define C___QUEUE_H

template<typename T>
class Queue {
    int getSize()const ;
    bool isEmpty()const ;
    void enqueue(T e);
    T dequeue();
    T getFront() const ;
};


#endif //C___QUEUE_H
