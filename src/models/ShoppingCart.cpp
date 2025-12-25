#include "ShoppingCart.h"
#include <iostream>
#include "../utils/Formatter.h"

void ShoppingCart::addItem(const ProductToPurchase& item) {
    m_items.push_back(item);
}

double ShoppingCart::total() const {
    double sum = 0.0;
    for (auto &it : m_items) sum += it.lineTotal();
    return sum;
}

void ShoppingCart::listItems() const {
    for (const auto &it : m_items) {
        if (it.product()) std::cout << it.product()->info() << " x" << it.quantity()
                                    << " -> $" << util::formatCurrency(it.lineTotal()) << "\n";
    }
}
