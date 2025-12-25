#pragma once
#include "Product.h"
#include <string>

class Book : public Product {
public:
    Book(int id, std::string title, double price, std::string author);
    std::string author() const;
    std::string info() const override;
private:
    std::string m_author;
};
