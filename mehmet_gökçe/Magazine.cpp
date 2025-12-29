// Author: Muhammed Mehmet Gökçe
// Date: 21.12.2025

// Dosya Amacý: Magazine sýnýfýnýn metotlarýný (kurucu, getter/setter, display) uygular.
// Not: publisher alaný ile ürün bilgisi ekrana yazdýrma özelleþtirilir.

#include "Magazine.h"
Magazine::Magazine(int id, string name, double price, int issue, string type)   :   Product(id, name, price), issue(issue), type(type) {}

int Magazine::getIssue() const 
{
    return issue; 
}
void Magazine::setIssue(int issue) 
{
    this->issue = issue; 
}

string Magazine::getType() const 
{
    return type; 
}
void Magazine::setType(string type) 
{
    this->type = type; 
}

void Magazine::printProperties() const 
{
    cout << "Magazine - ID: " << id << ", Name: " << name << ", Price: " << price << endl;
    cout << "Issue: " << issue << ", Type: " << type << endl;
}
