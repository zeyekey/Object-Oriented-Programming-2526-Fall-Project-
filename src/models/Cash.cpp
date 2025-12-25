#include "Cash.h"
#include <iostream>
#include "../utils/Formatter.h"

Cash::Cash() = default;

bool Cash::pay(double amount) {
    std::cout << "Received cash payment of $" << util::formatCurrency(amount) << "\n";
    return true;
}
