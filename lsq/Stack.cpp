//
// Created by rashadalsharpini on 05/12/23.
//

#include "Stack.h"
template class Stack<int>;
template class Stack<double>;
template class Stack<float>;
template class Stack<size_t>;
template class Stack<string>;
template class Stack<char>;
template class Stack<bool>;
template <typename T>
bool Stack<T>::isFull() {
    if(top==size-1)
        return true;
    return false;
}
template <typename T>
bool Stack<T>::isEmpty() {
    if(top==-1)
        return true;
    return false;
}
template <typename T>
void Stack<T>::push(T e) {
    if(isFull())
        cout<<" the Stack is full"<<endl;
    else
        array[++top] = e;
}
template <typename T>
T Stack<T>::pop() {
    if(isEmpty())
        cout<<" the Stack is empty"<<endl;
    else
        return array[top--];
}

template <typename T>
T Stack<T>::peektop() {
    return array[top];
}
template <typename T>
T Stack<T>::peekpos(int pos) {
    int x = top-(pos+1);
    if(x<0||x>top)
        return 0;
    else
        return array[x];
}
template <typename T>
void Stack<T>::clear(){
    while(!isEmpty())
        pop();
}
