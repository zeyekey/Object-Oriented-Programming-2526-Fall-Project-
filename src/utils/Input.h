#pragma once
#include <string>
#include <iostream>

namespace utils {
    inline std::string getString(const std::string& prompt) {
        std::string s;
        if (!prompt.empty()) std::cout << prompt;
        std::getline(std::cin, s);
        return s;
    }
}
