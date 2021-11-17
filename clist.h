#ifndef CLIST_H
#define CLIST_H

#include "cbooklist.h"

class CList
{
protected:
    struct Node
    {
        CBookList bookList;
        Node* next;
    };

    Node* head;
    Node* lastCreated;

public:
    CList() { head = NULL; lastCreated = NULL;}
    void addList();
    CBookList& searchBookList(int);
    bool existsBookList(int);
    void deleteList();
    void showList();
    void showAll();
    void moveToAnother();
    Node* getHead();
};

#endif