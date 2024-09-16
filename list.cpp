#include "volsort.h"

/*struct List {
    Node       *head;
    size_t      size;

    List(); 					// define in list.cpp
    ~List();					// define in list.cpp

  //    void push_front(const std::string &s);	//define below
};*/

List::List()
{
    head = NULL;
    size = 0;
}

List::~List()
{
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
}
bool node_number_compare(const Node *a, const Node *b)
{
    return a->number < b->number;
}
bool node_string_compare(const Node *a, const Node *b)
{
    return a->string < b->string;
}
