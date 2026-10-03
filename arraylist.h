#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <iostream>

using namespace std;


template <typename T>
class ArrayList {
    private: 
        T* data;
        int length;
        int capacity;

        void resize(int newCapacity);
    
    public: 
        ArrayList();
        ArrayList(int initialCapacity);

        ArrayList(const ArrayList& other);
        ArrayList& operator=(const ArrayList& other);

        ~ArrayList();

        //Required List operations
        void setLength(int);
        int getCapacity();
        int getLength();
        void addElement(T*, int);
        void removeElement(int);
        bool accessIndex(int);
        void clear();
};
#endif