#include "Node.h"
template <typename T>
Node<T>::Node(T* newData) {
    data = newData;
    next = nullptr;
}