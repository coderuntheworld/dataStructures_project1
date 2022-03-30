// LinkedList.h
// Created by:  Isabella Andrews
// Student No.: C3204936
// Program:     Bachelor of Software Engineering (Honours)
// Updated on:  18-04-2020

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <cstdlib>
#include <string>
#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList{
    public:
        // typedef declaration inherited from Node.h
        typedef Node::value_type value_type;

        LinkedList(); // Default Constructor
        LinkedList(value_type& data); // Specific Constuctor
        ~LinkedList(); // Destructor

        // Mutator Functions for Linked List

        // Function:        Creates a new doubly linked list with data from a string
        // Precondition:    A string of data is given and the list has been initialised
        // Postcondition:   The string has been tokenized and each word from the string is
        //                  added and stored in a separate node in a doubly linked list
        void add(const value_type& data);

        // Function:        Removes nodes with specific input from the linked list
        // Precondition:    Valid input string, i.e. word
        // Postcondtion:    The nodes with the specified word are removed according to
        //                  their position in linked list
        void remove(const value_type& word);

        // Function:        Counts the occurrences of a word stored in a linked list
        // Precondition:    Nodes hold valid data, i.e. words from a string
        // Postcondition:   The number of occurrences of the word are counted and returned
        int count(const value_type& wordCount);

        // Function:        Returns the "head" node
        // Precondition:    "head" is set to a valid node
        // Postcondition:   "head" is returned
        Node* getHead();

        // Function:        Returns the "current" node
        // Precondition:    "current" is set to a valid node
        // Postcondition:   "current" is returned
        Node* getCurrent();

        void setHead(Node* newHead);

        // Function:        Sets the "current" node
        // Precondition:    A valid node is specified
        // Postcondition:   "current" is set to the specified node
        void setCurrent(Node* newCurrent);

        // Member Overloaded Operator:  Appends nodes from one linked list to the end of
        //                              another linked list
        // Precondition:                Both lists are valid linked lists
        // Postcondition:               Linked list on the LHS now has the nodes of the
        //                              list on RHS appended to it's tail node
        LinkedList& operator += (LinkedList& list);

private:
        Node* head;     // "head" pointer
        Node* tail;     // "tail" pointer
        Node* current;  // "current" pointer
        int length;     // holds the length value of the linked list
};

// Non-member Overloaded Operator:      Prints the data stored in each node of a linked list
// Precondition:                        The list is a valid linked list
// Postcondition:                       The linked list is printed to screen
ostream& operator << (ostream& output, LinkedList& list);

#endif // LINKEDLIST_H
