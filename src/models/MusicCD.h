#pragma once
#include "Product.h"
#include <string>

class MusicCD : public Product {
public:
    MusicCD(int id, std::string title, double price, std::string artist);
    std::string artist() const;
    std::string info() const override;
private:
    std::string m_artist;
};
