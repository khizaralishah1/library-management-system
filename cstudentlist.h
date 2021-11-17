#ifndef CSTUDENTLIST_H
#define CSTUDENTLIST_H

#include "cstudent.h"
#include <iomanip>
using namespace std;

class CStudentList: public CStudent
{
protected:
    struct Node
    {
        CStudent std;
        Node* next;
    };

    Node* lastCreated;
    Node* head;

public:
    CStudentList();
    void addStudent();
    void showStudent();
    void deleteStudent();
    void printAll();
    bool existsStudent(int);
    void searchStudent(int);
    Node* getHead();    

    ~CStudentList();
};

#endif