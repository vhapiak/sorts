#include <chrono>
#include <iostream>
#include <memory>

#include "checker.hpp"
#include "generator.hpp"
#include "types.hpp"

#include "algo/CHeapSort.hpp"
#include "algo/CMergeSort.hpp"
#include "algo/CQuickSort.hpp"
#include "algo/CStdQSort.hpp"
#include "algo/CStdSort.hpp"

struct Data {
    const char* m_name;
    Array m_data;
};

int main() {
    const std::size_t N = 1000000;
    const std::vector<Data> dataSet = {
        {"sorted", generateSorted(N)},
        {"random", generateRandom(N)},
        {"reverse sorted", generateReverseSorted(N)},
    };

    using SortPtr = std::shared_ptr<ISort>;
    const std::vector<SortPtr> algos = {
        SortPtr(new CHeapSort()), SortPtr(new CQuickSort()), SortPtr(new CMergeSort()),
        SortPtr(new CStdSort()),  SortPtr(new CStdQSort()),
    };

    for (const auto& algo : algos) {
        auto data = dataSet;
        std::cout << "Algo: " << algo->name() << std::endl;
        for (auto& array : data) {
            auto start = std::chrono::system_clock::now();
            algo->sort(array.m_data);
            auto end = std::chrono::system_clock::now();
            auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

            if (!check(array.m_data)) {
                throw std::runtime_error("sort failed");
            }
            std::cout << "\tTest: " << array.m_name << ' ' << elapsed.count() << "ms" << std::endl;
        }
    }

    return 0;
}
