#include <iostream>
#include "DynamicArray.hpp"
#include "ArraySequence.hpp"
#include "List.hpp"
#include "ListSequence.hpp"


int main() {
    ArraySequence<int> array(3);
    array[0] = 0;
    array[1] = 1;
    array[2] = 2;
    ArraySequence<int> array2 = array;
    std::cout << array2;

    ListSequence<int> list;
    list.Append(1);
    list.Append(2);
    list.Append(-3);
    std::cout << list;
    return 0;
}
