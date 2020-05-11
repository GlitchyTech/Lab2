//
// Created by Vasiliy Evdokimov on 10.05.2020.
//

#pragma once

//
// Created by Vasiliy Evdokimov on 21.04.2020.
//

//template<typename T>
//using DynamicArrayT = DynamicArray<T>;

size_t const DEFAULT_CAPACITY = 100;

// *** Constructors ***

template<typename T>
DynamicArray<T>::DynamicArray(size_t size)
        : size_(size), capacity_(std::max(size_, DEFAULT_CAPACITY)), data_(new T[capacity_]) {}

// ** Copy Constructor **

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray const &rDarr)
    : size_(rDarr.size_), capacity_(rDarr.capacity_), data_(new T[rDarr.size_])
    {
        for (size_t i = 0; i != size_; ++i) data_[i] = rDarr.data_[i];
    }

// *** Operators ***

// ** Assignment Operator **

template<typename T>
DynamicArray<T> & DynamicArray<T>::operator=(DynamicArray const &rDarr){
    if (this != &rDarr) DynamicArray(rDarr).SwapAttributes(*this);
    return *this;
}

template<typename T>
T DynamicArray<T>::operator[](size_t i) const { return data_[i]; }

template<typename T>
T & DynamicArray<T>::operator[](size_t i) { return data_[i]; }


// *** Destructor ***

template<typename T>
DynamicArray<T>::~DynamicArray(){
    delete [] data_;
}


// *** Getters ***

template<typename T>
size_t DynamicArray<T>::GetSize() const { return size_; }

template<typename T>
size_t DynamicArray<T>::GetCapacity() const { return capacity_; }

template<typename T>
T* DynamicArray<T>::GetData() const { return data_; }


// *** Setters ***

template<typename T>
void DynamicArray<T>::Resize(size_t newSize){
    DynamicArray<T> darr(newSize);
    size_t n = newSize > darr.GetSize() ? darr.GetSize() : newSize;
    for (size_t i = 0; i != n; ++i) darr[i] = data_[i];
    SwapAttributes(darr);
}


// *** Utils ***

template<typename T>
void DynamicArray<T>::SwapAttributes(DynamicArray &rDarr){
    std::swap(size_, rDarr.size_);
    std::swap(capacity_, rDarr.capacity_);
    std::swap(data_, rDarr.data_);
}

