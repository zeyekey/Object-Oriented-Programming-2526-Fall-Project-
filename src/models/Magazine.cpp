#include "Magazine.h"
#include <sstream>

Magazine::Magazine(int id, std::string title, double price, int issue)
    : Product(id, std::move(title), price), m_issue(issue) {}

int Magazine::issue() const { return m_issue; }

std::string Magazine::info() const {
    std::ostringstream os;
    os << Product::info() << " (Magazine) Issue " << m_issue;
    return os.str();
}
