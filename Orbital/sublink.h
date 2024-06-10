//
// Created by rashadalsharpini on 29/12/23.
//

#ifndef ORBITAL_SUBLINK_H
#define ORBITAL_SUBLINK_H


#include<iostream>
using namespace std;
template <typename T>
struct Node{
    T* data{};
    Node* next{};
    Node* prev{};
    Node(T value):next(nullptr),prev(nullptr),data(new T[5]){
        data[0]=value;
    };
    size_t size = 0;
    void resize(){
        T* array=new T [--size];
        for (int i = 0; i < size; ++i) {
            array[i]=data[i+1];
        }

        delete[] data;
        data=array;
    }
    ~Node(){
        cout << "Destroy value: "<<*data<<" at address "<<this<<endl;
    }
};
template<typename T>
class sublink {
private:
    Node<T>* head{};
    Node<T>* tail{};
//    int length = 0;
    int numOfNode = 0;
public:
    sublink(){};
    sublink(const sublink&) = delete;
    sublink&operator=(const sublink &another) = delete;
    ~sublink();
    void link(Node<T>*first,Node<T>*second);
    void push(T value);
    bool isFull();
    bool isEmpty();
    void display();
    void display_reverse();
    void delete_node(Node<T>*node);
    T pop();
};


#endif //ORBITAL_SUBLINK_H
