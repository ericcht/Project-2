// quick.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *qsort(Node *head, bool numeric);
void  partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric);
Node *concatenate(Node *left, Node *right);

// Implementations

void quick_sort(List &l, bool numeric) {
    l.head = qsort(l.head, numeric);
}

Node *qsort(Node *head, bool numeric) {
    // Base case
    if(!head || !head->next) {
        return head;
    }

    // choose pivot and create left and right lists
    Node *pivot = head; // Head choosen for simplicity
    Node *left  = nullptr;
    Node *right = nullptr;

    // divide list around the pivot
    partition(head, pivot, left, right, numeric);

    // recursivly call on left and right
    left  = qsort(left , numeric);
    right = qsort(right, numeric);

    pivot->next = right;
    
    // return sorted list
    return concatenate(left,pivot);

}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {
    while(head) {
        // separate lists
        Node *next = head->next;
        head->next = nullptr;

        bool compare = numeric ? (head->number < pivot->number) : (head->string < pivot->string);

        // sort into either the left or right
        if(compare) {
            head->next = left;
            left = head;
        } else {
            head->next = right;
            right = head;
        }

        head = next;
    }
}

Node *concatenate(Node *left, Node *right) {

    // In case left is empty
    if(!left) {
        return right;
    }

    Node *temp = left;
    while(temp->next) {
        temp = temp->next;
    }

    temp->next = right;
    return left;

}

