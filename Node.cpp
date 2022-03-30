// Node.cpp
// Created by:  Isabella Andrews
// Student No.: C3204936
// Program:     Bachelor of Software Engineering (Honours)
// Updated on:  18-04-2020

#include "Node.h"
using namespace std;

Node::Node(const value_type &d, Node *n, Node *p) {
    data = d;
    next = n;
    previous = p;
}

Node::~Node() {
    next = NULL;        // Sets "next" to NULL
    previous = NULL;    // Sets "previous" to NULL
}

// Mutator Functions (setters)
void Node::setData(const value_type &word) {
    data = word;
}

void Node::setNext(Node *nextWord) {
    next = nextWord;
}

void Node::setPrevious(Node *previousWord) {
    previous = previousWord;
}

// Accessor Functions (getters)
Node::value_type Node::getData() const {
    return data;
}

Node* Node::getNext() const {
    return next;
}

Node* Node::getPrevious() const {
    return previous;
}