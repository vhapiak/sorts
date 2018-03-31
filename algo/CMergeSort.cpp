
#include "algo/CMergeSort.hpp"

namespace {

void mergeSort(Array& array, Array& buffer, const std::size_t start, const std::size_t end) {
    const std::size_t size = end - start;
    if (size <= 1) {
        return;
    }

    const std::size_t middle = (start + end) / 2;
    mergeSort(array, buffer, start, middle);
    mergeSort(array, buffer, middle, end);

    std::size_t first_pointer = start;
    std::size_t second_pointer = middle;
    for (std::size_t i = 0; i < size; ++i) {
        if (first_pointer == middle) {
            buffer[i] = array[second_pointer++];
        } else if (second_pointer == end) {
            buffer[i] = array[first_pointer++];
        } else if (array[first_pointer] <= array[second_pointer]) {
            buffer[i] = array[first_pointer++];
        } else {
            buffer[i] = array[second_pointer++];
        }
    }

    for (std::size_t i = 0; i < size; ++i) {
        array[start + i] = buffer[i];
    }
}

}  // namespace

const char* CMergeSort::name() const {
    return "merge sort";
}

void CMergeSort::sort(Array& array) {
    Array buffer(array.size());
    mergeSort(array, buffer, 0, array.size());
}
