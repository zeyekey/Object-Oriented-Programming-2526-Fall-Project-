#pragma once
#include "Payment.h"

class Cash : public Payment {
public:
    Cash();
    bool pay(double amount) override;
};
