// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void stl_sort(List &l, bool numeric)
{
    vector<Node *> nodes;

    // Traverse the list and collect all nodes into the vector
    Node *current = l.head;
    while (current != NULL)
    {
        nodes.push_back(current);
        current = current->next;
    }

    // Sort the vector based on numeric or string comparison
    if (numeric)
    {
        sort(nodes.begin(), nodes.end(), node_number_compare);
    }
    else
    {
        sort(nodes.begin(), nodes.end(), node_string_compare);
    }

    l.head = nodes[0]; // Set the head to the first node in the sorted vector
    current = l.head;

    for (size_t i = 1; i < nodes.size(); i++)
    {
        current->next = nodes[i];
        current = current->next;
    }

    current->next = NULL;
}
