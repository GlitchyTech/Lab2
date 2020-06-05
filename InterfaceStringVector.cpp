//
// Created by Vasiliy Evdokimov on 05.06.2020.
//

#include <iostream>

#include "InterfaceStringVector.hpp"
#include "StringVector.hpp"

void InterfaceStringVector(){
    StringV s = "";
    StringV option = "";

    std::cin >> s;

    std::cout << "Menu : \n"
                 "1. Concatenate\n"
                 "2. Resize\n"
                 "3. Add symbol\n"
                 "4. Erase symbol\n"
                 "5. Get symbol\n"
                 "6. Get size\n";

}
