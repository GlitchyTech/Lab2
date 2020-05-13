//
// Created by Vasiliy Evdokimov on 12.05.2020.
//

#include "Utils.hpp"


std::string const INDEX_OUT_OF_RANGE = "ERROR: Index out of range \n";
std::string const NEGATIVE_SIZE = "ERROR : Size can't be negative \n";


// **** Error Handling ****

void IsErrorOutOfRange(size_t i, size_t size){
    if (i < 0 || i >= size) throw std::out_of_range(INDEX_OUT_OF_RANGE);
}

void IsErrorLength(size_t size){
    if (size < 0) throw std::length_error(NEGATIVE_SIZE);
}
