
#include <algorithm>
#include <cstdlib>

#include "generator.hpp"

Array generateSorted(std::size_t N) {
    Array array(N);
    for (std::size_t i = 0; i < N; ++i) {
        array[i] = i;
    }
    return array;
}

Array generateRandom(std::size_t N) {
    Array array(N);
    for (std::size_t i = 0; i < N; ++i) {
        array[i] = std::rand();
    }
    return array;
}

Array generateReverseSorted(std::size_t N) {
    Array array = generateSorted(N);
    std::reverse(array.begin(), array.end());
    return array;
}
