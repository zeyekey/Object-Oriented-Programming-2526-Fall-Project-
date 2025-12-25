#include "MusicCD.h"
#include <sstream>

MusicCD::MusicCD(int id, std::string title, double price, std::string artist)
    : Product(id, std::move(title), price), m_artist(std::move(artist)) {}

std::string MusicCD::artist() const { return m_artist; }

std::string MusicCD::info() const {
    std::ostringstream os;
    os << Product::info() << " (MusicCD) by " << m_artist;
    return os.str();
}
