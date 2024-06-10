//
// Created by rashadalsharpini on 07/12/23.
//

#include "Queue.h"
template class Queue<int>;
template class Queue<double>;
template class Queue<float>;
template class Queue<size_t>;
template class Queue<string>;
template class Queue<char>;
template class Queue<bool>;
template <typename T>
int Queue<T>::next(int pos) {
    ++pos;
    if(pos==capacity)
        pos=0;
    return pos;
//    return (pos+1)%capacity;
}
template <typename T>
void Queue<T>::enqueue(T value) {
    if(isFull()) {
        cout << "Queue is full!" << endl;
    }
    else{
        array[rear]=value;
        rear=next(rear);
        numberOfElements++;
    }
}
template <typename T>
T Queue<T>::dequeue() {
    if(isEmpty())
        cout<<"Queue is empty!"<<endl;
    else{
        T value = array[front];
        front = next(front);
        --numberOfElements;
        return value;
    }
}
template <typename T>
void Queue<T>::display() {
    cout<<"Front "<<front<<" - Rear "<<rear<<endl;
    if(isFull())
        cout<<"Full"<<endl;
    else if(isEmpty()) {
        cout << "Empty" << endl;
        return;
    }
    for(int cur=front,step=0;step<numberOfElements;++step,cur=next(cur))
        cout<<array[cur]<<" ";
    cout<<"\n\n";
}
template <typename T>
bool Queue<T>::isEmpty() {
    if(numberOfElements==0)
        return true;
    return false;
}
template <typename T>
bool Queue<T>::isFull() {
    if(numberOfElements==capacity)
        return true;
    return false;
}
