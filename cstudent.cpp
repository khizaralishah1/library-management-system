#include "cstudent.h"
#include <iostream>
#include <iomanip>
using namespace std;

int CStudent::size = 0;

CStudent::CStudent(string name, int idNum, int roll, int booksIssu)
{
    stdName = name;
    id = idNum;
    rollNo = roll;
    booksIssued = booksIssu;
    size++;
}
void CStudent::setStdName()
{
    cout << setw(45) << "Student Name: ";
    cin >> stdName;
}
void CStudent::setID()
{
    cout <<  setw(43) << "Student ID: ";
    cin >> id;
}
void CStudent::setrollNo()
{
    cout <<  setw(48) << "Student Roll No: ";
    cin >> rollNo;
}

void CStudent::setBooksIssued()
{
    cout <<  setw(62) << "Total Books Issued by Student: ";
    cin >> booksIssued;
}

int CStudent::getID()
{
    return id;
}

int CStudent::getRollNo()
{
    return rollNo;
}

void CStudent::printAll()
{
    cout << setw(36) << "Student Name: " << stdName << endl
         << setw(34) << "Student ID: " << id << endl
         << setw(39) << "Student Roll No: " << rollNo << endl
         << setw(53) << "Total Books Issued by Student: " << booksIssued << endl << endl;
}

CStudent::~CStudent()
{
    size--;
}

void CStudent::setHead(Node* ptr) 
{
    head = ptr;
}

void CStudent::issuedBook(int list, CBook& mybook)
{
    Node* newNode = new Node;
    newNode->issuedBookList = list;
    newNode->issuedBook = mybook;
    newNode->next = NULL;

    if(head == NULL) head = newNode;
    else lastCreated->next = newNode;

    lastCreated = newNode;
    booksIssued++;
}

void CStudent::printIssuedBooks()
{
    if(head == NULL)
        return;

    cout << "Student ID: " << id << endl;
    
    Node* temp = head;
    while(temp != NULL)
    {
        cout << "List " << temp->issuedBookList << ". Book: " << endl;
        temp->issuedBook.printAll();
        temp = temp->next;
    }
}

CStudent::Node* CStudent::getHead()
{
    Node* temp = head;
    return temp;
}