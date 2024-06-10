//
// Created by rashadalsharpini on 28/12/23.
//
// 48-57 -> 0-9  65-90 -> A-Z 97-122 -> a-z
#include "HashTable.h"
int HashTable::hash(int key) {
    return key%10;
}
int HashTable::index(string value) {
    int index = 0;
    if(value[0]>=65&&value[0]<=90)
        index=value[0]-65;
    else if(value[0]>=97&&value[0]<=122)
        index=value[0]-97;
    return index;
}

void HashTable::insert(student value) {
    ll[index(value.returnFirstName())].insert_sorted(value);
}

void HashTable::print() {
    for (int i = 0; i < capacity; ++i) {
        cout<<"Linked List "<<i+1<<" : "<<endl;
        ll[i].print();
    }
}

void HashTable::print_reverse() { //completely useless but I like it
                                  // out of fun!!
    for (int i = capacity; i >= 0; --i) {
        cout<<"linked list "<<i+1<<" : "<<endl;
        ll[i].print_reverse();
    }
}

int HashTable::search(student value) {
    return ll[index(value.returnFirstName())].Search(value);
}

void HashTable::delete_value(student value) {
    ll[index(value.returnFirstName())].delete_value(value);
}



