//
// Created by rashadalsharpini on 28/12/23.
//

#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H

#include "LinkedList.h"
#include<iostream>
using namespace std;
class HashTable {
private:
    LinkedList<int> ll[10];
public:
    int hash(int key);
    void insert(int value);
    void print();
    void print_reverse();
    int search(int value);
    void delete_value(int value);
};


#endif //HASHTABLE_HASHTABLE_H
