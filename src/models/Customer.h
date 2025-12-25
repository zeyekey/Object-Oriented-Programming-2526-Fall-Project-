#pragma once
#include <string>

class Customer {
public:
    Customer(int id, std::string name);
    int id() const;
    const std::string& name() const;
private:
    int m_id;
    std::string m_name;
};
