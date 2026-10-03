#include "arraylist.h"

template <typename T>
ArrayList<T>::ArrayList() {
    length = 0;
    capacity = 1;
    data = new T[capacity];
}

template <typename T>
ArrayList<T>::ArrayList(int initialCapacity) {
    capacity = initialCapacity;
    data = new T[capacity];
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList& other) {
    //data = other.data;
    length = other.length;
    capacity = other.capacity;
    data = new T[capacity];
    for (int i = 0; i < length; i++) {
        data[i] = other.data[i];
    }
}
template <typename T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList& other) {
            data = other.data;
            length = other.length;
            capacity = other.capacity;
            data = new T[capacity];
            for (int i = 0; i < length; i++) {
                data[i] = other.data[i];
            }

            return *this;
}

template <typename T>
ArrayList<T>::~ArrayList() {
            delete [] data;
        }

        //Required List operations

template <typename T>
int ArrayList<T>::getCapacity() {
    return capacity;
}

template <typename T>
int ArrayList<T>::getLength() {
    return length;
}

template <typename T>
void ArrayList<T>::addElement(T* element, int position) {
    if (position < 0 || position > length) {
        cout << "Out of bounds" << endl;
    } else {
        if (length == capacity) {
        resize(2*capacity);
    } 
    T* temp = new T[capacity];
    for (int i = 0; i < length+1; i++) {
        if (i >= position) {
            if (i == position) {
                temp[i] = element;
            } else {
                if (i == length) {
                    temp[length] = data[length-1];
                } else {
                    temp[i] = data[i-1];
                }
            }
        } else {
            temp[i] = data[i];
        }
    }
    delete [] data;
    data = temp;
    length++; 
    }

}

template <typename T>
void ArrayList<T>::removeElement(int position) {
    if (position < 0 || position > length) {
        cout << "Out of bounds" << endl;
    } else {
        T* temp = new T[capacity];
        int tempCount = 0;
        for (int i = 0; i < length; i++) {
            if (i > position) {
                temp[tempCount] = data[i];
                tempCount++;
            } else if (i < position){
                temp[i] = data[i];
                tempCount++;
            }
        }

    }
}

template <typename T>
void ArrayList<T>::resize(int newCapacity) {
    T* temp = new T[newCapacity];
    for (int i = 0; i < length; i++) {
        temp[i] = data[i];
    }
    delete [] data;
    data = temp;
    capacity = newCapacity;
}

