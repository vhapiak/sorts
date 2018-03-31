#pragma once

#include "algo/ISort.hpp"

class CMergeSort : public ISort {
    const char* name() const override;
    void sort(Array& array) override;
};
