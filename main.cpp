#include <iostream>
#include <string>
#include <iomanip>
#include "cstudentlist.h"
#include "cbooklist.h"
#include <unistd.h>
#include "clist.h"
#include "clibrary.h"
using namespace std;

int mainMenu();
void selectSubMenu(int, CLibrary&);

void studentSubMenu(CStudentList &);
void bookSubMenu(CList &);
void listSubMenu(CList &);
void librarySubMenu(CLibrary&);

void selectCListFunction(int, CList &);
void selectCLibraryFunction(int, CLibrary&);
void selectStudentListFunction(int, CStudentList &);
void selectBookListFunction(int, CBookList &);

int getChoice();

int main()
{
    CLibrary clibrary;

    while (true)
        selectSubMenu(mainMenu(), clibrary);
}

//Book
void bookSubMenu(CList &clist)
{
    system("clear");
    int lsID;

    cout << setw(40) << "Enter book list ID to go to that list of books: ";
    cin >> lsID;
    //searching through clist for that booklist
    bool check = clist.existsBookList(lsID);

    if (!check)
    {
        cout << setw(40) << "No such book list with provided list ID exits" << endl
             << endl;
        cout << setw(40) << "Press any key and then enter to go back" << endl;
        cin >> lsID;
    }
    

    cin.clear();
    cin.ignore();

    while (check)
    {
        CBookList &bookList = clist.searchBookList(lsID);
        system("clear");
        cout << setw(30) << "1. Add New Book" << endl
             << setw(30) << "2. Delete Existing Book" << endl
             << setw(30) << "3. Show Particular Book" << endl
             << setw(30) << "4. Show All Books" << endl
             << setw(30) << "5. Sort Books in Ascending Order" << endl
             << setw(30) << "6. Sort Books in Descending Order" << endl
             << setw(45) << "7. BACK" << endl
             << endl;

        cout << setw(30) << "Your Choice: ";
        // cin.clear();
        // cin.ignore();

        int choice;

        cin >> choice;

        if (choice == 7)
            return;

        selectBookListFunction(choice, bookList);
    }
}

void selectBookListFunction(int choice, CBookList &bookList)
{
    system("clear");
    switch (choice)
    {
    case 1:
        bookList.addBook();
        break;

    case 2:
        bookList.deleteBook();
        break;

    case 3:
        bookList.showBook();
        break;

    case 4:
        bookList.printAll();
        break;

    case 5:
        bookList.sortAscending();
        break;

    case 6:
        bookList.sortDescending();
        break;

    default:
        cout << "hi";
    }
}

//Student
void studentSubMenu(CStudentList &studentList)
{
    while (true)
    {
        system("clear");
        cout << setw(45) << "1. Add New Student" << endl
             << setw(53) << "2. Delete Existing Student" << endl
             << setw(53) << "3. Show Particular Student" << endl
             << setw(47) << "4. Show All Students" << endl
             << setw(34) << "5. BACK" << endl;

        cout << setw(30) << "Your Choice: ";
        cin.clear();
        cin.ignore();

        int choice;

        cin >> choice;

        if (choice == 5)
            return;

        selectStudentListFunction(choice, studentList);
    }
}

void selectStudentListFunction(int choice, CStudentList &studentList)
{
    system("clear");

    switch (choice)
    {
    case 1:
        studentList.addStudent();
        break;

    case 2:
        studentList.deleteStudent();
        break;

    case 3:
        studentList.showStudent();
        break;

    case 4:
        studentList.printAll();
        break;

    default:
        cout << "hi";
    }
}
//------------------------------------------------------------------------------------------------------------------------------------------------

int mainMenu()
{
    system("clear");
    cout << setw(37) << "1. Student" << endl
         << setw(34) << "2. Book" << endl
         << setw(34) << "3. List" << endl
         << setw(37) << "4. Library" << endl
         << setw(34) << "5. Exit" << endl
         << endl;

    return getChoice();
}

void listSubMenu(CList &clist)
{
    while (true)
    {
        system("clear");
        // cin.clear();
        // cin.ignore();
        cout << setw(30) << "1. Add New List" << endl
             << setw(30) << "2. Delete Existing List" << endl
             << setw(30) << "3. Show Particular List" << endl
             << setw(30) << "4. Show All Lists" << endl
             << setw(30) << "5. Delete Book from List and assign book to another List" << endl
             << setw(50) << "6. BACK" << endl
             << endl;

        cout << setw(30) << "Your Choice: ";

        int choice;

        cin >> choice;
        cin.clear();
        cin.ignore();

        if (choice == 6)
            return;

        selectCListFunction(choice, clist);
    }
}

void selectCListFunction(int choice, CList &clist)
{
    system("clear");
    switch (choice)
    {
    case 1:
        clist.addList();
        break;

    case 2:
        clist.deleteList();
        break;

    case 3:
        clist.showList();
        break;

    case 4:
        clist.showAll();
        break;
    case 5:
        clist.moveToAnother();
    default:
        cout << "hi";
    }
}

void librarySubMenu(CLibrary& clibrary)
{
    while (true)
    {
        system("clear");
        cin.clear();
        cin.ignore();
        cout << setw(30) << "1. Issue a Book" << endl
             << setw(30) << "2. Return a Book" << endl
             << setw(30) << "3. Print which books have been issued" << endl
             << setw(40) << "4. BACK" << endl
             << endl;

        cout << setw(30) << "Your Choice: ";

        int choice;

        cin >> choice;
        cin.clear();
        cin.ignore();

        if (choice == 4)
            return;

        selectCLibraryFunction(choice, clibrary);
    }
}

int getChoice()
{
    cout << setw(30) << "Your Choice: ";
    int choice;
    cin >> choice;
    return choice;
}

void selectSubMenu(int userChoice, CLibrary& clibrary)
{
    system("clear");

    switch (userChoice)
    {
    case 1:
        studentSubMenu(clibrary.getCStudentList());
        break;
    case 2:
        bookSubMenu(clibrary.getCList());
        break;
    case 3:
        listSubMenu(clibrary.getCList());
        break;
    case 4:
        librarySubMenu(clibrary);
        break;
    case 5:
        exit(1);
    default:
        cout << "h";
    }
}

void selectCLibraryFunction(int userChoice, CLibrary& clibrary)
{
    system("clear");

    switch (userChoice)
    {
    case 1:
        clibrary.issueBook();
        break;
    case 2:
        clibrary.returnBook();
        break;
    case 3:
        clibrary.printIssuedBooks();
        break;
    case 4:
        exit(1);
        break;
    default:
        cout << "h";
    }
}