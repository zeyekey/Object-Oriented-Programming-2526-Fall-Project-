#include "Customer.h"

Customer::Customer(int id, std::string name)
    : m_id(id), m_name(std::move(name)) {}

int Customer::id() const { return m_id; }
const std::string& Customer::name() const { return m_name; }
