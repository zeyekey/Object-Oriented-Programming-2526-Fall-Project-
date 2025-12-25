#pragma once
#include "Payment.h"
#include <string>

class Check : public Payment {
public:
    Check(std::string bank, std::string number);
    bool pay(double amount) override;
private:
    std::string m_bank;
    std::string m_number;
};
