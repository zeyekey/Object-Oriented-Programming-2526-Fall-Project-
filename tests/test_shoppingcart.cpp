#include "gtest/gtest.h"
#include "models/Product.h"
#include "models/Book.h"
#include "models/ProductToPurchase.h"
#include "models/ShoppingCart.h"

TEST(ShoppingCartTest, AddAndTotal) {
    auto b = std::make_shared<Book>(1, "T", 10.0, "A");
    ProductToPurchase p(b, 2);
    ShoppingCart cart;
    cart.addItem(p);
    EXPECT_DOUBLE_EQ(cart.total(), 20.0);
}

TEST(ShoppingCartTest, RemoveAndClear) {
    auto b = std::make_shared<Book>(1, "T", 10.0, "A");
    auto b2 = std::make_shared<Book>(2, "U", 5.0, "B");
    ShoppingCart cart;
    cart.addItem(ProductToPurchase(b, 1));
    cart.addItem(ProductToPurchase(b2, 2));
    EXPECT_TRUE(cart.removeByProductId(1));
    EXPECT_DOUBLE_EQ(cart.total(), 10.0);
    cart.clear();
    EXPECT_DOUBLE_EQ(cart.total(), 0.0);
}
