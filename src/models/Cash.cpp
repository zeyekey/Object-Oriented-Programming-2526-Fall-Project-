#include "Cash.h"
#include <iostream>

Cash::Cash() = default;

bool Cash::pay(double amount) {
    std::cout << "Received cash payment of $" << amount << "\n";
    return true;
}
