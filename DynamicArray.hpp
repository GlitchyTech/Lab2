//
// Created by Vasiliy Evdokimov on 20.04.2020.
//

#pragma once

#include <iostream>

template<typename T>
class DynamicArray {
public:

    // **** Constructors ****

    explicit DynamicArray(size_t);

    // ** Copy Constructor **

    DynamicArray(DynamicArray const &);


    // **** Operators ****

    DynamicArray & operator=(DynamicArray const &);
    T operator[](size_t) const;
    T & operator[](size_t);


    // **** Destructor ****

    ~DynamicArray();
    void FreeData();


    // **** Getters ****

    size_t GetSize () const;
    size_t GetCapacity() const;
    T* GetData() const;
    T GetElem(size_t) const;
    T & GetElem(size_t);


    // **** Setters ****

    void Resize(size_t const);
    void SetSize(size_t const);
    void SetCapacity(size_t const);
    void SetData(T*);
    void SetElement(size_t, T);


    // **** Utils ****

    void PushBack(T);
    //void CopyDataValues(T*);

private:

    // ****** Private Methods ******

    // Needed to make it easier to implement public interface \
       but they are dangerous to make public cause user \
       can by mistake change invariants

    // **** Private Utils ****

    void SwapAttributes(DynamicArray &);
    void ChangeCapacity();
    void ExpandCapacity();


    // **** Error Handling ****

    void IsErrorOutOfRange(size_t) const;
    void IsErrorLength(size_t) const;



    // **** Member Variables ****

    size_t size_;
    size_t capacity_;
    T* data_;
};

#include "DynamicArrayImplementation.hpp"
