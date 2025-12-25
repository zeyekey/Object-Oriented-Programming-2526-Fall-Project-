#include "BookstoreApp.h"
#include "../models/Book.h"
#include "../models/Magazine.h"
#include "../models/MusicCD.h"
#include "../models/ProductToPurchase.h"
#include "../models/CreditCard.h"
#include <iostream>
#include "../utils/Input.h"
#include "../models/Cash.h"
#include "../models/Check.h"
#include "../utils/Formatter.h"
#include "../utils/Formatter.h"

BookstoreApp::BookstoreApp() { seed(); }

void BookstoreApp::seed() {
    m_inventory.addProduct(std::make_shared<Book>(1, "The C++ Way", 29.99, "A. Author"));
    m_inventory.addProduct(std::make_shared<Magazine>(2, "Tech Monthly", 5.99, 42));
    m_inventory.addProduct(std::make_shared<MusicCD>(3, "Greatest Hits", 12.50, "The Band"));
}

void BookstoreApp::run() {
    while (true) {
        std::cout << "\n--- Bookstore Menu ---\n";
        std::cout << "1) List products\n2) Add product to cart\n3) Show cart\n4) Remove from cart\n5) Checkout\n6) Clear cart\n7) Exit\n";
        int cmd = utils::getInt("Seçiminiz: ");
        if (cmd == 1) {
            std::cout << "Available products:\n";
            m_inventory.listAll();
        } else if (cmd == 2) {
            int id = utils::getInt("Ürün ID girin: ");
            int qty = utils::getInt("Miktar: ");
            auto p = m_inventory.findById(id);
            if (!p) std::cout << "Ürün bulunamadı.\n";
            else {
                m_cart.addItem(ProductToPurchase(p, qty));
                std::cout << "Sepete eklendi.\n";
            }
        } else if (cmd == 3) {
            std::cout << "\nCart contents:\n";
            m_cart.listItems();
            std::cout << "Total: $" << util::formatCurrency(m_cart.total()) << "\n";
        } else if (cmd == 4) {
            int id = utils::getInt("Sepetten çıkarılacak ürün ID: ");
            if (m_cart.removeByProductId(id)) std::cout << "Ürün çıkarıldı.\n";
            else std::cout << "Ürün sepette bulunamadı.\n";
        } else if (cmd == 5) {
            double total = m_cart.total();
            if (total <= 0.0) { std::cout << "Sepet boş.\n"; continue; }
            std::cout << "Toplam: $" << util::formatCurrency(total) << "\n";
            std::cout << "Ödeme yöntemi seçin: 1) CreditCard 2) Cash 3) Check\n";
            int payChoice = utils::getInt("Seçiminiz: ");
            std::unique_ptr<Payment> pay;
            if (payChoice == 1) {
                std::string name = utils::getString("Kart sahibinin adı: ");
                std::string number = utils::getString("Kart numarası: ");
                pay = std::make_unique<CreditCard>(name, number);
            } else if (payChoice == 2) {
                pay = std::make_unique<Cash>();
            } else if (payChoice == 3) {
                std::string bank = utils::getString("Banka adı: ");
                std::string num = utils::getString("Çek numarası: ");
                pay = std::make_unique<Check>(bank, num);
            } else {
                std::cout << "Geçersiz ödeme seçeneği.\n"; continue;
            }
            if (pay->pay(total)) {
                std::cout << "Payment successful\n";
                m_cart.clear();
            } else std::cout << "Payment failed\n";
        } else if (cmd == 6) {
            m_cart.clear();
            std::cout << "Sepet temizlendi.\n";
        } else if (cmd == 7) {
            std::cout << "Çıkılıyor...\n";
            break;
        } else {
            std::cout << "Geçersiz seçim.\n";
        }
    }
}
