//
// Created by rashadalsharpini on 29/12/23.
//

#include "sublink.h"
template class sublink<int>;
template class sublink<double>;
template class sublink<float>;
template class sublink<size_t>;
template class sublink<string>;
template class sublink<char>;
template class sublink<bool>;

template <typename T>
sublink<T>::~sublink() {
    while(head){
        Node<T>*current = head->next;
        delete head;
        head=current;
    }
}

template <typename T>
void sublink<T>::link(Node<T> *first, Node<T> *second) {
    if(first)
        first->next=second;
    if(second)
        second->prev=first;
}

template <typename T>
void sublink<T>::push(T value) {
    Node<T> *item = new Node(value);
    //this is first element in the first node
    if(!head) {
        head = tail = item;
        item->size++;
        ++numOfNode;
        return;
    }
    //this is first element in any node
    if (isFull()) {
        //create new node
        link(tail, item);
        tail = item;
        item->size++;
        ++numOfNode;
        return;
    }
    else {
        //add the value in the existed node
        tail->data[tail->size++]=value;
    }
}

template <typename T>
bool sublink<T>::isFull() {
    /*if(length%5==0)
        return true;
    return false;*/
    return !(tail->size%5);
}

template <typename T>
bool sublink<T>::isEmpty() {
    /*if(length==0)
        return true;
    return false;*/
    return !(head->size);
}

template <typename T>
void sublink<T>::display() {
    int numOfNodes = 0;
    for(Node<T>*cur=head;cur;cur=cur->next){
        numOfNodes++;
        cout << "\tNode " << numOfNodes << " ->[";
        for(int i=0;i<cur->size;i++) {
            cout << cur->data[i];
            if (i<cur->size-1)
                cout<<" ";
        }
        cout<<"]"<<endl;
    }
}

template <typename T>
void sublink<T>::display_reverse() {
    int numOfNodes = 0;
    for(Node<T>*cur=tail;cur;cur=cur->prev){
        numOfNodes++;
        cout << "Node " << numOfNodes << " ->[ ";
        for(int i=0;i<4;i++)
            cout<<cur->data[i]<<" ";
        cout<<"]"<<endl;
    }
}

template <typename T>
T sublink<T>::pop() {
    Node<T>*temp=head;
    if(isEmpty()) {
        head=head->next;
        head->prev= nullptr;
        delete temp;
        numOfNode--;
    }
    if(!head)
        throw logic_error("Empty!!");
    T value=head->data[0];
    head->resize();
    return value;
}

template<typename T>
void sublink<T>::delete_node(Node<T> *node) {
//    --length;
    delete node;
}
