#include "ProductToPurchase.h"

ProductToPurchase::ProductToPurchase(std::shared_ptr<Product> product, int qty)
    : m_product(std::move(product)), m_qty(qty) {}

std::shared_ptr<Product> ProductToPurchase::product() const { return m_product; }
int ProductToPurchase::quantity() const { return m_qty; }
double ProductToPurchase::lineTotal() const { return m_product ? m_product->price() * m_qty : 0.0; }
