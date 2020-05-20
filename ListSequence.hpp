//
// Created by Vasiliy Evdokimov on 20.05.2020.
//

#pragma once

#include <iostream>
#include "ISequence.hpp"
#include "List.hpp"

template<typename T>
class ListSequence : public ISequence<T>{
public:

    // **** Constructors ****

    ListSequence();
    ListSequence(T *, size_t);


    // ** Copy Constructor

    ListSequence(ListSequence<T> const &);


    // **** Destructor ****

    ~ListSequence() = default;


    // **** Operators ****

    //


    // **** Getters ****

    //


    // **** Setters ****

    //


    // **** Modifiers ****

    //

private:

    List<T> list_;

};


#include "ListImplementation.hpp"