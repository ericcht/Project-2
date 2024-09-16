// qsort.cpp

#include "volsort.h"
#include <cstdlib>   // qsort
#include <vector>
#include <iostream>

using namespace std;

// numeric compare fxn

int node_number_compare(const void *a, const void *b)
{
	const Node *node1 = *(const Node **)a;
	const Node *node2 = *(const Node **)b;

	if (node1->number < node2->number)
		return -1;
	if (node1->number > node2->number)
		return 1;
	return 0;
}

// string compare fxn

int node_string_compare(const void *a, const void *b)
{
	const Node *node1 = *(const Node **)a;
	const Node *node2 = *(const Node **)b;

	return node1->string.compare(node2->string);
}

void qsort_sort(List &l, bool numeric)
{
	vector<Node *> nodes;

	// traverse and store nodes in vector
	Node *current = l.head;
	while (current != NULL)
	{
		nodes.push_back(current);
		current = current->next;
	}

	// qsort call
	if (numeric)
	{
		qsort(nodes.data(), nodes.size(), sizeof(Node *), node_number_compare);
	}
	else
	{
		qsort(nodes.data(), nodes.size(), sizeof(Node *), node_string_compare);
	}

	// rebuild w/ sorted vector

	if (nodes.empty())
		l.head = nullptr;
	else
		l.head = nodes[0];

	current = l.head;

	for (size_t i = 1; i < nodes.size(); i++)
	{
		current->next = nodes[i];
		current = current->next;
	}

	// last->null
	if (current != nullptr)
	{
		current->next = nullptr;
	}
}
