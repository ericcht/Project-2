// qsort.cpp

#include "volsort.h"

#include <cstdlib>
#include <array>
#include <iostream>



void qsort_sort(List &l, bool numeric) {
	
	
	/* STL SORT COPIED
	 * Change STL sort call to Qsort call 
	 * Create compare fxn for int and string
	 */
	
	//Functions needed for qsort
	/*
	int compareint (const void * a, const void * b)
	{
		return ( *(int*)a - *(int*)b );
	}

	int comparestring (const void *arg1, const void *arg2) {
		return strcmp( *(char * const *) arg1, *(char * const *) arg2);
	}
	*/

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
		// differs from STL
        qsort(sorted.begin(), sorted.end(), compareint());
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
		// differs from STL
        qsort(stringSorted.begin(), stringSorted.end(), comparestring());
        current = l.head;

        int i = 0;
        while (current != NULL)
        {
            current->string = sorted[i];
            current = current->next;
            i++;
        }
    }

	// end of STL paste

}

