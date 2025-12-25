#include "Formatter.h"
#include <sstream>
#include <iomanip>

namespace util {
    std::string formatCurrency(double value) {
        std::ostringstream os;
        os << std::fixed << std::setprecision(2) << value;
        return os.str();
    }
}
