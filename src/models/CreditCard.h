#pragma once
#include "Payment.h"
#include <string>

class CreditCard : public Payment {
public:
    CreditCard(std::string holder, std::string number);
    bool pay(double amount) override;
private:
    std::string m_holder;
    std::string m_number;
};
