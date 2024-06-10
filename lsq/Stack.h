//
// Created by rashadalsharpini on 05/12/23.
//

#ifndef LSQ_STACK_H
#define LSQ_STACK_H
#include <iostream>
#include "LinkedList.h"
using namespace std;
template <typename T>
class Stack {
private:
    int size{};
    int top{};
//    LinkedList<T>*array;
    T*array{};
public:
    Stack(int size):size(size),top(-1){
        array = new T[size];
    }
    bool isEmpty();
    bool isFull();
    void push(T value);
    T pop();
    T peektop();
    T peekpos(int pos);
    void clear();
};


#endif //LSQ_STACK_H
