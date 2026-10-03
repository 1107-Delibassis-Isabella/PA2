#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;


template <typename T>
struct Node {
    public:
        T* data;
        Node* next;

        Node(T* newData);
};
#endif