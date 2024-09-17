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
    
    //Base case
    if(!head || !head->next) {
        return head;
    }

    //pviot chosen for simplicity
    Node *pivot = head;
    Node *left  = nullptr;
    Node *right = nullptr;

    // partition
    partition(head->next, pivot, left, right, numeric);

    pivot->next = nullptr;

    // recursive call
    left  = qsort(left , numeric);
    right = qsort(right, numeric);

    // combine left and right
    return concatenate(left, concatenate(pivot, right));

}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {

    while(head) {

        // separate
        Node *next = head->next;
        head->next = nullptr;

        // compare based on pivot
        bool compare = numeric ? node_number_compare(head, pivot) : node_string_compare(head,pivot);

        // assign to proper list then move to next
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

    // if left is empty return right
    if(!left) {
        return right;
    }

    // find end of left
    Node *temp = left;

    while(temp->next) {
        temp = temp->next;
    }

    // have right most of left point to leftmost of right
    temp->next = right;
    return left;

}
