#include <iostream>
#include <iomanip>
#include "clist.h"
using namespace std;

void CList::addList()
{
    Node *newNode = new Node;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else
        lastCreated->next = newNode;

    newNode->bookList.setListID();

    lastCreated = newNode;
}

CBookList &CList::searchBookList(int id)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->bookList.getListID() == id)
            break;
        temp = temp->next;
    }
    return temp->bookList;
}

bool CList::existsBookList(int id)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->bookList.getListID() == id)
            return true;
        temp = temp->next;
    }
    return false;
}

void CList::deleteList()
{
    int id;
    cout << "Enter the ID of the book list you want to delete: ";
    cin >> id;

    Node *temp = head;
    Node *back = head;

    while (temp != NULL)
    {
        if (temp->bookList.getListID() == id)
        {
            if (temp->next == NULL)
                head = NULL;
            else
                back->next = temp->next;
            break;
        }
        back = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        cout << "No such book list with the provided ID exists" << endl;

    cout << "Press any key and then enter to go back" << endl;
    cin >> id;
    cin.clear();
    cin.ignore();
}

void CList::showList()
{
    int id;
    cout << "Enter the ID of the list to show: ";
    cin >> id;

    if (!existsBookList(id))
    {
        cout << "No such book list with the provided ID exists" << endl;
        cout << endl
             << "Press any key and then enter to go back" << endl;
        cin >> id;
    }
    else
    {
        CBookList &bookList = searchBookList(id);
        bookList.printAll(false, id);
    }
}

void CList::showAll()
{
    Node *temp = head;

    while (temp != NULL)
    {
        temp->bookList.printAll(true, temp->bookList.getListID());
        temp = temp->next;
    }

    cout << endl
         << endl
         << "Press any key and then enter to go back...";
    char a;
    cin >> a;
}

void CList::moveToAnother()
{
    system("clear");

    int sourceID, desigID, bookID;

    cout << setw(40) << "Enter list ID from where you want to take the book (source): ";
    cin >> sourceID;

    Node *source = head;

    if (!existsBookList(sourceID))
        cout << setw(40) << "No such book list with provided ID exists" << endl;

    else // source book list exists
    {   
        while (source != NULL)
        {
            if (source->bookList.getListID() == sourceID)
                break;
            source = source->next;
        }
        
        cout << endl
             << endl
             << endl
             << setw(40) << "Enter Book ID: ";
        cin >> bookID;

        if (!(source->bookList.existsBook(bookID)))
            cout << setw(40) << "No such book with provided ID exists" << endl;

        else // book exists
        {
            CBook& bookInSource = source->bookList.getBook(bookID);
            
            cout << setw(40) << "Enter destination list ID: ";
            cin >> desigID;

            if (!existsBookList(desigID))
                cout << setw(40) << "No such book list with provided ID exists" << endl;
            else // destination list exists
            {
                Node* desig = head;
                while(desig != NULL)
                {
                    if( desig->bookList.getListID() == desigID)
                        break;
                    desig = desig->next;
                }

                desig->bookList.addBook(bookInSource);

                source->bookList.deleteBook(bookID);       
            }
        }
    }
}

CList::Node* CList::getHead()
{
    Node* temp = head;
    return temp;
}