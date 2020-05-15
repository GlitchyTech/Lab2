//
// Created by Vasiliy Evdokimov on 12.05.2020.
//

#pragma once

#include <iostream>
#include <stdexcept>

// **** Error Handling ****

void IsExceptionOutOfRange(size_t, size_t);
void IsExceptionLength(size_t, size_t = 0);
void IsEndBiggerStart(size_t, size_t);