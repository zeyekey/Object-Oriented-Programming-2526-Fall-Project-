// Author: Muhammed Mehmet Gökçe
// Date: 21.12.2025

// Dosya Amacý: Product taban sýnýfýnýn metotlarýný (kurucu, getter/setter, display) uygular.
// Not: Alt sýnýflar display() metodunu override ederek farklý formatta çýktý verebilir.

#include "Product.h"

Product::Product(int id, string name, double price) : id(id), name(name), price(price) {}
Product::~Product() {}

int Product::getID() const
{
	return id; 
}

void Product::setID(int id) 
{
	this->id = id; 
}

string Product::getName() const 
{
	return name; 
}

void Product::setName(string name) 
{
	this->name = name; 
}

double Product::getPrice() const 
{
	return price; 
}

void Product::setPrice(double price) 
{
	this->price = price; 
}