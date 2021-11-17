#include "cbooklist.h"
#include <iomanip>
#include <iostream>
using namespace std;
// CBookList::CBookList(CBook myBooks, int idOfList = 0)
// {
//     books = myBooks;
//     listID = idOfList;
// }

void CBookList::sortAscending()
{
    Node *newHead = head;
    Node *prev = head;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            Node *temp = head->next;
            if (head->book.getName() > temp->book.getName())
            {
                head->next = temp->next;
                temp->next = head;

                if (j != 0)
                    prev->next = temp;

                prev = temp;
            }
            else
            {
                prev = head;
                head = head->next;
            }

            if (j == 0)
                newHead = prev;
        }
        head = newHead;
        prev = head;
    }
}

void CBookList::sortDescending()
{
    Node *newHead = head;
    Node *prev = head;

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            Node *temp = head->next;
            if (head->book.getName() < temp->book.getName())
            {
                head->next = temp->next;
                temp->next = head;

                if (j != 0)
                    prev->next = temp;

                prev = temp;
            }
            else
            {
                prev = head;
                head = head->next;
            }

            if (j == 0)
                newHead = prev;
        }
        head = newHead;
        prev = head;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------------------
CBookList::CBookList()
{
    head = NULL;
    size = 0;
}

void CBookList::addBook()
{
    cout << setw(49) << "ADDING NEW BOOK\n\n\n";

    Node *newNode = new Node;
    newNode->book.setName();
    // newNode->book.setAuthor();

    // newNode->book.setISBN();
    // newNode->book.setReturnDate();
    // newNode->book.setIssueDate();
    // newNode->book.setIssuedBy();
    // newNode->book.setPrice();
    // newNode->book.setPages();

    //id must be unique
    while (true)
    {
        newNode->book.setID();
        Node *temp = head;
        while (temp != NULL)
        {
            if(temp->book.getID() == newNode->book.getID())
            {
                cout << setw(40) << "ID must be unique. Try again.\n\n";
                break;
            }
            temp = temp->next;
        }
        if(temp == NULL) break;
    }

    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else
        lastCreated->next = newNode;

    lastCreated = newNode;
    size++;
}

void CBookList::showBook()
{
    cout << setw(49) << "SHOWING A BOOK\n\n\n";
    searchBook(0);
}

void CBookList::deleteBook()
{
    cout << setw(49) << "DELETING A BOOK\n\n\n";
    searchBook(1);
    size--;
}

void CBookList::searchBook(int deleteIt)
{
    //deleteIt = 1 means delete, deleteIt=0 means show that book but do not delete

    //type = 1 means search by id, and type=2 means search by ISBN
    cout << setw(59) << "How will you search for the book? ";
    cout << setw(48) << "1. ID" << endl
         << setw(29) << "2. ISBN" << endl
         << endl;
    int type;
    cout << setw(35) << "Your Choice: ";
    cin >> type;

    if (type == 1)
        cout << endl
             << setw(40) << "Enter Book ID: ";
    else if (type == 2)
        cout << endl
             << setw(45) << "Enter Book ISBN: ";

    int data;
    cin >> data;
    cin.clear();
    cin.ignore();

    Node *temp = head;
    Node *lastVisited = head;

    while (temp != NULL && !((type == 2 && data == temp->book.getISBN()) || (type == 1 && data == temp->book.getID())))
    {
        lastVisited = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << endl
             << setw(40) << "There is no Book with the provided data" << endl;
    }
    else if (deleteIt == 1)
    {
        if (head->next == NULL)
            head = NULL;
        lastVisited->next = temp->next;
    }
    else if (deleteIt == 0)
    {
        cout << endl
             << endl;
        temp->book.printAll();
    }

    //pause
    char c;
    cout << "Press any key and enter to go back...";
    cin >> c;
}

void CBookList::printAll(bool cond, int checkID)
{
    if (checkID != -1)
        cout << setw(40) << "PRINTING ALL BOOKS IN LIST WITH LIST ID " << checkID << "\n\n\n";
    else
    {
        system("clear");
        cout << setw(40) << "PRINTING ALL BOOKS\n\n\n";
    }

    Node *temp = head;
    int i = 1;

    while (temp != NULL)
    {
        cout << "Book " << i << endl;
        temp->book.printAll();
        temp = temp->next;
        i++;
        cout << "\n\n";
    }

    //waiting (so that function does not finish very fast)
    if (checkID == -1 && cond == false)
    {
        char a;
        cout << "\n\n\nPress any key to go back";
        cin >> a;
    }
}

void CBookList::setListID()
{
    cout << setw(40) << "Enter Book List ID: ";
    cin >> listID;
}

int CBookList::getListID()
{
    return listID;
}

bool CBookList::existsBook(int id)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->book.getID() == id)
            return true;
        temp = temp->next;
    }
    return false;
}

CBook &CBookList::getBook(int id)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->book.getID() == id)
            break;
        temp = temp->next;
    }
    return temp->book;
}

void CBookList::addBook(CBook &book)
{
    Node *newNode = new Node;
    newNode->book = book;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else
        lastCreated->next = newNode;

    lastCreated = newNode;
    size++;
}

void CBookList::deleteBook(int id)
{
    Node *temp = head;
    Node *back = head;

    while (temp != NULL)
    {
        if (temp->book.getID() == id)
        {
            if (temp == head)
            {
                head = temp->next;
                break;
            }

            if (temp->next == NULL)
                lastCreated = back;
            back->next = temp->next;

            break;
        }
        back = temp;
        temp = temp->next;
    }
    size--;
}