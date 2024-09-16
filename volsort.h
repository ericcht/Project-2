// volsort.h

#ifndef VOLSORT_H
#define VOLSORT_H

#include <string>

struct Node
{
  std::string string;
  int number;
  Node *next;
};

struct List
{
  Node *head;
  size_t size;

  List();  // define in list.cpp
  ~List(); // define in list.cpp

  void push_front(const std::string &s)
  {
    Node *newNode = new Node();
    newNode->string = s;

    // Error checking stoi - https://cplusplus.com/forum/beginner/253696/
    try
    {
      newNode->number = std::stoi(s);
    }
    catch (const std::exception &e)
    {
      newNode->number = 0;
    }
    newNode->next = head;
    head = newNode;
    size++;
  }
};

// Functions -------------------------------------------------------------------

bool node_number_compare(const Node *a, const Node *b);
bool node_string_compare(const Node *a, const Node *b);

void dump_node(Node *n); // implement in this file (volsort.h) to make it easier for TAs to grade

void stl_sort(List &l, bool numeric);   // define in stl.cpp - sort using std::sort
void qsort_sort(List &l, bool numeric); // define in qsort.cpp - sort using qsort from cstdlib
void merge_sort(List &l, bool numeric); // define in merge.cpp - your implementation
void quick_sort(List &l, bool numeric); // define in quick.cpp - your implementation

#endif
