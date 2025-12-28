// Author: Muhammed Mehmet Gökçe
// Date: 21.12.2025

// Dosya Amacý: Tüm ürün tipleri için ortak Product taban sýnýfýný tanýmlar.
// Not: Book/Magazine/MusicCD gibi sýnýflar buradan türeyerek display() metodunu özelleþtirir.

#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>

using namespace std;

class Product 
{
protected:
    int id;
    string name;
    double price;

public:
    Product(int id, string name, double price);
    virtual ~Product();
    int getID() const;
    void setID(int id);
    string getName() const;
    void setName(string name);
    double getPrice() const;
    void setPrice(double price);
    virtual void printProperties() const = 0;
};
#endif
