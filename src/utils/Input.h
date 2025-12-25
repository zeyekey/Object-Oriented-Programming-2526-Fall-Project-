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

    inline int getInt(const std::string& prompt) {
        while (true) {
            std::string s = getString(prompt);
            try {
                size_t pos = 0;
                int v = std::stoi(s, &pos);
                if (pos == s.size()) return v;
            } catch (...) {}
            std::cout << "Geçersiz sayı, tekrar deneyin.\n";
        }
    }
}
