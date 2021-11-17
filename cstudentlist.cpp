#include "cstudentlist.h"
#include <iostream>
#include <string>
using namespace std;

string spaces(int n)
{
    return string(" ", n);
}

CStudentList::CStudentList()
{
    head = NULL;
}

void CStudentList::addStudent()
{
    cout << setw(49) << "ADDING NEW STUDENT\n\n\n";

    Node *newNode = new Node;
    newNode->std.setStdName();
    newNode->std.setrollNo();
    newNode->std.setID();
    newNode->std.setBooksIssued();
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else
        lastCreated->next = newNode;
    lastCreated = newNode;
}

void CStudentList::deleteStudent()
{
    cout << setw(49) << "DELETING A STUDENT\n\n\n";
    searchStudent(1);
    CStudent::size--;
}

void CStudentList::showStudent()
{
    cout << setw(49) << "SHOWING A STUDENT'S DATA\n\n\n";
    searchStudent(0);
}

void CStudentList::searchStudent(int deleteIt)
{
    //deleteIt = 1 means delete, deleteIt=0 means show that student but do not delete

    //type = 1 means search by id, and type=2 means search by rollNo
    cout << setw(59) << "How will you search for the student? ";
    cout << setw(48) << "1. ID" << endl
         << setw(29) << "2. Roll" << endl
         << endl;
    int type;
    cout << setw(35) << "Your Choice: ";
    cin >> type;

    if (type == 1)
        cout << endl
             << setw(40) << "Enter Student ID: ";
    else if (type == 2)
        cout << endl
             << setw(45) << "Enter Student Roll No: ";

    int data;
    cin >> data;

    Node *temp = head;
    Node *lastVisited = head;

    while (temp != NULL && !((type == 2 && data == temp->std.getRollNo()) || (type == 1 && data == temp->std.getID())))
    {
        lastVisited = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        spaces(35);
        cout << endl
             << "There is no Student with the provided data" << endl;
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
        temp->std.printAll();
    }

    //pause
    cout << "Press any key and enter to go back...";
    cin >> data;
}

void CStudentList::printAll()
{
    Node *temp = head;
    int i = 1;
    while (temp != NULL)
    {
        cout << "Student " << i << endl;
        temp->std.printAll();
        temp = temp->next;
        i++;
    }

    //waiting (so that function does not finish very fast)
    char a;
    cout << endl
         << endl
         << endl
         << "Press any key to go back";
    cin >> a;
}

CStudentList::~CStudentList()
{
    head = NULL;
}

bool CStudentList::existsStudent(int id)
{
    Node *temp = head;
    Node *lastVisited = head;

    while (temp != NULL && !(id == temp->std.getID()))
    {
        lastVisited = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return false;
    return true;
}

CStudentList::Node* CStudentList::getHead()
{
    Node* temp = head;
    return temp;
}