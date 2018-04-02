#pragma once

#include "algo/ISort.hpp"

class CQuickSort : public ISort {
    const char* name() const override;
    void sort(Array& array) override;
};
