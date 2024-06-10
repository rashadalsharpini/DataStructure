//
// Created by rashadalsharpini on 29/12/23.
//

#ifndef ORBITAL_ORBITAL_H
#define ORBITAL_ORBITAL_H

#include <iostream>
#include "sublink.h"
using namespace std;
template <typename T>
class Orbital {
private:
    int capacity;
    sublink<T>*ss=new sublink<T>[capacity];
    int numOfElements = 0;
    int numOfElementsp = 0;
public:
    Orbital(int capacity):capacity(capacity){}
    void push(T value);
    T pop();
    void print();
};

#endif //ORBITAL_ORBITAL_H
