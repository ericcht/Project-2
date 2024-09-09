// stl.cpp

#include "volsort.h"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void stl_sort(List &l, bool numeric)
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
        sort(sorted.begin(), sorted.end());

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
        sort(stringSorted.begin(), stringSorted.end());

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
