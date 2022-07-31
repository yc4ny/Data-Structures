#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

// next line needed because NULL is part of std namespace
using namespace std;

class ListNode {
public:
    ListNode();                 // Constructor
    ListNode(int val);          //one parameter constructor
    ListNode(int val, ListNode *n, ListNode *p);
    ListNode* getNext();
    ListNode* getPrevious();
private:
    int value;
    ListNode *next, *previous;	// for doubly linked lists

    // List needs to be able to access/change ListNode's next and
    // previous pointers
    friend class List;

    // ListItr needs to access/change ListNode as well
    friend class ListItr;

    // Not writing a destructor is fine in this case since there is no
    // dynamically allocated memory in this class.  No constructor is
    // necessary, as an object will be set up by the List class.
};

#endif
