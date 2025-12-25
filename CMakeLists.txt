cmake_minimum_required(VERSION 3.10)
project(BookstoreApp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(SRC
    src/main.cpp
    src/models/Product.cpp
    src/models/Book.cpp
    src/models/Magazine.cpp
    src/models/MusicCD.cpp
    src/models/Customer.cpp
    src/models/ProductToPurchase.cpp
    src/models/ShoppingCart.cpp
    src/models/Payment.cpp
    src/models/CreditCard.cpp
    src/models/Cash.cpp
    src/models/Check.cpp
    src/store/Inventory.cpp
    src/store/BookstoreApp.cpp
    src/utils/Input.cpp
    src/utils/Formatter.cpp
)
add_executable(bookstore ${SRC})
