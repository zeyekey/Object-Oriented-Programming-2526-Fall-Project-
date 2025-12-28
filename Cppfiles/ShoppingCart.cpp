// Author: Hayri Baran Vural
// Date: 23.12.2025
// Author: Zeynep Kurt(exception handling)
// Date: 27.12.2025

// Dosya Amacý: ShoppingCart fonksiyonlarýný uygular.
// Not: Invoice kýsmýnda müþteri adý/e-posta/adres bilgileri de gösterilir.

#include "ShoppingCart.h"
#include "CreditCard.h"
#include "Check.h"
#include "Cash.h"

ShoppingCart::ShoppingCart() : customer(nullptr), paymentMethod(nullptr), isBonusUsed(false) {}

ShoppingCart::~ShoppingCart() 
{
    if (paymentMethod) 
    {
        delete paymentMethod;
        paymentMethod = nullptr;
    }
    for (auto item : productsToPurchase) 
    {
        delete item;
    }
    productsToPurchase.clear();
}

void ShoppingCart::setCustomer(Customer* c) 
{ customer = c; }
void ShoppingCart::setBonusUsed(bool use) 
{ isBonusUsed = use; }

void ShoppingCart::setPaymentMethod(Payment* p) 
{
    if (paymentMethod && paymentMethod != p) 
    {
        delete paymentMethod;
    }
    paymentMethod = p;
}

void ShoppingCart::addProduct(Product* p, int qty) 
{
    productsToPurchase.push_back(new ProductToPurchase(p, qty));
    cout << ">> Added to cart: " << p->getName() << " x" << qty << endl;
}

void ShoppingCart::removeProduct(Product* p) 
{
    for (auto it = productsToPurchase.begin(); it != productsToPurchase.end(); ) 
    {
        if ((*it)->getProduct()->getID() == p->getID()) 
        {
            delete* it;
            it = productsToPurchase.erase(it);
            cout << ">> Deleted from cart.\n";
            return;
        }
        else 
        {
            ++it;
        }
    }
    throw ItemNotFoundException("Product is not in cart.");
}

void ShoppingCart::printProducts() 
{
    if (productsToPurchase.empty()) 
    {
        cout << "Cart is empty.\n";
        return;
    }
    cout << "\n--- YOUR CART ---\n";
    for (auto item : productsToPurchase) 
    {
        cout << item->getProduct()->getName()
            << " (" << item->getQuantity() << " Quantity) - "
            << item->getProduct()->getPrice() * item->getQuantity()
            << " TL" << endl;
    }
    cout << "-----------------\n";
}

#include <limits>   

void ShoppingCart::placeOrder()
{
    if (productsToPurchase.empty()) throw CartEmptyException();

    double totalAmount = 0.0;
    for (auto item : productsToPurchase)
    {
        totalAmount += item->getProduct()->getPrice() * item->getQuantity();
    }

    cout << "\nTotal Cart Amount: " << totalAmount << " TL" << endl;

    double discount = 0.0;
    if (isBonusUsed && customer)
    {
        double currentBonus = customer->getBonus();
        if (currentBonus > 0)
        {
                if (currentBonus >= totalAmount)
            {
                discount = totalAmount; }
            else
            {
                discount = currentBonus;
            }

            customer->useBonus();
            cout << "Bonus Used: -" << discount << " TL" << endl;
        }
    }

    double finalAmount = totalAmount - discount;
    if (finalAmount < 0) finalAmount = 0;

    cout << "Payment Required: " << finalAmount << " TL" << endl;

    int m = 0;
    while (true)
    {
        cout << "Choose payment method: 1-Cash, 2-CreditCard, 3-Check: ";
        if (!(cin >> m))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (m >= 1 && m <= 3) break;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Payment* newPayment = nullptr;

    if (m == 1)
    {
        newPayment = new Cash();
    }
    else if (m == 2) 
    {
        long cardNo;
        string type, exp;
        cout << "Card Number: "; cin >> cardNo; cin.ignore();
        cout << "Card Type (Visa/Master): "; getline(cin, type);
        cout << "Exp Date (MM/YY): "; getline(cin, exp);
        newPayment = new CreditCard(cardNo, type, exp);
    }
    else 
    {
        string bank, checkNo;
        cout << "Bank ID: "; getline(cin, bank); // PDF: bankID
        cout << "Check Owner Name: "; getline(cin, checkNo); // PDF: name
        newPayment = new Check(checkNo, bank);
    }

    newPayment->setAmount(finalAmount);
    newPayment->performPayment();
    setPaymentMethod(newPayment); 

    if (customer)
    {
        customer->addBonus(finalAmount);
        cout << ">> You earned " << (finalAmount * 0.01) << " TL bonus points!\n";
    }

    showInvoice();

    for (auto item : productsToPurchase) delete item;
    productsToPurchase.clear();
    isBonusUsed = false; // Reset

    cout << "Order process completed successfully.\n";
}


void ShoppingCart::cancelOrder() 
{
    if (productsToPurchase.empty()) throw CartEmptyException();

    for (auto item : productsToPurchase) delete item;
    productsToPurchase.clear();

    isBonusUsed = false;

    if (paymentMethod) 
    {
        delete paymentMethod;
        paymentMethod = nullptr;
    }

    cout << "Order cancelled.\n";
}

void ShoppingCart::showInvoice() 
{
    cout << "\nBill Preview\n";
    cout << "Guest: " << (customer ? customer->getName() : "Guest") << endl;
    printProducts();
    cout << "*****************************\n";
}
