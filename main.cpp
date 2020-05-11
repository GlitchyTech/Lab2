#include <iostream>
#include "DynamicArray.h"

#define info(msg) std::cout << (#msg) << " = " << (msg) <<  std::endl;

int main() {
    size_t size = 10;
    DynamicArray<int> darr(size);
    DynamicArray<int> darr2 = darr;
    DynamicArray<int> darr3(20);
    info(darr3.GetSize());
    darr3 = darr;
    info(darr3.GetSize());
    info(darr3.GetCapacity());
    darr3.Resize(450);
    info(darr3.GetSize());
    info(darr3.GetCapacity());
    return 0;
}
