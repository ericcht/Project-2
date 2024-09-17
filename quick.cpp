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

    partition(head->next, pivot, left, right, numeric);

    pivot->next = nullptr;

    left  = qsort(left , numeric);
    right = qsort(right, numeric);

    return concatenate(left, concatenate(pivot, right));

}

void partition(Node *head, Node *pivot, Node *&left, Node *&right, bool numeric) {

    while(head) {

        Node *next = head->next;
        head->next = nullptr;

        bool compare = numeric ? node_number_compare(head, pivot) : node_string_compare(head,pivot);

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
