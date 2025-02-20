//
// Created by rashadalsharpini on 02/11/23.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H
#include <iostream>
#include <cassert>
#include <sstream>
#include <vector>
#include <algorithm>
#include <climits>
#include"Queue.h"
using namespace std;
template <typename T>
struct Node{
    T data{};
    Node* next{};
    Node* prev{};
    Node(T data) : data(data){};
    ~Node(){
        cout << "Destroy value: "<<data<<" at address "<<this<<endl;
    }
    void set(Node*next,Node*prev){
        this->next=next;
        this->prev=prev;
    }
};
template <typename T>
class LinkedList {
private:
    Node<T>* head{};
    Node<T>* tail{};
    int length = 0;
public:
//    vector<Node<T>*> debug_data;
    LinkedList(){};
    LinkedList(const LinkedList&) = delete;
    LinkedList&operator=(const LinkedList &another) = delete;
    ~LinkedList();
    int printlength(){
        return length;
    }
    void link(Node<T>*first,Node<T>*second);
    void print();
    void print_reverse();
    void insert_end(T value);
    void insert_front(T value);
    Node<T>* get_nth(int n);
//    int Search(T value);
//    int improvedSearchV1(T value);
//    int improvedSearchV2(T value); // the same as v1 the difference is the writing
    Node<T>* get_nth_back(int n);
    void delete_front();
    void delete_end();
    void delete_nth(int index);
    void delete_value(T value);
    void delete_node(Node<T>*node);
    void swap_pair();
    void reverse_nodes();
    void insert_sorted(T value);
    void embed_after(Node<T>*node,T value);
};


#endif //LINKEDLIST_LINKEDLIST_H
