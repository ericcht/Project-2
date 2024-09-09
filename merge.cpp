// merge.cpp

#include "volsort.h"

#include <iostream>

// Prototypes

Node *msort(Node *head, bool numeric);
void split(Node *head, Node *&left, Node *&right);
Node *merge(Node *left, Node *right, bool numeric);

// Implementations

void merge_sort(List &l, bool numeric)
{
}

Node *msort(Node *head, bool numeric)
{
}

void split(Node *head, Node *&left, Node *&right)
{
    left = head;
    right = head;

    // slow fast pointer technique
    while (right != NULL && right->next != NULL)
    {
        left = left->next;
        right = right->next->next;
    }
}

Node *merge(Node *left, Node *right, bool numeric)
{
    Node *dummy = new Node();
    Node *tail = dummy; // dummy node to eliminate special cases

    while (left != NULL && right != NULL)
    {
        if (left->number < right->number)
        { // left is less
            tail->next = left;
            left = left->next;
        }
        else
        {
            // right is less
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }
    if (left != NULL) // if there is a remaining list just attach it
    {
        tail->next = left;
    }
    if (right != NULL)
    {
        tail->next = right;
    }
    return dummy->next; // return head node
}
