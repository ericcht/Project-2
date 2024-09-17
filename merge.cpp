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
    l.head = msort(l.head, numeric); // call sort on head of list
}

Node *msort(Node *head, bool numeric)
{
    if (head == NULL || head->next == NULL){ // return head if no elements or one element
        return head;
    }
    Node *left = NULL;
    Node *right = NULL;
    split(head, left, right); // split list

    left = msort(left, numeric); // recursive call to sort split lists
    right = msort(right, numeric);

    return merge(left, right, numeric); // merge halves and return them
}

void split(Node *head, Node *&left, Node *&right)
{
    if (head == NULL || head->next == NULL)
    {
        left = head;
        right = NULL;
        return;
    }

    Node *slow = head;
    Node *fast = head->next;  // start `fast` at `head->next` so slow lands at the middle

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    left = head;
    right = slow->next;
    slow->next = NULL;  // this terminates the left half of the list.
}


Node *merge(Node *left, Node *right, bool numeric)
{
    Node *dummy = new Node();
    Node *tail = dummy; // dummy node to eliminate special cases

    while (left != NULL && right != NULL)
    {
        if (numeric)
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
        }
        else
        {
            if (left->string < right->string)
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
        }
        tail = tail->next;
    }
    
    // attach the remaining nodes if any
    if (left != NULL)
    {
        tail->next = left;
    }
    if (right != NULL)
    {
        tail->next = right;
    }

    Node *result = dummy->next; // save the actual result head
    delete dummy;               // delete dummy node
    return result;              // ret the merged list
}

