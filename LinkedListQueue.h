//
// Created by cmf on 2020/4/15.
//

#ifndef C___LINKEDLISTQUEUE_H
#define C___LINKEDLISTQUEUE_H
#include <iostream>
template<typename T>
class QNode {

public:
    QNode() : e(0), next(nullptr) {}  //无参构造
    QNode(T& E) : e(E), next(nullptr) {}    //传入一个元素
    QNode(T& E, QNode<T>* Next) : e(E), next(Next) {}    //传元素和下一节点
    T e;   //元素
    QNode<T>* next;  //指向下一节点
};

template<typename T>
class LinkedListQueue : public QNode<T>
{
public:
    LinkedListQueue() :head(nullptr), tail(nullptr), size(0) {} //默认构造
    int getSize()const; //返回队列大小
    bool isEmpty()const;    //判断是否为空
    void enqueue(T e);  //入队
    T dequque();    //出队
    T getFront();   //返回头
    void print()const;  //打印

private:
    QNode<T>* head;  //指向头
    QNode<T>* tail;   //指向尾
    int size;   //记录大小
};

template<typename T>
int LinkedListQueue<T>::getSize() const {
    return size;    //返回大小
}

template<typename T>
bool LinkedListQueue<T>::isEmpty() const {
    return size == 0;   //如果等0为空返回true
}

template<typename T>
void LinkedListQueue<T>::enqueue(T e) {
    if (tail == nullptr)     //队列是否为空
    {
        tail = new QNode<T>(e);  //为空则添加在对尾指针
        head = tail;    //头和尾指向同一个节点
    }
    else {
        tail->next = new QNode<T>(e);    //否则tail的next指向新节点
        tail = tail->next;  //tail向后移一位，也就是tail指向新节点
    }
    ++size; //大小+1
}

template<typename T>
T LinkedListQueue<T>::dequque() {
    if (!isEmpty())  //判断队列是否为空
    {
        QNode<T>* retNode = head; //不为空，并把头节点的指向给临时节点
        head = head->next;  //头指向向后移一位，也就是head指向了第二个节点
        retNode->next = nullptr;    //把原本头节点的next指向置为空
        if (head == nullptr) //如果向后移一位后指向空
        {
            tail = nullptr; //则说明队列原本就一个元素，出队删除一个后，队列为空，所以尾指针指原本指向要删除的节点现在也要指向空
        }
        --size; //大小-1
        return retNode->e;  //返回出队元素
    }
}

template<typename T>
T LinkedListQueue<T>::getFront() {
    if (!isEmpty())  //如果队列不为空
    {
        return head->e; //则返回头节点的元素
    }
}

template<typename T>
void LinkedListQueue<T>::print()const {
    QNode<T>* prev = head;
    std::cout << "LinkListQueue: size = " << size << std::endl;
    std::cout << "front ";
    std::cout << "[";
    while (prev != nullptr) {
        std::cout << prev->e;
        if (prev->next != nullptr) {
            std::cout << ", ";
        }
        prev = prev->next;
    }
    std::cout << "] tail" << std::endl;
}

#endif //C___LINKEDLISTQUEUE_H
