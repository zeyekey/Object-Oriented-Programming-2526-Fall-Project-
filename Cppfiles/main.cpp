// Author: Zeynep Kurt
// Date: 27.12.2025

// Dosya Amacý: Programýn giriþ noktasýdýr; menü tabanlý akýþla müþteri/ürün/sepet/ödeme iþlemlerini yönetir.
// Not: Sýnýflarý bir araya getirerek uygulamanýn senaryosunu çalýþtýrýr (kayýt, giriþ, sepet, ödeme).

#include <iostream>
#include <vector>
#include <string>

#include "Customer.h" // Customer sýnýfý
#include "Product.h" // Product taban sýnýfý
#include "Book.h" // Book ürün tipi
#include "Magazine.h" // Magazine ürün tipi
#include "MusicCD.h" // MusicCD ürün tipi
#include "ShoppingCart.h" // Alýþveriþ Sepeti

using namespace std;

vector<Customer*> dbCustomers;
vector<Product*> dbProducts;

template <typename T, typename Pred>
T* findFirst(const vector<T*>& items, Pred predicate) {
    for (T* item : items) {
        if (predicate(item)) return item;
    }
    return nullptr;
}

void seedData() {
    cout << "Loading system data...\n";

    dbCustomers.push_back(new Customer(1, "Ali Yilmaz", "ali123", "pass1", "ali@mail.com", "Eskisehir"));
    dbCustomers.push_back(new Customer(2, "Ayse Demir", "ayse", "1234", "ayse@mail.com", "Eskisehir"));
    dbCustomers.push_back(new Customer(3, "Mehmet Kaya", "mehmet", "0000", "mehmet@mail.com", "Eskisehir"));
    dbCustomers.push_back(new Customer(4, "Elif Sahin", "elif", "1111", "elif@mail.com", "Eskisehir"));
    dbCustomers.push_back(new Customer(5, "Can Aydin", "can", "2222", "can@mail.com", "Eskisehir"));

    // kitap
    dbProducts.push_back(new Book(101, "Sefiller", 350.0, "Victor Hugo", "Is Bankasi", 1500));
    dbProducts.push_back(new Book(102, "Kurk Mantolu Madonna", 220.0, "Sabahattin Ali", "Yapi Kredi", 160));
    dbProducts.push_back(new Book(103, "Tutunamayanlar", 450.0, "Oguz Atay", "Iletisim", 724));

    // Magazin
    dbProducts.push_back(new Magazine(201, "Bilim Teknik", 50.0, 202401, "Science"));
    dbProducts.push_back(new Magazine(202, "National Geographic", 90.0, 202402, "Geography"));
    dbProducts.push_back(new Magazine(203, "Level", 75.0, 202403, "Gaming"));

    // MuzikCD
    dbProducts.push_back(new MusicCD(301, "Random Access Memories", 180.0, "Daft Punk", "Electronic"));
    dbProducts.push_back(new MusicCD(302, "Thriller", 200.0, "Michael Jackson", "Pop"));
    dbProducts.push_back(new MusicCD(303, "Back in Black", 170.0, "AC/DC", "Rock"));
    cout << "System data loaded.\n";
}

void showMainMenu() {
    cout << "\n===== ONLINE BOOKSTORE =====\n";
    cout << "1. Customer Menu\n";
    cout << "2. Product Menu\n";
    cout << "3. Shopping Menu\n";
    cout << "4. Exit\n";
    cout << "Choose: ";
}

void showCustomerMenu()
{
    cout << "\n--- Customer Menu ---\n";
    cout << "1. Add New Customer\n";
    cout << "2. List Customers\n";
    cout << "3. Back\n";
    cout << "Choose: ";
}

void showShoppingMenu(const string& kim)
{
    cout << "\n========================================\n";
    cout << "    Shopping Menu (" << kim << ")\n";
    cout << "========================================\n";
    cout << "1. Login \n";
    cout << "2. Logout \n";
    cout << "----------------------------------------\n";
    cout << "3. Add Product\n";
    cout << "4. Remove Product\n";
    cout << "5. List Shopping Cart\n";
    cout << "6. Show Bonus\n";
    cout << "7. Use Bonus\n";
    cout << "8. Place Order\n";
    cout << "9. Cancel Order\n";
    cout << "10. Show Invoice\n";
    cout << "11. Back to Main Menu\n";
    cout << "Choose: ";
}

int main()
{
    seedData();
    int choice;

    Customer* currentSession = nullptr;

    while (true)
    {
        showMainMenu();
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1)
        {
            int custChoice;
            showCustomerMenu();
            cin >> custChoice;

            if (custChoice == 1)
            {
                string n, u, p, e, a;
                cout << "Name: "; cin.ignore(); getline(cin, n);
                cout << "Username: "; cin >> u;
                cout << "Password: "; cin >> p;
                cout << "E-mail: "; cin >> e;
                cout << "Address: "; cin >> ws; getline(cin, a);

                long newID = (long)(dbCustomers.size() + 1ULL);
                dbCustomers.push_back(new Customer(newID, n, u, p, e, a));
                cout << "Customer added successfully!\n";
            }
            else if (custChoice == 2)

            {
                cout << "\n--- Customer List ---\n";
                for (auto c : dbCustomers)
                {
                    cout << "ID: " << c->getCustomerID() << " - " << c->getName()
                        << " (" << c->getEmail() << ") - " << c->getAddress() << "\n";
                }
            }
        }
        else if (choice == 2)
        {
            cout << "\n--- Product List ---\n";
            for (auto p : dbProducts) { p->printProperties(); cout << "---\n"; }
        }
        else if (choice == 3)
        {
            int shopChoice;
            bool back = false;

            while (!back)
            {
                showShoppingMenu(currentSession ? currentSession->getName() : "Guest");
                cin >> shopChoice;

                try
                {
                    switch (shopChoice)
                    {
                    case 1:
                    {
                        if (currentSession)
                        {
                            cout << "Already logged in.\n";
                            break;
                        }

                        string u, p;
                        cout << "Username: "; cin >> u;
                        cout << "Password: "; cin >> p;

                        Customer* match = findFirst<Customer>(dbCustomers, [&](Customer* c)
                            {
                                return c->checkAccount(u, p);
                            });

                        if (!match) throw AuthenticationException("Wrong username or password.");

                        currentSession = match;
                        currentSession->getCart()->setCustomer(currentSession);
                        cout << "Login success!\n";
                        break;
                    }
                    case 2:
                    {
                        if (currentSession)
                        {
                            cout << "Logout: " << currentSession->getName() << endl;
                            currentSession = nullptr;
                        }
                        else cout << "Not logged in.\n";
                        break;
                    }
                    case 3:
                    {
                        int id, qty;
                        cout << "Product ID: "; cin >> id;
                        cout << "Quantity: "; cin >> qty;

                        Product* p = findFirst<Product>(dbProducts, [&](Product* pr) { return pr->getID() == id; });
                        if (!p) throw runtime_error("Product not found.");

                        if (!currentSession) throw AuthenticationException("Login required.");

                        currentSession->getCart()->addProduct(p, qty);
                        break;
                    }
                    case 4:
                    {
                        int id;
                        cout << "Product ID: "; cin >> id;

                        Product* p = findFirst<Product>(dbProducts, [&](Product* pr) { return pr->getID() == id; });
                        if (!p) throw runtime_error("Product not found.");

                        if (!currentSession) throw AuthenticationException("Login required.");

                        currentSession->getCart()->removeProduct(p);
                        break;
                    }
                    case 5:
                    {
                        if (!currentSession) throw AuthenticationException("Login required.");
                        currentSession->getCart()->printProducts();
                        break;
                    }
                    case 6:
                    {
                        if (!currentSession) throw AuthenticationException("Login required.");
                        cout << "Bonus: " << currentSession->getBonus() << endl;
                        break;
                    }
                    case 7:
                    {
                        if (!currentSession) throw AuthenticationException("Login required.");
                        currentSession->getCart()->setBonusUsed(true);
                        cout << "Bonus will be used.\n";
                        break;
                    }
                    case 8:
                    {
                        if (!currentSession) throw AuthenticationException("Login required.");
                        currentSession->getCart()->placeOrder();
                        break;
                    }
                    case 9:
                    {
                        if (!currentSession) throw AuthenticationException("Login required.");
                        currentSession->getCart()->cancelOrder();
                        break;
                    }
                    case 10:
                    {
                        if (!currentSession) throw AuthenticationException("Login required.");
                        currentSession->getCart()->showInvoice();
                        break;
                    }
                    case 11:
                    {
                        back = true;
                        break;
                    }
                    default:
                        cout << "Invalid choice.\n";
                    }
                }
                catch (exception& ex)
                {
                    cout << "[ERROR] " << ex.what() << endl;
                }
            }
        }
        else if (choice == 4)
        {
            cout << "Exiting...\n";
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }

    for (auto c : dbCustomers) delete c;
    for (auto p : dbProducts) delete p;

    return 0;
}
