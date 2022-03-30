// Node.h
// Created by:  Isabella Andrews
// Student No.: C3204936
// Program:     Bachelor of Software Engineering (Honours)
// Updated on:  18-04-2020

#ifndef NODE_H
#define NODE_H

#include <cstdlib>
#include <string>

using namespace std;

class Node{
    public:
        // Create typdef for string values
        typedef string value_type;

        // Default Constructor
        Node();

        // Specific Constructor, d = data item, n = next, p = previous
        Node(const value_type& d, Node* n = NULL, Node* p = NULL);

        // Destructor
        ~Node();

        // Mutator Functions for Nodes

        // Function:        Sets the nodes data
        // Precondition:    A valid data item was given
        // Postcondition:   Data now has the given value
        void setData(const value_type& d);

        // Function:        Sets the next pointer
        // Precondition:    The next pointer is set to a node or NULL
        // Postcondition:   The next pointer is now pointing to the given node
        void setNext(Node* n);

        // Function:        Sets the previous pointer
        // Precondition:    The previous pointer is set to a node or NULL
        // Postcondition:   The previous pointer is now pointing to the given node
        void setPrevious(Node* p);

        // Accessor Functions for Nodes

        // Function:        Gets the value of "data"
        // Precondition:    A valid data item is held in "data"
        // Precondition:    The data item in "data" is returned
        value_type getData() const;

        // Function:        Gets the pointer held in "next"
        // Precondition:    A valid pointer or NULL is held in "next"
        // Postcondition:   The pointer for "next" is returned
        Node* getNext() const;

        // Function:        Gets the pointer held in "previous"
        // Precondition:    A valid pointer or NULL is held in "previous"
        // Postcondition:   The pointer for "previous" is returned
        Node* getPrevious() const;

    private:
        // Members
        value_type data; // points to payload value
        Node* next; // pointer to next node or NULL
        Node* previous; // pointer to previous node or NULL
    };

#endif //NODE_H
