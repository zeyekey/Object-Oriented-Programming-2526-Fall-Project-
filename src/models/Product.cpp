#include "Product.h"
#include <sstream>
#include "../utils/Formatter.h"

Product::Product(int id, std::string title, double price)
    : m_id(id), m_title(std::move(title)), m_price(price) {}

Product::~Product() = default;

int Product::id() const { return m_id; }
const std::string& Product::title() const { return m_title; }
double Product::price() const { return m_price; }

std::string Product::info() const {
    std::ostringstream os;
    os << "[" << m_id << "] " << m_title << " - $" << util::formatCurrency(m_price);
    return os.str();
}
