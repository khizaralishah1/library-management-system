#include "cbook.h"
#include <iostream>
#include <iomanip>
using namespace std;


CBook::CBook(string name, string writer, string issueDate, string returnOn, string issueBy, int isbNum, int idNum, int pric, int pageCount)
{
    bookName = name;
    author = writer;
    isbn = isbNum;
    issuedOn = issueDate;
    returnDate = returnOn;
    id = idNum;
    pages = pageCount;
    issuedBy = issueBy;
}

int CBook::getID()
{
    return id;
}

int CBook::getISBN()
{
    return isbn;
}

string CBook::getName()
{
    return bookName;
}

void CBook::printAll()
{
    cout << "Book Name: " << bookName << endl
        //  << "Author: " << author << endl
        //  << "ISBN: " << isbn << endl
        //  << "Issue Date: " << issuedOn << endl
        //  << "Return Date: " << returnDate << endl
          << "ID: " << id << endl;
        //  << "Pages: " << pages << endl
        //  << "Issued by: " << issuedBy << endl;
}

void CBook::setName()
{
    cout << setw(45) << "Book Name: ";
    cin >> bookName;
}

void CBook::setAuthor()
{
    cout << setw(45) << "Author: ";
    cin >> author;
}

void CBook::setPrice()
{
    cout << setw(45) << "Price: ";
    cin >> price;
}

void CBook::setPages()
{
    cout << setw(45) << "Pages: ";
    cin >> pages;
}

void CBook::setID()
{
    cout << setw(45) << "(Unique) ID: ";
    cin >> id;
}

void CBook::setIssueDate()
{
    cout << setw(45) << "Issue Date: ";
    cin >> issuedOn;
}

void CBook::setIssuedBy()
{
    cout << setw(45) << "Issued By: ";
    cin >> issuedBy;
}

void CBook::setISBN()
{
    cout << setw(45) << "ISBN: ";
    cin >> isbn;
}

void CBook::setReturnDate()
{
    cout << setw(45) << "Return Date: ";
    cin >> returnDate;
}

CBook::~CBook()
{
    
}