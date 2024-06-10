//
// Created by rashadalsharpini on 29/12/23.
//

#include "Orbital.h"
template class Orbital<int>;
template class Orbital<double>;
template class Orbital<float>;
template class Orbital<size_t>;
template class Orbital<string>;
template class Orbital<char>;
template class Orbital<bool>;

template <typename T>
void Orbital<T>::push(T value) {
    ss[numOfElements%capacity].push(value);
    numOfElements++;
}

template <typename T>
T Orbital<T>::pop() {
    T value = ss[numOfElementsp%capacity].pop();
    numOfElementsp++;
    return value;
}

template <typename T>
void Orbital<T>::print() {
    for (int i = 0; i < capacity; ++i) {  //node 1 ->[5 8]
        cout<<"Orbital "<<i+1<<" ->{"<<endl;
        ss[i].display();cout<<"}\n";
    }
}
