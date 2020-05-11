//
// Created by Vasiliy Evdokimov on 20.04.2020.
//

#pragma once

#include <iostream>

template<typename T>
class DynamicArray {
public:

    // *** Constructors ***

    DynamicArray(size_t);

    // ** Copy Constructor **

    DynamicArray(DynamicArray const &);


    // *** Operators ***

    DynamicArray & operator=(DynamicArray const &);
    T operator[](size_t) const;
    T & operator[](size_t);

    // *** Destructor ***

    ~DynamicArray();


    // *** Getters ***

    size_t GetSize () const;
    size_t GetCapacity() const;
    T* GetData() const;


    // *** Setters ***

    void Resize(size_t);


    // *** Utils ***

    //

private:

    // *** Private Methods ***

    void SwapAttributes(DynamicArray &);
    void ChangeCapacity();


    // *** Member Variables ***

    size_t size_;
    size_t capacity_;
    T* data_;
};

#include "DynamicArrayImplementation.h"
