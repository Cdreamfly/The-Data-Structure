//
// Created by cmf on 2020/4/14.
//

#ifndef C___LINKEDLIST_H
#define C___LINKEDLIST_H
#include <iostream>
template<typename T>
class Node
{
public:
    T e;
    Node<T>*next;
    Node():e(0),next(nullptr){}
    Node(T& E):e(E),next(nullptr){}
    Node(T& E,Node<T>*Next):e(E),next(Next){}
};
template<typename T>
class LinkedList {

public:
    LinkedList();
    //返回连表大小
    int getSize()const;
    //判断是否为空
    bool isEmpty()const;
    //头插入
    void addFirst(T e);
    //为插入
    void addLast(T e);
    //插入
    void add(int index, T e);
    //练习：获取链表第👈index个位置的元素
    T get(const int index);
    //获取链表第一个元素
    T getFirst();
    //获取链表最后一个元素
    T getLast();
    //练习：修改链表第👈index个位置的元素
    void set(const int index,const T&e);
    //查找链表是否有元素e
    bool contains(const T&e)const;
    //删除元素
    T remove(const int index);
    //删除头
    T removeFirst();
    //删除尾
    T removeLast();
    //删除链表中直为e的所有节点
    void removeElement(T& e);
    //打印链表
    void print()const;
private:
    Node<T>*dummyHead;  //虚拟头节点，不存数据
    int size;   //记录大小
};

template<typename T>
int LinkedList<T>::getSize() const {
    return size;
}

template<typename T>
bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
void LinkedList<T>::addFirst(T e) {
    //第一种写法
//    Node<T>*node = new Node<T>(e);    //创建一个节点，把直放入节点
//    node->next = head;    //让创建的节点的下next指向当前头
//    head = node;  //头指向新创建的节点
    //第二种写法
//    head = new Node<T>(e,head); //新创建一个节点传入数据和头让新节点的next指向head，然后head在指向新节点
//    ++size;
    add(0,e);
}

template<typename T>
void LinkedList<T>::add(int index, T e) {
    if(index >= 0 && index <= size)
    {
        Node<T>*prev = dummyHead;
        for(int i = 0;i<index;++i){
            prev = prev->next;  //遍历到node为要插入节点的前一节点
        }
        //第一种写法
//    Node<T>*newNode = Node<T>(e);   //创建新节点传入直e
//    newNode->next = node->next; //新节点的next指向要插入节点
//    node->next = newNode;   //要插入节点的前一节点的next指向新节点
        //第二种写法
        prev->next = new Node<T>(e,prev->next); //创建一个节点传入直和让新节点的next指向插入节点，然后要插入节点的前一节点的next指向新节点
        ++size;
    }
}

template<typename T>
void LinkedList<T>::addLast(T e) {
    add(size,e);
}

template<typename T>
LinkedList<T>::LinkedList() {
    dummyHead = new Node<T>();
    size = 0;
}

template<typename T>
T LinkedList<T>::get(const int index) {
    if(index>=0 && index<=size)
    {
        Node<T>*cur = dummyHead->next;  //把第一个元素的位置给cur
        for(int i = 0;i<index;++i)
        {
            cur = cur->next;
        }
        return cur->e;//返回👈第index个节点的元素
    }
}

template<typename T>
T LinkedList<T>::getFirst() {
    return get(0);
}

template<typename T>
T LinkedList<T>::getLast() {
    return get(size-1);
}

template<typename T>
void LinkedList<T>::set(const int index, const T &e) {
    if(index>=0 && index<=size)
    {
        Node<T> *cur = dummyHead->next;
        for (int i = 0; i < index; ++i) {
            cur = cur->next;
        }
        cur->e = e;
    }
}

template<typename T>
bool LinkedList<T>::contains(const T &e) const {
    //第一种遍历
//    Node<T>*cur = dummyHead->next;
//    while(cur!= nullptr)
//    {
//        if(cur->e == e)
//        {
//            return true;
//        }
//        cur = cur->next;
//    }
//    return false;
    //第二种遍历
    for(Node<T>*cur = dummyHead->next;cur!= nullptr;cur = cur->next)
    {
        if(cur->e == e) //如果找到元素返回true
        {
            return true;
        }
    }
    return false;   //否则返回false
}

template<typename T>
void LinkedList<T>::print() const {
    std::cout << "LinkedList: size = " << size << std::endl;
    std::cout << "[";

    for(Node<T>*cur = dummyHead->next;cur!= nullptr;cur = cur->next)
    {
        std::cout<<cur->e<<"->";
    }
    std::cout<<"NULL"<<"]"<<std::endl;
}

template<typename T>
T LinkedList<T>::remove(const int index) {
    if(index>=0 && index<=size)
    {
        Node<T>*prev = dummyHead;
        for(int i = 0;i<index;++i)  //找到要删除节点的前一个节点
        {
            prev = prev->next;
        }
        Node<T>*retNode = prev->next;   //保存要删除的节点
        prev->next = retNode->next; //让前一节点next指向要删除节点的后一节点
        retNode->next = nullptr;    //要删除节点next指向空
        --size;
        return retNode->e;
    }
}

template<typename T>
T LinkedList<T>::removeLast() {
    return remove(size-1);
}

template<typename T>
T LinkedList<T>::removeFirst() {
    return remove(0);
}

template<typename T>
void LinkedList<T>::removeElement(T &e) {
    Node<T> *prev = dummyHead->next;
    while (prev->next != nullptr) {
        if (prev->next->e == e) {
            break;
        }
        prev = prev->next;
    }

    if (prev->next != nullptr) {
        Node<T> *delNode = prev->next;
        prev->next = delNode->next;
        delNode->next = nullptr;
        size--;
    }
}


#endif //C___LINKEDLIST_H
