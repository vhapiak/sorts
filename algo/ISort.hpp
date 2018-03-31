#pragma once

#include "types.hpp"

class ISort {
  public:
    virtual ~ISort() {}

    virtual const char* name() const = 0;
    virtual void sort(Array& array) = 0;
};
