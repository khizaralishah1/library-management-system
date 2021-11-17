#include "clibrary.h"
#include "clist.h"
#include <iostream>
#include <iomanip>
using namespace std;

void CLibrary::issueBook()
{
    //which student is issuing the book
    int ID, bookID;
    cout << setw(40) << "Student ID: ";
    cin >> ID;

    //see if that student exists
    if (cstudentlist.existsStudent(ID))
    {
        cout << setw(40) << "Enter ID of the book you want to issue: ";
        cin >> bookID;

        //traverse through all the books of each booklist
        CList::Node *tempList = clist.getHead();
        while (tempList != NULL)
        {
            if (tempList->bookList.existsBook(bookID))
                break;
            tempList = tempList->next;
        }

        if (tempList == NULL)
            cout << setw(40) << "No such book with provided ID exists" << endl;
        else
        {
            //now tempList contains the right booklist
            CStudentList::Node *tempStdList = cstudentlist.getHead();
            while (tempStdList != NULL)
            {
                if (tempStdList->std.getID() == ID)
                {
                    tempStdList->std.issuedBook(tempList->bookList.getListID(), tempList->bookList.getBook(bookID));
                    break;
                }
                tempStdList = tempStdList->next;
            }

            tempList->bookList.deleteBook(bookID);
        }
    }
    else
    {
        cout << setw(40) << "No such student with provided data exists" << endl;
    }
    
    char a;
    cout << setw(40) << "Press any key and then enter to go back" << endl;
    cin >> a;
}
void CLibrary::returnBook()
{
    system("clear");

    cout << setw(40) << "Enter Student ID: ";
    int stdID;
    cin >> stdID;

    if (cstudentlist.existsStudent(stdID))
    {
        // cin.clear();
        // cin.ignore();

        CStudentList::Node *tempStdList = cstudentlist.getHead();
        CList::Node *tempclist = clist.getHead();

        cout << setw(40) << "Enter ID of the book to return: ";
        int bookID;
        cin >> bookID;

        while (tempStdList != NULL)
        {
            if (tempStdList->std.getID() == stdID)
            {
                CStudent::Node *tempStdIssuedList = tempStdList->std.getHead();
                CStudent::Node *back = tempStdIssuedList;

                while (tempStdIssuedList != NULL)
                {
                    if (tempStdIssuedList->issuedBook.getID() == bookID)
                    {
                        while (tempclist != NULL)
                        {
                            if (tempclist->bookList.getListID() == tempStdIssuedList->issuedBookList)
                            {
                                tempclist->bookList.addBook(tempStdIssuedList->issuedBook);
                                break;
                            }
                            tempclist = tempclist->next;
                        }
                        if(back == tempStdIssuedList) tempStdList->std.setHead(tempStdIssuedList->next);
                        
                        back->next = tempStdIssuedList->next;
                        break;
                    }

                    back = tempStdIssuedList;
                    tempStdIssuedList = tempStdIssuedList->next;
                }

                if (tempStdIssuedList == NULL)
                    cout << "Book with provided ID was not issued. So it cannot be returned" << endl;

                break;
            }
            tempStdList = tempStdList->next;
        }
    }

    char a;
    cout << setw(40) << "Press any key and then enter to go back" << endl;
    cin >> a;
}
void CLibrary::printIssuedBooks()
{
    CStudentList::Node *tempStdList = cstudentlist.getHead();

    //go through the student list, and print the issued books of each student
    while (tempStdList != NULL)
    {
        tempStdList->std.printIssuedBooks();

        tempStdList = tempStdList->next;
    }

    char a;
    cout << setw(40) << "Press any key and then enter to go back" << endl;
    cin >> a;
}