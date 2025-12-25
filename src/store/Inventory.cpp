#include "Inventory.h"
#include <iostream>

void Inventory::addProduct(std::shared_ptr<Product> p) {
    m_products.push_back(std::move(p));
}

std::shared_ptr<Product> Inventory::findById(int id) const {
    for (auto &p : m_products) if (p && p->id() == id) return p;
    return nullptr;
}

void Inventory::listAll() const {
    for (auto &p : m_products) if (p) std::cout << p->info() << "\n";
}
