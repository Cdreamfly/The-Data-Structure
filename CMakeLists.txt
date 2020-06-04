cmake_minimum_required(VERSION 3.16)
project(C__)

set(CMAKE_CXX_STANDARD 14)

add_executable(C__ main.cpp Array.h ArrayStack.h ArrayQueue.h LoopQueue.h LinkedList.h LinkedListStack.h LinkedListQueue.h BST.h BSTSet.h Set.h FileOperation.h LinkedListSet.h Map.h LinkedListMap.h BSTMap.h MaxHeap.h Queue.h PriorityQueue.h)

target_link_libraries(C__ ${OpenCV_LIBS})