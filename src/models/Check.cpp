#include "Check.h"
#include <iostream>
#include "../utils/Formatter.h"

Check::Check(std::string bank, std::string number)
    : m_bank(std::move(bank)), m_number(std::move(number)) {}

bool Check::pay(double amount) {
    std::cout << "Processing check payment of $" << util::formatCurrency(amount) << " from " << m_bank << "\n";
    return true;
}
