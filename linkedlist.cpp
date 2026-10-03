#include "linkedlist.h"
#include "Node.h"

template <typename T>
LinkedList<T>::LinkedList() {
    length = 1;
    head = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& other) {
    if (other.head == nullptr) {
        head = nullptr;
    } else {
        head = new Node<T>(other.head->data);
        Node<T>* curr = other.head->next;
        Node<T>* newCurr = head;
        
        while (curr != nullptr) {
            newCurr->next = new Node<T>(curr->data);
            newCurr = newCurr->next;
            curr = curr->next;
        }
    }
    length = other.length;
    
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other) {
    /*length = other.length;
    head = other.head;*/
    if (other.head == nullptr) {
        head = nullptr;
    } else {
        head = new Node<T>(other.head->data);
        Node<T>* curr = other.head->next;
        Node<T>* newCurr = head;
        
        while (curr != nullptr) {
            newCurr->next = new Node<T>(curr->data);
            newCurr = newCurr->next;
            curr = curr->next;
        }
    }
    length = other.length;
    return *this;
 }

 template <typename T>
int LinkedList<T>::getLength() {
    return length;
}

template <typename T>
LinkedList<T>::~LinkedList() {
    delete [] head; 
}


//
template <typename T>
void LinkedList<T>::addElement(Node<T>* added, int position) {
    if (position < 0) {
        //out of bounds
        cout << "Out of bounds" << endl;
        return;
    }
    
    if (position == 0) {
        head = new Node<T>(added, head);
        length++;
        return;
    }
    

    Node<T>* curr = head;
    for (int i = 0; i < (position - 1); i++) {
        curr = curr->next;
    }
    
    curr->next = new Node<T>(added, curr->next);
    length++;
    return;
}

template <typename T>
void LinkedList<T>::removeElement(int position) {
    if (position < 0) {
        cout << "Out of bounds for removing an element" << endl;
    }
    if (position == 0) {
        Node<T>* temp = head;
        head = head->next;
        length--;
        delete temp; 
        return;
    }
    Node<T>* prev;
    for (int i = 0; i < (position-1); i++) {
        prev = head;
        prev = prev->next; 
    }
    Node<T>* after = prev->next;
    prev->next = after->next;
    delete after;
    length--;
    return;
}

template <typename T>
void LinkedList<T>::setLength(int l) {
    length = l;
}

template <typename T>
bool LinkedList<T>::accessIndex(int i) {
    if (i < length) {
        return true;
    } else if (i >= length) {
        return false;
    }
}

template<typename T>
void LinkedList<T>::clear() {
    length = 0;
}
