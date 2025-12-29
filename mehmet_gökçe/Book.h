// Author: Muhammed Mehmet Gökçe
// Date: 21.12.2025
// Dosya Amacý: Book ürün tipinin arayüzünü tanýmlar; Product sýnýfýndan türetilmiþtir.
// Not: Bu dosyada sadece sýnýf bildirimi vardýr; fonksiyonlarýn içeriði Book.cpp dosyasýndadýr.
#ifndef BOOK_H
#define BOOK_H
#include "Product.h"
class Book : public Product 
{
private:
     string author, publisher;
     int page;

public:
    Book(int id, string name, double price, string author, string publisher, int page);
    string getAuthor() const;
    void setAuthor(string author);
    string getPublisher() const;
    void setPublisher(string publisher);
    int getPage() const;
    void setPage(int page);
    void printProperties() const override;
};
#endif
