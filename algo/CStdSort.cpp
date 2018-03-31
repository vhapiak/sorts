
#include <algorithm>

#include "algo/CStdSort.hpp"

const char* CStdSort::name() const {
    return "std sort";
}

void CStdSort::sort(Array& array) {
    std::sort(array.begin(), array.end());
}
