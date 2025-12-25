#include "Book.h"
#include <sstream>

Book::Book(int id, std::string title, double price, std::string author)
    : Product(id, std::move(title), price), m_author(std::move(author)) {}

std::string Book::author() const { return m_author; }

std::string Book::info() const {
    std::ostringstream os;
    os << Product::info() << " (Book) by " << m_author;
    return os.str();
}
