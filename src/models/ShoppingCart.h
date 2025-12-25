#pragma once
#include <vector>
#include <memory>
#include "ProductToPurchase.h"

class ShoppingCart {
public:
    void addItem(const ProductToPurchase& item);
    double total() const;
    void listItems() const;
    bool removeByProductId(int productId);
    void clear();
private:
    std::vector<ProductToPurchase> m_items;
};
