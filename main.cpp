#include <iostream>
#include "DynamicArray.hpp"

#define info(msg) std::cout << (#msg) << " = " << (msg) <<  std::endl;

int main() {
    size_t size = 10;
    DynamicArray<int> darr(size);
    DynamicArray<int> darr2 = darr;
    DynamicArray<int> darr3(20);

    darr[0] = 184;
    darr[1] = 231;
    darr[2] = 334;

    info(darr[2]);
    darr.SetElement(2, 666);
    info(darr[2]);

    return 0;
}
