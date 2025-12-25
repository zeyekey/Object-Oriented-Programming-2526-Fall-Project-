#pragma once
#include "Product.h"
#include <string>

class Magazine : public Product {
public:
    Magazine(int id, std::string title, double price, int issue);
    int issue() const;
    std::string info() const override;
private:
    int m_issue;
};
