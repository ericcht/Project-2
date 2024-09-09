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
    if (head == NULL || head->next == NULL)
    {
        left = head;
        right = NULL;
        return;
    }

    Node *slow = head;
    Node *fast = head;

    // slow fast pointer technique
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    left = head;
    right = slow->next;
    slow->next = NULL;
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
