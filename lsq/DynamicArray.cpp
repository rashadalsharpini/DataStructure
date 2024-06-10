//
// Created by rashadalsharpini on 25/12/23.
//

#include "DynamicArray.h"
template class DynamicArray<int>;
template class DynamicArray<double>;
template class DynamicArray<float>;
template class DynamicArray<size_t>;
template class DynamicArray<string>;
template class DynamicArray<char>;
template class DynamicArray<bool>;
template class DynamicArray<student>;
template<typename T>
DynamicArray<T>::DynamicArray() {
    size = 0;
    capacity = 2;
    data = new T[capacity];
}


template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &other)
: size(other.size), capacity(other.capacity) {
    data = new T[capacity];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

template<typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray<T> &other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template<typename T>
void DynamicArray<T>::resize() {
    size_t new_capacity = std::max(2 * (int)size, 2);
    T* brr = new T[new_capacity];
    for (int i = 0; i < size; i++)
        brr[i] = data[i];
    delete[] data;
    data = brr;
    capacity = new_capacity;

}

template<typename T>
T &DynamicArray<T>::operator[](size_t index) {
    if (index >= capacity) {
        throw std::out_of_range("Index out of range");
    }
    resize();////
    return data[index];
}

template<typename T>
size_t DynamicArray<T>::getsize() const {
    return size;
}

template<typename T>
void DynamicArray<T>::insertEnd(const T &value) {
    if (size == capacity) {
        resize();
    }
    data[size++] = value;

}

template<typename T>
void DynamicArray<T>::display() {
    for (int i = 0; i < size; ++i) {
        cout<<data[i];
    }
}

template<typename T>
void DynamicArray<T>::insertFront(const T& value) {
    if (size == capacity) {
        resize();
    }
    // Shift elements to the right
    for (size_t i = size; i > 0; --i) {
        data[i] = data[i - 1];
    }
    data[0] = value;
    size++;
}

template<typename T>
void DynamicArray<T>::removeEnd() {
    if (size > 0) {
        size--;
        if (size < 3 * capacity) {
            resize();
        }
    }
}

template<typename T>
void DynamicArray<T>::removeFront() {
    if (size > 0) {
        // Shift elements to the left
        for (size_t i = 0; i < size - 1; i++) {
            data[i] = data[i + 1];
        }
        size--;
        if (size < 3 * capacity) {
            resize();
        }
    }
}

template<typename T>
void DynamicArray<T>::insert_nth(size_t index, const T& value) {
    if (index > size || index < 0) {
        throw std::out_of_range("Index out of range");
    }

    if (size == capacity) {
        resize();
    }

    // Shift elements to the right to make space for the new element
    for (size_t i = size; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    size++;
}

template<typename T>
void DynamicArray<T>::delete_nth(size_t index) {
    if (index >= size || index < 0) {
        throw std::out_of_range("Index out of range");
    }

    // Shift elements to the left to fill the gap left by the removed element
    for (size_t i = index; i < size - 1; i++) {
        data[i] = data[i + 1];
    }
    size--;
    if (size * 3 <  capacity) {
        resize();
    }
}