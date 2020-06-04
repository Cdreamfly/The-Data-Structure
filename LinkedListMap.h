////
//// Created by cmf on 2020/5/19.
////
//
//#ifndef C___LINKEDLISTMAP_H
//#define C___LINKEDLISTMAP_H
//#include "Map.h"
//
//template<typename K,typename V>
//class MapNode{
//public:
//    K key;
//    V value;
//    MapNode<K,V>*next;
//public:
//    MapNode():key(),value(),next(nullptr){}
//    MapNode(K KEY,V VALUE,MapNode<K,V>*NEXT):key(KEY),value(VALUE),next(NEXT){}
//};
//
//template<typename K,typename V>
//class LinkedListMap : public Map<K,V>{
//private:
//    MapNode<K,V>*dummyHead;
//    int size;
//    MapNode<K,V>* getNode(K key){
//        MapNode<K,V>*cur = dummyHead->next;
//        while(cur!= nullptr){
//            if(cur->key == key){
//                return cur;
//            }
//            cur = cur->next;
//        }
//        return nullptr;
//    }
//
//public:
//    LinkedListMap():size(0){
//        dummyHead = new MapNode<K,V>();
//    }
//    int getSize()const{
//        return size;
//    }
//    bool isEmpty()const {
//        return size == 0;
//    }
//    bool contains(K key) {
//        return getNode(key)!= nullptr;
//    }
//    V get(K key){
//        if(contains(key) == true){
//            MapNode<K,V>*node = getNode(key);
//            return node->value;
//        }
//    }
//    void set(K key,V value){
//        MapNode<K,V>*node = getNode(key);
//        if(node== nullptr){
//            add(key,value);
//        }else{
//            node->value = value;
//        }
//    }
//    void add(K key,V value){
//        MapNode<K,V>*node = getNode(key);
//        if(node == nullptr){
//            dummyHead->next = new MapNode<K,V>(key,value,dummyHead->next);
//            ++size;
//        }else{
//            node->value = value;
//        }
//    }
//    V remove(K key){
//        MapNode<K,V>*prev = dummyHead;
//        while(prev->next!= nullptr){
//            if(prev->next->key == key){
//                break;
//            }
//            prev = prev->next;
//        }
//        if(prev->next!= nullptr){
//            MapNode<K,V>*delNode = prev->next;
//            prev->next = delNode->next;
//            delNode->next = nullptr;
//            --size;
//            return delNode->value;
//        }else{
//            return prev->value;
//        }
//    }
//};
//
//
//#endif //C___LINKEDLISTMAP_H
