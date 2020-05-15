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

    size_t GetSize() const;

    T GetFirst() const;
    T & GetFirst();
    T GetLast() const;
    T & GetLast();
    T GetElementData(size_t) const;
    T & GetElementData(size_t);



    // **** Setters ****

    void SetSize(size_t);


    // **** Utils ****

    List<T> * GetSubList(size_t, size_t) const;
    void Prepend(T);
    void InsertAt(size_t, T);
    void Append(T);

public:

    struct Node;

    // ****** Private Methods ******


    // **** Getters ****

    Node * GetHead() const;
    Node GetNode(size_t) const;
    Node & GetNode(size_t);


    // **** Setters ****

    void SetHead(Node *);


    // **** Member Variables ****

    struct Node {

        // **** Constructors ****

        Node()
            : data_(T(0)), next_(nullptr) {}

        explicit Node(T data, Node *next = nullptr)
            : data_(data), next_(next) {}


        // **** Destructor ****
        // If I uncomment this than program will free \
        nodes twice. First in List destructor then \
        in Node destructor which will cause error

//        ~Node(){
//            if (GetNext() != nullptr) delete next_;
//        }


        // **** Getters ****

        T GetData() const { return data_; }
        T & GetData() { return data_; }
        Node * GetNext() { return next_; }


        // **** Member Variables ****

        T data_;
        Node *next_;
    };

public:
    size_t size_;
    Node *head_;
};


#include "ListImplementation.hpp"