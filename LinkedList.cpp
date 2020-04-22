// LinkedList.cpp
// Created by:  Isabella Andrews
// Student No.: C3204936
// Program:     Bachelor of Software Engineering (Honours)
// Updated on:  18-04-2020

#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"

// Constructors and Destructor
LinkedList::LinkedList() {
    head = NULL;        // head, tail and current pointers are set to NULL
    tail = NULL;
    current = NULL;
    length = 0;         // length set to 0
}

    LinkedList::LinkedList(value_type &data) {
    head = new Node(data);
    if (tail == NULL){
        tail = head;    // if list was previously empty tail is set to head
    }
    current = head;     // current is set to head
    length++;           // length is incremented
}

LinkedList::~LinkedList() {
    while (head != NULL){
        Node* tempNode;     // temporary node is created
        tempNode = head;
        head = head->getNext();
        if(head != NULL){
            head->setPrevious(NULL);
        }
        else{
            tail = NULL;
        }
        delete tempNode;    // temporary node is deleted
    }
    length = 0;             // list length is set to 0, list is empty
}

// Creates Linked Lists l1 and l2 from string data
void LinkedList::add(const value_type &data) {
    istringstream is(data); // input to be read
    value_type word;        // local variable declaration where input string is stored
    while(getline(is, word, ' '))   // delimitation character is whitespace, i.e. ' '
    {
        if(head == NULL){           // list is empty
            head = new Node(word);  // creates new node
            tail = head;            // sets tail to head
            current = head;         // sets current to head
            length = 1;             // length is incremented
        }
        else{                       // list is not empty
            Node* newNode = new Node(word); // creates new node
            tail->setNext(newNode); // sets next pointer of tail node to new node
            newNode->setPrevious(tail); // sets previous pointer of new node to tail node
            tail = newNode;         // sets tail to new node
            newNode = NULL;         // sets new node to NULL
            length++;               // length is incremented
        }

    }

}

// Removes specified words from a linked list
void LinkedList::remove(const value_type &word) {
    current = head;             // sets current to the head of the list
    while (current != NULL){
        if(word == current->getData() && current == head){  // word to be removed is stored in the head node
            Node* tempNode;     // temporary node is created
            tempNode = head;    // temporary node is set to head
            head = head->getNext(); // head is set to the next node in the list
            if (head != NULL) {
                head->setPrevious(NULL); // previous pointer of new head node is set to NULL
            }
            else{
                head = NULL;    // list is empty
            }
            delete tempNode;    // temporary node is deleted
            length--;           // length is decremented
            current = NULL;     // current is set to NULL
        }
        else if(word == current->getData() && current == tail){ // word to be removed is stored in the tail node
            Node* tempNode;     // temporary node is created
            tempNode = tail;    // temporary node is set to tail
            tail = tempNode->getPrevious(); // tail is set to the previous node in the list
            if (tail != NULL){
                tail->setNext(NULL);    // next pointer of the new tail node is set to NULL
            }
            else{
                head = NULL;    // list is empty
            }
            delete tempNode;    // temporary node is deleted
            length--;           // length is decremented
            current = NULL;     // current is set to NULL
        }
        else if (word == current->getData()){   // word to be removed is stored in the current node
            Node* tempNode;     // temporary node is created
            tempNode = current->getPrevious();  // temporary node is set to the previous node in the list
            tempNode->setNext(current->getNext());  // next pointer of temporary node is set to current nodes next pointer
            tempNode = current->getNext();      // temporary node is set to the current nodes next node
            tempNode->setPrevious(current->getPrevious());  // previous pointer of temporary node is set the current nodes previous pointer
            delete current;     // current node is deleted
            current = tempNode; // current node is set to temporary node
            length--;           // length is decremented
        }
        else {
            current = current->getNext();   // word to be removed is not stored in the current node, current node is moved to next node in the list
        }
    }
}

// Counts the number of times a word occurs in a linked list
int LinkedList::count(const value_type &wordCount) {
    head = current;             // head is set to current node
    int num = 0;                // local int variable where word count is stored
    do{
        if (wordCount == current->getData()){   // if word to be counted is in current node
            num++;                              // word count is incremented
        }
        current = current->getNext();           // word to be counted is not in current node, move to next node
    }
    while (current != NULL);

    return num;                 // word count is returned
}

// Getters for overloaded << operator
Node* LinkedList::getHead() const {
    return head;
}

Node* LinkedList::getCurrent() const {
    return current;
}

// Setter for overloaded += operator
void LinkedList::setCurrent(Node *newCurrent) {
    current = newCurrent;
}

// Member Overloaded += Operator
LinkedList& LinkedList::operator+=(LinkedList &list) {
    do{
        this->add(list.current->getData());     // appends the data from the RHS ("that") list to the tail of LHS ("this") list
        list.setCurrent(list.getCurrent()->getNext()); // sets current node to the next node in the list
    }
    while (list.getCurrent() != NULL);
    return *this;               // returns updated list
}

// Non-member Overloaded << Operator
ostream &operator<<(ostream &output, LinkedList &list) {
    list.setCurrent(list.getHead());                    // sets current node to the head node
    do{
        output << list.getCurrent()->getData() + " ";   // prints data from the current node to screen and adds a white space
        list.setCurrent(list.getCurrent()->getNext());  // sets current node to the next node in the list
    }
    while (list.getCurrent() != NULL);
    list.setCurrent(list.getHead());                    // sets current node to the head node
    return output;              // returns the output
}
