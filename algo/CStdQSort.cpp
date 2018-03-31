
#include <algorithm>

#include "algo/CStdQSort.hpp"

const char* CStdQSort::name() const {
    return "std qsort";
}

void CStdQSort::sort(Array& array) {
    std::qsort(array.data(), array.size(), sizeof(Array::value_type),
               [](const void* a, const void* b) -> int {
                   auto arg1 = *static_cast<const Array::value_type*>(a);
                   auto arg2 = *static_cast<const Array::value_type*>(b);

                   if (arg1 < arg2) return -1;
                   if (arg1 > arg2) return 1;
                   return 0;
               });
}
