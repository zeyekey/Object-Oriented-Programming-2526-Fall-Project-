#include "BookstoreApp.h"
#include "../models/Book.h"
#include "../models/Magazine.h"
#include "../models/MusicCD.h"
#include "../models/ProductToPurchase.h"
#include "../models/CreditCard.h"
#include <iostream>
#include "../utils/Formatter.h"

BookstoreApp::BookstoreApp() { seed(); }

void BookstoreApp::seed() {
    m_inventory.addProduct(std::make_shared<Book>(1, "The C++ Way", 29.99, "A. Author"));
    m_inventory.addProduct(std::make_shared<Magazine>(2, "Tech Monthly", 5.99, 42));
    m_inventory.addProduct(std::make_shared<MusicCD>(3, "Greatest Hits", 12.50, "The Band"));
}

void BookstoreApp::run() {
    std::cout << "Welcome to the Bookstore demo\nAvailable products:\n";
    m_inventory.listAll();

    auto p = m_inventory.findById(1);
    if (p) m_cart.addItem(ProductToPurchase(p, 2));

    std::cout << "\nCart contents:\n";
    m_cart.listItems();
    double total = m_cart.total();
    std::cout << "Total: $" << util::formatCurrency(total) << "\n";

    CreditCard cc("Test User", "4111111111111111");
    if (cc.pay(total)) std::cout << "Payment successful\n";
}
