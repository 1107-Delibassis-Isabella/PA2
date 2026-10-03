#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"

using namespace std;


template <typename T>
class LinkedList {
    private: 
        Node<T>* head;
        int length;
    
    public: 
        LinkedList();
        LinkedList(const LinkedList& other);
        LinkedList& operator=(const LinkedList& other);

        int getLength();


        ~LinkedList();

        //
        void addElement(Node<T>*, int);
        void removeElement(int);
        void setLength(int);
        bool accessIndex(int);
        void clear();
        
}; 
#endif