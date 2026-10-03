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
    head = other.head;
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
    head = other.head;
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
void LinkedList<T>::addElement(Node<T>* n) {
    Node* newNode = new Node(length);
    if (head == nullptr) {
        head = newNode;
        return newNode;
    } else {
        
    }
    
    newNode->head = n;
    return newNode;
}
template <typename T>
void LinkedList<T>::insertPosition(Node<T>* added, int position, int val) {
    if (position < 1) {
        //out of bounds
        cout << "Out of bounds" << endl;
        return;
        //return added;
    }
    
    if (position == 1) {
        Node<T>* newNode = new Node<T>(val);
        newNode->head = added;
        return;
    }

    Node<T>* curr = added;
    for (int i = 1; i < (position - 1) && curr != nullptr; i++) {
        curr = curr->head;
    }
    if (curr == nullptr) {
        return;
    }
    Node<T>* newNode = new Node<T>(val);
    newNode->head = curr->head;
    curr->head = newNode;
    return;
}

template <typename T>
void LinkedList<T>::removePosition(int position) {
    Node<T>* temp = removed;
    if (position == 1) {
        removed = temp->next;
        delete temp; 
        return;
    }
    Node *prev = nullptr;
    for (int i = 1; i < position; i++) {
        prev = temp;
        temp = temp->next; 
    }

    prev->next = temp->next;
    delete temp;
    return;
}

