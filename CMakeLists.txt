cmake_minimum_required(VERSION 3.10)
project(BookstoreApp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CORE_SRC
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

add_library(bookstore_core STATIC ${CORE_SRC})
target_include_directories(bookstore_core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(bookstore src/main.cpp)
target_link_libraries(bookstore PRIVATE bookstore_core)

enable_testing()
add_subdirectory(tests)
