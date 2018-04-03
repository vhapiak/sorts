
#include "algo/CHeapSort.hpp"

namespace {

void buildHeap(Array& array, const std::size_t root, const std::size_t n) {
    std::size_t largest = root;
    std::size_t left = 2 * root + 1;
    std::size_t right = 2 * root + 2;

    if (left < n && array[left] > array[largest]) {
        largest = left;
    }

    if (right < n && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != root) {
        std::swap(array[largest], array[root]);

        buildHeap(array, largest, n);
    }
}
}  // namespace

const char* CHeapSort::name() const {
    return "heap sort";
}

void CHeapSort::sort(Array& array) {
    for (std::size_t i = array.size() / 2; i > 0; --i) {
        buildHeap(array, i - 1, array.size());
    }

    for (std::size_t i = array.size(); i > 0; --i) {
        std::swap(array[0], array[i - 1]);
        buildHeap(array, 0, i - 1);
    }
}
