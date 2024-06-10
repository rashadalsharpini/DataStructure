//
// Created by rashadalsharpini on 07/12/23.
//

#ifndef LSQ_QUEUE_H
#define LSQ_QUEUE_H
#include <iostream>
#include "Stack.h"
#include "LinkedList.h"
using namespace std;
template <typename T>
class Queue {
private:
    T*array;
    int front{0};
    int rear{0};
    int capacity;
    int numberOfElements = 0;
public:
    Queue(int capacity):capacity(capacity){
        array=new T[capacity];
        front=0;rear=0;
    }
//    ~Queue(){delete[] array;}
    void enqueue(T value);
    T dequeue();
    void display();
    bool isEmpty();
    bool isFull();
    int next(int pos);
    friend ostream& operator<<(ostream& os,const Queue&obj){
        for (int i = 0; i < obj.capacity; ++i) {
            os<<obj.array[i]<<" ";
        }
//        os<<dequeue();
        return os;
    };
//    ostream& operator<<(std::ostream& os, const MyClass& obj)
};




#endif //LSQ_QUEUE_H
