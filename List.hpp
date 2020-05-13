//
// Created by Vasiliy Evdokimov on 12.05.2020.
//

#pragma once

#include <iostream>


template<typename T>
class List {
public:

    // **** Constructors ****

    List();
    List(T*, size_t);

    // ** Copy Constructor

    List(List<T> const &);


    // **** Operators ****

    //


    // **** Destructor ****

    ~List();


    // **** Getters ****

    T GetFirst() const;
    T & GetFirst();
    T GetLast() const;
    T & GetLast();
    T GetElement() const;
    T & GetElement();
    size_t GetSize() const;


    // **** Setters ****

    //


    // **** Utils ****

    List<T> * GetSubList(size_t, size_t);
    void Prepend(T);
    void Insert(size_t, T);
    void Append(T);

public:

    struct Node {
        T data_ = T(0);
        Node *next_ = nullptr;
    };

    size_t size_;
    Node *head_;
};


#include "ListImplementation.hpp"