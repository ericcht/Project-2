// qsort.cpp

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
