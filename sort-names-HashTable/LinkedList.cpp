//
// Created by rashadalsharpini on 02/11/23.
//
// ninja: no work to do.

#include "LinkedList.h"
template class LinkedList<int>;
template class LinkedList<double>;
template class LinkedList<float>;
template class LinkedList<size_t>;
template class LinkedList<string>;
template class LinkedList<char>;
template class LinkedList<bool>;
template class LinkedList<student>;
template <typename T>
LinkedList<T>::~LinkedList() {
    while(head){
        Node<T>*current = head->next;
        delete head;
        head=current;
    }
}
template <typename T>
void LinkedList<T>::print() {
    for(Node<T>*cur=head;cur;cur = cur->next){
        cout<<cur->data;
    }
    cout<<endl;
}
template <typename T>
void LinkedList<T>::print_reverse() {
    for(Node<T>*cur=tail;cur;cur=cur->prev)
        cout<<cur->data<<" ";
    cout<<endl;
}
template <typename T>
void LinkedList<T>::link(Node<T> *first, Node<T> *second) {
    if(first)
        first->next=second;
    if(second)
        second->prev=first;
}
template <typename T>
void LinkedList<T>::insert_end(T value) {
    Node<T>* item = new Node(value);
    if(!head)
        head = tail = item;
    else{
        link(tail,item);
        tail = item;
    }
    length++;
}
template <typename T>
void LinkedList<T>::insert_front(T value) {
    Node<T>* item = new Node(value);

    if(!head)
        head = tail = item;
    else{
        link(item,head);
        head = item;
    }
    length++;
}
template <typename T>
Node<T>* LinkedList<T>::get_nth(int index) {
    int cnt = 0;
    for (Node<T> *cur = head; cur; cur = cur->next)
        if (cnt++ == index)
            return cur;
    return nullptr;
}

template <typename T>
Node<T>* LinkedList<T>::get_nth_back(int n) {
    if(length<n)
        return nullptr;
    return get_nth(length - (n + 1));
}
template <typename T>
int LinkedList<T>::Search(T value) {
    int index = 0;
    for(Node<T>* cur =head;cur;cur=cur->next,index++)
        if(cur->data==value)
            return index;
    return -1;
}
template <typename T>
void LinkedList<T>::delete_node(Node<T> *node) {
    --length;
    delete node;
}
template <typename T>
void LinkedList<T>::delete_front() {
    if(!head)
        return;
    Node<T>*cur=head->next;
    delete_node(head);
    head=cur;
    if(head)
        head->prev= nullptr;
    else if(!length)
        tail= nullptr;
    cout<<"Deleted Successfully\n";
}
template <typename T>
void LinkedList<T>::delete_end() {
    if(!head)
        return;
    Node<T>*cur = tail->prev;
    delete_node(tail);
    tail=cur;
    if(tail)
        tail->next = nullptr;
    else if(!length)
        head = nullptr;
    cout<<"Deleted Successfully\n";
}
template <typename T>
void LinkedList<T>::delete_nth(int index) {
    if(index<0||index>length)
        cout<<"Error. No such node\n";
    else if(index==0)
        delete_front();
    else if(index==length-1)
        delete_end();
    else{
        Node<T>*cur = get_nth(index);
        link(cur->prev,cur->next);
        delete_node(cur);
        cout<<"Deleted Successfully\n";
    }
}
template <typename T>
void LinkedList<T>::delete_value(T value) {
    delete_nth(Search(value));
}
template <typename T>
void LinkedList<T>::embed_after(Node<T> *node_before, T value) {
    Node<T>*middle=new Node(value);
    ++length;LinkedList<string> lr[5];


    Node<T>*node_after=node_before->next;
    link(node_before,middle);
    link(middle,node_after);
}
template <typename T>
void LinkedList<T>::insert_sorted(T value) {
    if(!length||value<=head->data)
        insert_front(value);
    else if(tail->data<=value)
        insert_end(value);
    else{
        for(Node<T>*cur=head;cur;cur=cur->next){
            if(value<=cur->data){
                embed_after(cur->prev,value);
                break;
            }
        }
    }
}
