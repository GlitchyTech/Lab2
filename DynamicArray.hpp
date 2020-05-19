//
// Created by Vasiliy Evdokimov on 20.04.2020.
//

#pragma once

#include <iostream>

extern size_t const DEFAULT_CAPACITY;

template<typename T>
class DynamicArray {
public:

    // **** Constructors ****

    DynamicArray();
    explicit DynamicArray(size_t);
    DynamicArray(T *, size_t);

    // ** Copy Constructor **

    DynamicArray(DynamicArray<T> const &);


    // **** Operators ****

    DynamicArray & operator=(DynamicArray const &);
    T operator[](size_t) const;
    T & operator[](size_t);


    // **** Destructor ****

    ~DynamicArray();
    void FreeData();


    // **** Getters ****

    T GetFirst() const;
    T & GetFirst();
    T GetLast() const;
    T & GetLast();
    size_t GetSize () const;
    size_t GetCapacity() const;
    T * GetData() const;
    T GetElem(size_t) const;
    T & GetElem(size_t);


    // **** Setters ****

    void Resize(size_t);
    void SetSize(size_t);
    void SetCapacity(size_t);
    void SetData(T *);
    void SetElement(size_t, T);


    // **** Utils ****

    void PushBack(T);
    //void CopyDataValues(T *);

private:

    // ****** Private Methods ******

    // Needed to make it easier to implement public interface \
       but they are dangerous to make public cause user \
       can by mistake change invariants

    // **** Private Utils ****

    void SwapAttributes(DynamicArray &);
    void ChangeCapacity();
    void ExpandCapacity();


    // **** Member Variables ****

    size_t size_;
    size_t capacity_;
    T *data_;
};

#include "DynamicArrayImplementation.hpp"
