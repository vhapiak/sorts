
#include "algo/CQuickSort.hpp"

namespace {

void quick_sort(Array& array, const long start, const long end) {
    if (end - start <= 1) {
        return;
    }
    const long middle = (start + end) / 2;
    const auto pivot = array[middle];

    long i = start;
    long j = end - 1;
    while (i <= j) {
        while (array[i] < pivot) {
            ++i;
        }

        while (array[j] > pivot) {
            --j;
        }

        if (i <= j) {
            std::swap(array[i], array[j]);
            ++i;
            --j;
        }
    }

    if (j > 0) {
        quick_sort(array, start, j + 1);
    }
    if (end > i) {
        quick_sort(array, i, end);
    }
}

}  // namespace

const char* CQuickSort::name() const {
    return "quick sort";
}

void CQuickSort::sort(Array& array) {
    quick_sort(array, 0, array.size());
}
