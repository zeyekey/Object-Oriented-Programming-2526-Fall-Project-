#include "CreditCard.h"
#include <iostream>
#include "../utils/Formatter.h"

CreditCard::CreditCard(std::string holder, std::string number)
    : m_holder(std::move(holder)), m_number(std::move(number)) {}

bool CreditCard::pay(double amount) {
    std::cout << "Charging $" << util::formatCurrency(amount) << " to credit card (" << m_holder << ")\n";
    return true;
}
