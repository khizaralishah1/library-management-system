#ifndef CBOOK_H
#define CBOOK_H

#include <string>
using namespace std;

class CBook
{
private:
    int id, price, pages, isbn;
    string issuedBy;
    string bookName;
    string author;
    string issuedOn, returnDate;
    
public:
    CBook(string="", string="", string="", string="", string="", int=0, int=0, int=0, int=0);

    void setName();
    string getName();
    void setAuthor();
    void setPrice();
    void setPages();
    void setID();
    void setIssueDate();
    void setISBN();
    int getISBN();
    int getID();
    void setReturnDate();
    void setIssuedBy();
    void printAll();

    ~CBook();
};


#endif