#pragma once
#include <memory>
#include "Product.h"

class ProductToPurchase {
public:
    ProductToPurchase(std::shared_ptr<Product> product, int qty);
    std::shared_ptr<Product> product() const;
    int quantity() const;
    double lineTotal() const;
private:
    std::shared_ptr<Product> m_product;
    int m_qty;
};
