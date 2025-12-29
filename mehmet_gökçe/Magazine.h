// Author: Muhammed Mehmet Gökçe
// Date: 21.12.2025

// Dosya Amacý: Magazineürün tipinin arayüzünü tanýmlar; Product sýnýfýndan türetilmiþtir.
// Not: Dergiye özel "publisher" alaný bulunur; detaylar Magazine.cpp dosyasýndadýr.

#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "Product.h"
class Magazine : public Product 
{
private:
    int issue;
    string type;

public:
    Magazine(int id, string name, double price, int issue, string type);
    int getIssue() const;
    void setIssue(int issue);
    string getType() const;
    void setType(string type);
    void printProperties() const override;
};
#endif
