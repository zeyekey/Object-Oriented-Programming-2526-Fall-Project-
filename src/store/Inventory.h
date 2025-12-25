#pragma once
#include <vector>
#include <memory>
#include "../models/Product.h"

class Inventory {
public:
    void addProduct(std::shared_ptr<Product> p);
    std::shared_ptr<Product> findById(int id) const;
    void listAll() const;
private:
    std::vector<std::shared_ptr<Product>> m_products;
};
