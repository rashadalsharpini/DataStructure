//
// Created by rashadalsharpini on 28/12/23.
//

#include "HashTable.h"

int HashTable::hash(int key) {
    return key%10;
}

void HashTable::insert(int value) {
    int index=hash(value);
    ll[index].insert_sorted(value);
}

void HashTable::print() {
    for (int i = 0; i < 10; ++i) {
        cout<<"linked list "<<i<<" : ";
        ll[i].print();
    }
}

void HashTable::print_reverse() { //completely useless but I like it
                                  // out of fun!!
    for (int i = 9; i >= 0; --i) {
        cout<<"linked list "<<i<<" : ";
        ll[i].print_reverse();
    }
}

int HashTable::search(int value) {
    int index=hash(value);
    return ll[index].Search(value);
}

void HashTable::delete_value(int value) {
    int index=hash(value);
    ll[index].delete_value(value);
}


