//
// Created by cmf on 2020/5/19.
//

#ifndef C___SET_H
#define C___SET_H

template<typename T>
class Set {
    virtual void add(T e) = 0;
    virtual void remove(T e) = 0;
    virtual bool contains(T e)const = 0;
    virtual int getSize()const = 0;
    virtual bool isEmpty()const = 0;
};

#endif //C___SET_H
