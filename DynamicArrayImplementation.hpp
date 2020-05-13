//
// Created by Vasiliy Evdokimov on 10.05.2020.
//

#pragma once

#include <stdexcept>
#include <string>
#include "Utils.hpp"


size_t const DEFAULT_CAPACITY = 300;


// **** Constructors ****

template<typename T>
DynamicArray<T>::DynamicArray(size_t size)
    : size_(size), capacity_(std::max(size_ + DEFAULT_CAPACITY, size_ * 2)), data_(new T[capacity_]) {
        IsErrorLength(size_);
    }

template<typename T>
DynamicArray<T>::DynamicArray(T* data, size_t numOfElements)
    : size_(numOfElements), capacity_(std::max(size_ + DEFAULT_CAPACITY, size_ * 2)), data_(data) {
        IsErrorLength(size_);
    }


// ** Copy Constructor **

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T> const &rDarr)
    : size_(rDarr.size_), capacity_(rDarr.capacity_), data_(new T[rDarr.size_])
    {
        IsErrorLength(size_);
        for (size_t i = 0; i != size_; ++i) GetData()[i] = rDarr[i];
    }


// **** Operators ****

// ** Assignment Operator **

template<typename T>
DynamicArray<T> & DynamicArray<T>::operator=(DynamicArray const &rDarr){
    if (this != &rDarr) DynamicArray(rDarr).SwapAttributes(*this);
    return *this;
}

// ** [] Operator const and non-const version **

template<typename T>
T DynamicArray<T>::operator[](size_t i) const {
    IsErrorOutOfRange(i, GetSize());
    return data_[i];
}

template<typename T>
T & DynamicArray<T>::operator[](size_t i) {
    IsErrorOutOfRange(i, GetSize());
    return data_[i];
}


// **** Destructor ****

template<typename T>
DynamicArray<T>::~DynamicArray(){
    delete [] data_;
}

template<typename T>
void DynamicArray<T>::FreeData(){
    if (GetData()) {
        delete [] GetData();
        data_ = nullptr;
    }
}


// **** Getters ****

template<typename T>
size_t DynamicArray<T>::GetSize() const { return size_; }

template<typename T>
size_t DynamicArray<T>::GetCapacity() const { return capacity_; }

template<typename T>
T* DynamicArray<T>::GetData() const { return data_; }

template<typename T>
T DynamicArray<T>::GetElem(size_t i) const {
    IsErrorOutOfRange(i, GetSize());
    return data_[i];
}

template<typename T>
T & DynamicArray<T>::GetElem(size_t i) {
    IsErrorOutOfRange(i, GetSize());
    return data_[i];
}


// **** Setters ****

template<typename T>
void DynamicArray<T>::Resize(size_t const newSize){
    IsErrorLength(newSize);
    DynamicArray<T> darr(newSize);
    size_t n = newSize > darr.GetSize() ? darr.GetSize() : newSize;
    for (size_t i = 0; i != n; ++i) darr[i] = GetData()[i];
    SwapAttributes(darr);
}

template<typename T>
void DynamicArray<T>::SetSize(size_t const newSize) { size_ = newSize; }

template<typename T>
void DynamicArray<T>::SetCapacity(size_t const newCapacity) { capacity_ = newCapacity; }

template<typename T>
void DynamicArray<T>::SetData(T* newData) {
    FreeData();
    data_ = newData;
}

template<typename T>
void DynamicArray<T>::SetElement(size_t i, T value) { GetElem(i) = value; }


// **** Utils ****

template<typename T>
void DynamicArray<T>::PushBack(T newElem){
    if (GetCapacity() <= GetSize() + 1) ExpandCapacity();

    SetSize(GetSize() + 1);
    SetElement(GetSize() - 1, newElem);
}


// **** Private Methods ****

template<typename T>
void DynamicArray<T>::SwapAttributes(DynamicArray &rDarr){
    std::swap(size_, rDarr.size_);
    std::swap(capacity_, rDarr.capacity_);
    std::swap(data_, rDarr.data_);
}

template<typename T>
void DynamicArray<T>::ExpandCapacity(){
    SetCapacity(GetCapacity() * 2);
    T* new_data = new T[GetCapacity()];
    for (size_t iElem = 0; iElem != GetSize(); ++iElem)
        new_data[iElem] = GetElem(iElem);

    SetData(new_data);
}