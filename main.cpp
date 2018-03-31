#include <iostream>
#include <memory>

#include "checker.hpp"
#include "generator.hpp"
#include "types.hpp"

#include "algo/CMergeSort.hpp"

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
        SortPtr(new CMergeSort()),
    };

    for (const auto& algo : algos) {
        auto data = dataSet;
        std::cout << "Algo: " << algo->name() << std::endl;
        for (auto& array : data) {
            algo->sort(array.m_data);
            bool sorted = check(array.m_data);
            std::cout << "\tTest: " << array.m_name << ' ' << sorted << std::endl;
        }
    }

    return 0;
}
