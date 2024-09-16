// qsort.cpp
/*
#include "volsort.h"

#include <cstdlib> // for qsort
#include <cstring> // for strcmp
#include <iostream>
#include <vector>

using namespace std;

// Comparison function for numeric sorting
int compare_numeric(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b;
	return (num1 - num2);
}


// Comparison function for string sorting
int compare_string(const void *a, const void *b)
{
	string *str1 = (string *)a;
	string *str2 = (string *)b;
	return strcmp(str1->c_str(), str2->c_str());
}

void qsort_sort(List &l, bool numeric)
{
	Node *current = l.head;
	vector<int> sorted;
	vector<string> stringSorted;

	if (numeric)
	{
		while (current != NULL)
		{
			sorted.push_back(current->number);
			current = current->next;
		}
		// Use qsort for numeric sorting
		qsort(&sorted[0], sorted.size(), sizeof(int), compare_numeric);

		//qsort(&sorted[0], sorted.size(), sizeof(int), node_number_compare);

		current = l.head;
		int i = 0;
		while (current != NULL)
		{
			current->number = sorted[i];
			current = current->next;
			i++;
		}
	}
	else
	{
		while (current != NULL)
		{
			stringSorted.push_back(current->string);
			current = current->next;
		}
		// Use qsort for string sorting
		qsort(&stringSorted[0], stringSorted.size(), sizeof(string), compare_string);

		current = l.head;
		int i = 0;
		while (current != NULL)
		{
			current->string = stringSorted[i];
			current = current->next;
			i++;
		}
	}
}
*/
//
//
// STL copied
//
//

#include "volsort.h"
#include <cstdlib>   // For qsort
#include <vector>
#include <iostream>

using namespace std;

// Comparison function for numeric sorting

int node_number_compare(const void *a, const void *b)
{
    // Cast void* to Node**
    const Node *node1 = *(const Node **)a;
    const Node *node2 = *(const Node **)b;
    
    // Compare numbers and return the result
    if (node1->number < node2->number)
        return -1;
    if (node1->number > node2->number)
        return 1;
    return 0;
}

int node_string_compare(const void *a, const void *b)
{
    // Cast void* to Node**
    const Node *node1 = *(const Node **)a;
    const Node *node2 = *(const Node **)b;

    // Compare strings using std::string's compare method
    return node1->string.compare(node2->string);
}

void qsort_sort(List &l, bool numeric)
{
    vector<Node *> nodes;

    // Traverse the list and collect all nodes into the vector
    Node *current = l.head;
    while (current != NULL)
    {
        nodes.push_back(current);
        current = current->next;
    }

    // Use qsort to sort the nodes based on numeric or string comparison
    if (numeric)
    {
        qsort(nodes.data(), nodes.size(), sizeof(Node *), node_number_compare);
    }
    else
    {
        qsort(nodes.data(), nodes.size(), sizeof(Node *), node_string_compare);
    }

    // Reconstruct the linked list from the sorted vector
    l.head = nodes.empty() ? nullptr : nodes[0];
    current = l.head;

    for (size_t i = 1; i < nodes.size(); i++)
    {
        current->next = nodes[i];
        current = current->next;
    }

    // Ensure the last node points to NULL
    if (current != nullptr)
    {
        current->next = nullptr;
    }
}
