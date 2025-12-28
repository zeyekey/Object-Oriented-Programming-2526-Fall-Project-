// Author: Muhammed Mehmet Gökçe
// Date: 21.12.2025
// Dosya Amacý: Book sýnýfýnýn metotlarýný (kurucu, getter/setter, display) uygular.
// Not: Book’e özel alan olan "author" burada yönetilir ve ekrana yazdýrma burada özelleþtirilir.

#include "Book.h"
Book::Book(int id, string name, double price, string author, string publisher, int page)  :  Product(id, name, price), author(author), publisher(publisher), page(page) {}

string Book::getAuthor() const 
{ 
    return author; 
}

void Book::setAuthor(string author) 
{
    this->author = author; 
}

string Book::getPublisher() const 
{
    return publisher; 
}

void Book::setPublisher(string publisher) 
{
    this->publisher = publisher; 
}

int Book::getPage() const
{ return page; 
}

void Book::setPage(int page) 
{
    this->page = page; 
}

void Book::printProperties() const 
{
    cout << "Book - ID: " << id << ", Name: " << name << ", Price: " << price << endl;
    cout << "Author: " << author << ", Publisher: " << publisher << ", Pages: " << page << endl;
}
