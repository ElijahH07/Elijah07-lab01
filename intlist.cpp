// intlist.cpp
// Implements class IntList
// Elijah Hargreaves 1/6/25

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) : head(nullptr), tail(nullptr)  {
    *this = source;
}

// destructor deletes all nodes
IntList::~IntList() {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node *temp = head;
    while (temp) {
        sum += temp->info;
        temp = temp->next;
    }
    return sum;
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    Node *temp = head;
    while (temp) {
        if (temp->info == value) {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    int max = 0;
    Node *temp = head;
    while (temp) {
        if (temp->info > max) {
            max = temp->info;
        }
        temp = temp->next;
    }
    return max;
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double sum = 0;
    double count = 0;
    Node *temp = head;
    while (temp) {
        sum += temp->info;
        count += 1;
        temp = temp->next;
    }
    if (count == 0) {
        return 0;
    }
    return sum/count;
}

// inserts value as new node at beginning of list
void IntList::push_front(int value) {
    Node *temp = new Node();
    temp->info = value;
    temp->next = head;
    head = temp;
}

// append value at end of list
void IntList::push_back(int value) {
    Node *temp = new Node();
    temp->next = nullptr;
    temp->info = value;
    if (tail) {
        tail->next = temp;
        tail = temp;
    } else {
        head = temp;
        tail = temp;
    }

}

// return count of values
int IntList::count() const {
    int count = 0;
    Node *temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}


//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    if (this == &source) {
        return *this;
    }
    //delete self data
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;

    //assign new data to self from source
    Node *original = source.head;
    if (original == nullptr) {
        return *this;
    }

    while(original) {
        push_back(original->info);
        original = original->next;
    }
    return *this;
}

// constructor sets up empty list
IntList::IntList(){ 
    head = nullptr;
    tail = nullptr;
}


// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = head;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

