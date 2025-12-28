// Author: Yusuf Göç
// Date: 23.12.2025
// 
// Dosya Amacý: MusicCD ürün tipinin arayüzünü tanýmlar; Product sýnýfýndan türetilmiþtir.
// Not: MusicCD’ye özel "artist" alaný bulunur; çýktý formatý printProperties() ile özelleþtirilir.

#ifndef MUSICCD_H

#define MUSICCD_H



#include <string>

#include <iostream>

#include "Product.h"



using namespace std;



class MusicCD : public Product

{

private:

    string singer; //singer

    string type;   //type



public:

    MusicCD(int id, string name, double price, string singer, string type);



    string getSinger() const;

    void setSinger(string singer);



    string getType() const;

    void setType(string type);



    void printProperties() const override;

};



#endif