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
    int capacity;
    LinkedList<student>*ll=new LinkedList<student>[capacity];
public:
    HashTable(int capacity):capacity(capacity){}
    int hash(int key);
    int index(string value);
    void insert(student value);
    void print();
    void print_reverse();
    int search(student value);
    void delete_value(student value);
};


#endif //HASHTABLE_HASHTABLE_H
