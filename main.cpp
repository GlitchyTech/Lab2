#include <iostream>
#include "DynamicArray.hpp"
#include "ArraySequence.hpp"
#include "List.hpp"
#include "ListSequence.hpp"


int main() {
    List<int> list;
    std::cin >> list;
    std::cout << list;
    list.EraseAt(3);
    std::cout << list;
    list.PopFirst();
    std::cout << list;
    list.PopBack();
    std::cout << list;
    return 0;
}
