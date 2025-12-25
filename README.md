# Bookstore OOP Project

Minimal C++17 Object-Oriented Bookstore example. Build with CMake.

Quick build:
```bash
mkdir -p build && cd build
cmake ..
cmake --build .
./bookstore
```
# Online Bookstore (Console App) — C++

Online Bookstore is a **console-based** C++ application that simulates a simple shopping experience:
customers can log in, browse products, add/remove items to cart, use bonus, and place/cancel orders.

This repository is built to satisfy the OOP1 term project requirements:
- Console-based application
- Only standard C++ libraries
- Each class in separate `.h` and `.cpp`
- Code comments near related code segments
- Team task distribution must be documented in the report
- At least **5 customers** and **3 products of each type** (Book / Magazine / MusicCD) :contentReference[oaicite:2]{index=2} :contentReference[oaicite:3]{index=3}

---

## Project Requirements (From Spec)

### Product Types
- **Product (abstract)**: `id`, `name`, `price`, `printProperties()`
- **Book**: `author`, `publisher`, `page`
- **Magazine**: `issue`, `type`
- **MusicCD**: `singer`, `type` :contentReference[oaicite:4]{index=4} :contentReference[oaicite:5]{index=5}

### Customer & Bonus
- **Customer**: `customerID`, `name`, `username`, `password`, `bonus`
- Bonus rule: customer earns **1%** of each shopping amount; can use next shopping or save. :contentReference[oaicite:6]{index=6}

### Shopping Cart
- Holds `productsToPurchase` (use `std::vector` or `std::list`)
- Holds `paymentMethod` + `isBonusUsed` flag
- Methods: `addProduct`, `removeProduct`, `printProducts`, `placeOrder`, `cancelOrder`, `showInvoice` :contentReference[oaicite:7]{index=7}

### Payments
- **Payment (abstract)**: `amount`, `performPayment()`
- **CreditCard**: `number`, `type (Master/Visa)`, `expDate`
- **Cash**
- **Check**: `name`, `bankID` :contentReference[oaicite:8]{index=8}

---

## Proposed Console Menus (Aligned with Spec)

Example flow (you may improve UI; you can even implement menus as objects for bonus points): :contentReference[oaicite:9]{index=9}

**Main Menu**
1. Customer
2. Item
3. Shopping
4. Quit

**Customer Menu**
1. Add a new customer to the system
2. Show the customers in the system
3. Back

**Shopping Menu**
1. Login
2. Add Product
3. Remove Product
4. List All Products
5. List Shopping Cart
6. Show Bonus
7. Use Bonus
8. Place Order
9. Cancel Order
10. Show Invoice
11. Quit :contentReference[oaicite:10]{index=10}

---

## Repository Structure

> Rule: every class has its own header/source files (`.h` / `.cpp`) and each file includes **author name + date** in the file header comment. :contentReference[oaicite:11]{index=11}

