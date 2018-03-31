
#include "checker.hpp"

bool check(const Array& array) {
    for (std::size_t i = 1; i < array.size(); ++i) {
        if (array[i - 1] > array[i]) {
            return false;
        }
    }
    return true;
}
