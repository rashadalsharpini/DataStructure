//
// Created by rashadalsharpini on 25/12/23.
//

#ifndef DYNAMICARRAY_DYNAMICARRAY_H
#define DYNAMICARRAY_DYNAMICARRAY_H
#include <iostream>
#include "student.h"
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* data; // Pointer to dynamically allocated array
    size_t size; // Current number of elements in the array
    size_t capacity; // Full array Capacity
public:
    DynamicArray();
    ~DynamicArray();
    DynamicArray(const DynamicArray<T>& other);
    DynamicArray& operator=(const DynamicArray<T>& other);
    void resize();
    T& operator[](size_t index);
    size_t getsize()const;
    void insertEnd(const T& value);
    void display();
    void insertFront(const T& value);
    void removeEnd();
    void removeFront();
    void insert_nth(size_t index, const T& value);
    void delete_nth(size_t index);

};




#endif //DYNAMICARRAY_DYNAMICARRAY_H
