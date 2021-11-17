#ifndef CBOOKLIST_H
#define CBOOKLIST_H

#include "cbook.h"

class CBookList
{
private:
    struct Node
    {
        CBook book;
        Node* next;
    };

    Node* lastCreated;
    Node* head;
    int listID;
    int size;

public:
    //CBookList(CBook, int);
    CBookList();
    void addBook(CBook&);
    void addBook();
    void showBook();
    void deleteBook();
    void deleteBook(int);
    void sortAscending();
    void sortDescending();
    void searchBook(int );
    void printAll(bool=false, int=-1); //  int as arguments means printing through list with list id as given int
    void setListID();
    int getListID();
    bool existsBook(int);
    CBook& getBook(int);
};


#endif