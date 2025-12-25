#pragma once
#include "Inventory.h"
#include "../models/ShoppingCart.h"
#include <memory>

class BookstoreApp {
public:
    BookstoreApp();
    void run();
private:
    Inventory m_inventory;
    ShoppingCart m_cart;
    void seed();
};
