//
// Created by cmf on 2020/5/28.
//

#ifndef C___PRIORITYQUEUE_H
#define C___PRIORITYQUEUE_H
#include "Queue.h"
#include "MaxHeap.h"
template<class T>
class PriorityQueue : public Queue<T> {
private:
    MaxHeap<T> *maxHeap;
public:
    PriorityQueue() {
        maxHeap = new MaxHeap<T>();
    }

    int getSize() {
        return maxHeap->size();
    }

    bool isEmpty() {
        return maxHeap->isEmpty();
    }

    T getFront() {
        return maxHeap->findeMax();
    }

    void enqueue(T e) {
        maxHeap->add(e);
    }

    T dequeue() {
        return maxHeap->extractMax();
    }

    void print() {
        std::cout << "Queue: size = " << maxHeap->size() << std::endl;
        std::cout << "front ";
        maxHeap->print();
        std::cout << " tail" << std::endl;
    }
};


#endif //C___PRIORITYQUEUE_H
