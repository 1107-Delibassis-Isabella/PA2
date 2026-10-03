#include <iostream> 
#include "arraylist.h"
#include "linkedlist.h"


template <template <typename> class ListType>
bool testDriver(const char* listName) {
    

    //Construct an empty list
    ListType<int> list;
    list.clear();
    if (list.getLength()!= 0) {
        return false;
    }

    //Insert at the beginning
    list.addElement(12, 0);
    list.addElement(25, 0);
    if (list.getLength() != 2) {
        return false; 
    }

    //Adding extra elements to insert elements in the middle
    list.addElement(86, 0);
    list.addElement(29, 1);
    if (list.getLength() != 4) {
        return false; 
    }


    //Insert at the middle
    list.addElement(89, 2);
    list.addElement(70, 3);
    if (list.getLength() != 6) {
        return false; 
    }


    //Insert at the end
    list.addElement(77, 5);
    list.addElement(6, 6);
    if (list.getLength() != 8) {
        return false; 
    }


    //Remove a first element
    list.removeElement(0);
    if (list.getLength() != 7) {
        return false; 
    }

    //Remove a middle element
    list.removeElement(4);
    if (list.getLength() != 6) {
        return false; 
    }

    //Remove an end element
    list.removeElement(5);
    if (list.getLength() != 5) {
        return false; 
    }

    //Access every valid index
    bool validOrInvalid;
    for (int i = 0; i < list.getLength(); i++) {
        validOrInvalid = list.accessIndex(i);
    }
    if (validOrInvalid == false) {
        return false; 
    }

    //Attempt to access an invalid index
    validOrInvalid = list.accessIndex(17);
    if (validOrInvalid != false) {
        return false; 
    }

    //Clear empty list
    ListType<int> emptyList;
    emptyList.clear();
    if (list.getLength()!= 0) {
        return false;
    }

    //Clear nonempty list
    //Using the same list
    list.clear();
    if (list.getLength()!= 0) {
        return false;
    }

    //Reuse a list after calling clear();
    list.addElement(89, 0);
    list.addElement(98, 1);
    if (list.getLength()!= 2) {
        return false;
    }

    //Trigger a multiple array resizes
    list.setLength(8);
    list.setLength(6);
    if (list.getLength()!= 6) {
        return false;
    }

    //Copy an empty list
    ListType<int> secondEmptyList;
    secondEmptyList = emptyList;
    if (secondEmptyList != emptyList) {
        return false;
    }

    //Copy a nonempty list
    ListType<int> secondList;
    secondList = list;
    if (secondList != list) {
        return false;
    }

    //Modify the copy without affecting the original
    secondList.addElement(28, 1);
    if (secondList[1] == list[1]) {
        return false; 
    }

    //Assign one list to another
    ListType<int> newList;
    newList = secondList;
    if (newList.getLength() != secondList.getLength()) {
        return false;
    }

    //Destroy a nonempty list
    secondList.~secondList();


    cout << "All tests have passed" << endl;
}
