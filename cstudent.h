#ifndef CSTUDENT_H
#define CSTUDENT_H

#include <string>
#include "cbook.h"
using namespace std;

class CStudent
{
protected:
    int id, rollNo, booksIssued;
    string stdName;
    
    struct Node
    {
        int issuedBookList; //list id
        CBook issuedBook;
        Node* next;
    };

    Node* head;
    Node* lastCreated;

protected:
    static int size;

public:
    CStudent(string="", int=0, int=0, int=0);
    void setStdName();
    void setID();
    int getID();
    void setrollNo();
    int getRollNo();
    void setBooksIssued();
    void printAll();
    void issuedBook(int, CBook&);
    void printIssuedBooks();
    Node* getHead();
    ~CStudent();
    void setHead(Node*);
};

#endif
