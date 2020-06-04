#include <iostream>
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include "LoopQueue.h"
#include "LinkedList.h"
#include "LinkedListStack.h"
#include "LinkedListQueue.h"
#include "BST.h"
#include "BSTSet.h"
#include "FileOperation.h"
#include "LinkedListSet.h"
#include "LinkedListMap.h"
#include "BSTMap.h"
#include "MaxHeap.h"
#include "PriorityQueue.h"
using namespace std;
int main() {
    PriorityQueue<int> *queue = new PriorityQueue<int>();
    for (int i = 0; i < 10; ++i) {
        queue->enqueue(i);
        queue->print();
        if (i % 3 == 2) {
            queue->dequeue();
            queue->print();
        }
    }
    return 0;
}
//template<typename T>
//double testHeap(T testData[], int n, bool isHeapify) {
//    clock_t startTime = clock();
//    MaxHeap<T> *maxHeap;
//    if (isHeapify) {
//        maxHeap = new MaxHeap<T>(testData, n);
//    } else {
//        maxHeap = new MaxHeap<T>();
//        for (int i = 0; i < n; ++i) {
//            maxHeap->add(testData[i]);
//        }
//    }
//
//    T *arr = new T[n];
//    for (int j = 0; j < n; ++j) {
//        arr[j] = maxHeap->extractMax();
//    }
//
//    for (int k = 1; k < n; ++k) {
//        assert(arr[k - 1] >= arr[k]);
//    }
//    std::cout << "Test MaxHeap completed." << std::endl;
//    clock_t endTime = clock();
//    return double(endTime - startTime) / CLOCKS_PER_SEC;
//}
//
//int MaxHeap() {
//    int n = 10000000;
//    int *testData = new int[n];
//    for (int i = 0; i < n; ++i) {
//        testData[i] = rand() % INT32_MAX;
//    }
//    double time1 = testHeap(testData, n, false);
//    std::cout << "Without heapify :" << time1 << " s " << std::endl;
//    double time2 = testHeap(testData, n, true);
//    std::cout << "With heapify :" << time2 << " s " << std::endl;
//    return 0;
//}


//int BSTMap()
//{
//    std::cout << "a-tale-of-two-cities.txt" << std::endl;
//    string filename = ".././a-tale-of-two-cities.txt";
//    BSTMap<string, int> *bstMap = new BSTMap<string, int>();
//    vector<string> words;
//    if (FileOps::readFile(filename, words)) {
//        std::cout << "Total words: " << words.size() << std::endl;
//        for (string word : words) {
//            if (bstMap->contains(word)) {
//                bstMap->set(word, *(bstMap->get(word)) + 1);
//            } else {
//                bstMap->add(word, 1);
//            }
//        }
//        std::cout << "Total different words: " << bstMap->getSize() << std::endl;
//        std::cout << "Frequency of PRIDE: " << *(bstMap->get("pride")) << std::endl;
//        std::cout << "Frequency of PREJUDICE: " << *(bstMap->get("prejudice")) << std::endl;
//    }
//    return 0;
//}
//int LinkedListMap {
//    std::cout << "pride-and-prejudice.txt" << std::endl;
//    string filename = ".././pride-and-prejudice.txt";
//    LinkedListMap<string, int> *linkedListMap = new LinkedListMap<string, int>();
//    vector<string> words;
//    if (FileOps::readFile(filename, words)) {
//        std::cout << "Total words: " << words.size() << std::endl;
//        for (string word : words) {
//            if (linkedListMap->contains(word)) {
//                linkedListMap->set(word, linkedListMap->get(word) + 1);
//            } else {
//                linkedListMap->add(word, 1);
//            }
//        }
//        std::cout << "Total different words: " << linkedListMap->getSize() << std::endl;
//        std::cout << "Frequency of PRIDE: " << linkedListMap->get("pride") << std::endl;
//        std::cout << "Frequency of PREJUDICE: " << linkedListMap->get("prejudice") << std::endl;
//    }
//    return 0;
//}

//int main() {
//    std::cout << "a-tale-of-two-cities.txt" << std::endl;
//    vector<string> words;
//    if (FileOps::readFile(".././a-tale-of-two-cities.txt", words)) {
//        std::cout << "Total words: " << words.size() << std::endl;
//        LinkedListSet<string> *linkedListSet = new LinkedListSet<string>();
//        for(string word : words) {
//            linkedListSet->add(word);
//        }
//        std::cout << "Total different words: " << linkedListSet->getSize() << std::endl;
//        linkedListSet = nullptr;
//        delete linkedListSet;
//    }
//
//    std::cout << "a-tale-of-two-cities.txt" << std::endl;
//    vector<string> words1;
//    if (FileOps::readFile(".././pride-and-prejudice.txt", words1)) {
//        std::cout << "Total words: " << words1.size() << std::endl;
//        LinkedListSet<string> *linkedListSet = new LinkedListSet<string>();
//        for(string word : words1) {
//            linkedListSet->add(word);
//        }
//        std::cout << "Total different words: " << linkedListSet->getSize() << std::endl;
//        linkedListSet = nullptr;
//        delete linkedListSet;
//    }
//    return 0;
//}
//int main()
//{
//    std::cout << "a-tale-of-two-cities.txt" << std::endl;
//    vector<string> words;
//    if (FileOps::readFile(".././a-tale-of-two-cities.txt", words)) {
//        std::cout << "Total words: " << words.size() << std::endl;
//        BSTSet<string> *bstSet = new BSTSet<string>();
//        for(string word : words) {
//            bstSet->add(word);
//        }
//        std::cout << "Total different words: " << bstSet->getSize() << std::endl;
//        bstSet = nullptr;
//        delete bstSet;
//    }
//
//    std::cout << "pride-and-prejudice.txt" << std::endl;
//    vector<string> words1;
//    if (FileOps::readFile(".././pride-and-prejudice.txt", words1)) {
//        std::cout << "Total words: " << words1.size() << std::endl;
//        BSTSet<string> *bstSet = new BSTSet<string>();
//        for(string word : words1) {
//            bstSet->add(word);
//        }
//        std::cout << "Total different words: " << bstSet->getSize() << std::endl;
//        bstSet = nullptr;
//        delete bstSet;
//    }
//    return 0;
//}

//int main()
//{
//    BST<int>*bst = new BST<int>();
//    int nums[] = {5, 3, 6, 8, 4, 2,3};
//    /*
//     *      5
//     *    3   6
//     *  2  4    8
//     *
//     */
//    for (int num : nums)
//    {
//        bst->add(num);
//    }
//    cout<<"man: "<<bst->minimun()<<endl;
//    cout<<"min: "<<bst->maximun()<<endl;
//
//    bst->preOrder();
//    cout<<endl;
//    bst->preOrderNR();
//    cout<<endl;
//    bst->RRemove(3);
//    bst->LRemove(6);
//    cout<<"size:"<<bst->getSize()<<endl;
//    bst->inOrder();
//    cout<<endl;
//    bst->inOrderNR();
//    cout<<endl;
//    bst->postOrder();
//    cout<<endl;
//    bst->postOrderNR();
//    cout<<endl;
//    bst->removeMax();
//    bst->removeMin();
//    bst->levelOrder();
//    cout<<endl;
//    bst->print();
//    cout<<endl;
//    return 0;
//}

//int LinkedListQueue()
//{
//    LinkedListQueue<int>*lq = new LinkedListQueue<int>();
//    for(int i = 0;i<10;++i)
//    {
//        if(i>=5)
//        {
//            lq->dequque();
//            lq->print();
//        } else{
//            lq->enqueue(i);
//            lq->print();
//        }
//    }
//    cout<<"getSize()"<<lq->getSize()<<endl;
//    cout<<"isEmpty()"<<lq->isEmpty()<<endl;
//    cout<<"getFront()"<<lq->getFront()<<endl;
//    return 0;
//}




//int LinkedListStack()
//{
//   LinkedListStack<int>*ls = new LinkedListStack<int>();
//   for(int i = 0;i<10;++i)
//   {
//       ls->push(i);
//       ls->print();
//   }
//   cout<<"isEmpty()"<<ls->isEmpty()<<endl;
//   cout<<"getSize()"<<ls->getSize()<<endl;
//   cout<<"peek"<<ls->peek()<<endl;
//   cout<<"pop"<<ls->pop()<<endl;
//   ls->print();
//   return 0;
//}

//int linkedlist()
//{
//
//    LinkedList<int> *ll;
//    ll = new LinkedList<int>();
//    for(int i = 0;i<10;++i)
//    {
//        ll->addFirst(i);
//        ll->print();
//    }
//    ll->add(2,666);
//    ll->print();
//    cout<<endl;
//    cout<<"get(2)"<<ll->get(2)<<endl;
//    cout<<"getSize()"<<ll->getSize()<<endl;
//    cout<<"getFirst()"<<ll->getFirst()<<endl;
//    cout<<"getLast()"<<ll->getLast()<<endl;
//    cout<<"isEmpty"<<ll->isEmpty()<<endl;
//    cout<<"contains"<<ll->contains(666)<<endl;
//    ll->set(3,999);
//    ll->addLast(000);
//    ll->print();
//    cout<<endl;
//    ll->removeLast();
//    ll->removeFirst();
//    ll->remove(1);
//    ll->print();
//    return 0;
//}




//int loopqueue()
//{
//    LoopQueue<int> *loopQueue = new LoopQueue<int>();
//    for (int j = 0; j < 10; ++j) {
//        loopQueue->enqueue(j);
//        loopQueue->print();
//    }
//    loopQueue->enqueue(20);
//    loopQueue->enqueue(33);
//    loopQueue->print();
//    loopQueue->dequeue();
//    loopQueue->print();
//    std::cout << loopQueue->getFront() << std::endl;
//    loopQueue = nullptr;
//    delete loopQueue;
//    return 0;
//}
//
//
//int isValid(string s)
//{
//    auto* stack = new ArrayStack<char>();
//    for (char c : s) {
//        if (c == '(' || c == '[' || c == '{') {
//            stack->push(c);
//        }
//        else {
//            if (stack->isEmpty()) {
//                return false;
//            }
//            char topChar = stack->pop();
//            if (c == ')' && topChar != '(') {
//                return false;
//            }
//            if (c == ']' && topChar != '[') {
//                return false;
//            }
//            if (c == '}' && topChar != '{') {
//                return false;
//            }
//        }
//    }
//    return stack->isEmpty();
//}
//
//int arrayqueue()
//{
//    string str = "(){}[]";
//    cout << isValid(str) << endl;
//
//    ArrayQueue<int>*aq = new ArrayQueue<int>();
//    for(int i = 0;i<10;++i)
//    {
//        aq->enqueue(i);
//    }
//    aq->print();
//    cout<<endl;
//    cout<<"aq->isEmpty()"<<aq->isEmpty()<<endl;
//    cout<<endl;
//    cout<<"aq->getCapacity"<<aq->getCapacity()<<endl;
//    cout<<endl;
//    cout<<"aq->getSize()"<<aq->getSize()<<endl;
//    cout<<endl;
//    cout<<"aq->dequeue()"<<aq->dequeue()<<endl;
//    cout<<endl;
//    cout<<"aq->getFront()"<<aq->getFront()<<endl;
//    cout<<endl;
//    aq->print();
//    return 0;
//}
