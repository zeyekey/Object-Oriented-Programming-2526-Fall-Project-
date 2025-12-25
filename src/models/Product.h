#pragma once
#include <string>

class Product {
public:
    Product(int id, std::string title, double price);
    virtual ~Product();
    int id() const;
    const std::string& title() const;
    double price() const;
    virtual std::string info() const;
private:
    int m_id;
    std::string m_title;
    double m_price;
};
