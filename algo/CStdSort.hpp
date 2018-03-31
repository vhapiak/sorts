#pragma once

#include "algo/ISort.hpp"

class CStdSort : public ISort {
    const char* name() const override;
    void sort(Array& array) override;
};
