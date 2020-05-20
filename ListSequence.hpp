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
    ListSequence(List<T> const &);
    ListSequence(T *, size_t);
    //ListSequence(List<T>);


    // ** Copy Constructor **

    ListSequence(ListSequence<T> const &);


    // **** Destructor ****

    ~ListSequence() = default;


    // **** Operators ****

    ListSequence<T> * operator+(ISequence<T>);
    T operator[](size_t) const;
    T & operator[](size_t);

    template<typename TT>
    friend std::istream & operator>>(std::istream &, ListSequence<TT> &);

    template<typename TT>
    friend std::ostream & operator<<(std::ostream &, ListSequence<TT> const &);


    // **** Getters ****

    List<T> GetList() const;
    List<T> & GetList();
    T GetFirst() const;
    T & GetFirst();
    T GetLast() const;
    T & GetLast();
    T GetElementData(size_t) const;
    T & GetElementData(size_t);
    size_t GetSize() const;


    // **** Setters ****

    void SetSize(size_t);


    // **** Modifiers ****

    void Prepend(T);
    void InsertAt(size_t, T);
    void Append(T);
    void PopFirst();
    void EraseAt(size_t);
    void PopBack();
    ListSequence<T> * Concatenation(ISequence<T> *);


private:

    List<T> list_;

};


#include "ListSequenceImplementation.hpp"