#ifndef CLIBRARY_H
#define CLIBRARY_H

#include "clist.h"
#include "cstudentlist.h"

class CLibrary: public CList, public CStudentList
{
private:
    CList clist;
    CStudentList cstudentlist;
    
public:
    CList& getCList()
    {
        return clist;
    }

    CStudentList& getCStudentList()
    {
        return cstudentlist;
    }

    void issueBook();
    void returnBook();
    void printIssuedBooks();
};

#endif