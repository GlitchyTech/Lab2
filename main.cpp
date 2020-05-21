#include <iostream>
#include "DynamicArray.hpp"
#include "ArraySequence.hpp"
#include "List.hpp"
#include "ListSequence.hpp"
#include "StringVector.hpp"
#include "StringList.hpp"
#include "Interface.hpp"


int main() {
    StringV str = "abcdef", str2;
    std::cin >> str >> str2;
    str2 = str;
    std::cout << str << str2 << str + str2;
    return 0;
}
