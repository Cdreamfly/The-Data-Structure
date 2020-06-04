//
// Created by cmf on 2020/5/19.
//

#ifndef C___LINKEDLISTSET_H
#define C___LINKEDLISTSET_H
#include "LinkedList.h"
#include "Set.h"

template<typename T>
class LinkedListSet: public Set<T> {
private:
    LinkedList<T>*list;
public:
    LinkedListSet(){
        list = new LinkedList<T>();
    }

    int getSize()const{
        return list->getSize();
    }

    bool isEmpty()const {
        return list->isEmpty();
    }

    bool contains(T e)const {
        return list->contains(e);
    }

    void add(T e){
        if(!list->contains(e)){
            list->addFirst(e);
        }
    }

    void remove(T e){
        list->removeElement(e);
    }
    ~LinkedListSet(){
        delete list;
    }
};

#endif //C___LINKEDLISTSET_H
