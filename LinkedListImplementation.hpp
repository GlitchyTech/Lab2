//
// Created by Vasiliy Evdokimov on 12.05.2020.
//

#pragma once

#include <stdexcept>
#include <string>
#include "Utils.hpp"


// **** Constructors ****

template<typename T>
List<T>::List()
    : size_(0), head_(nullptr) {}

template<typename T>
List<T>::List(T *pData, size_t size)
    : size_(size)
    {
        Node **ppCur_node = &head_;
        for (size_t i = 0; i != size; ++i){
            *ppCur_node = new Node;
            (*ppCur_node)->data_ = pData[i];
            ppCur_node = &((*ppCur_node)->next_);
        }
    }

// ** Copy Constructor **

template<typename T>
List<T>::List(List<T> const &rList)
    : size_(rList.size_){
    Node **ppCur_node = &head_;
    Node * const *ppCur_node_copy = &rList.head_;
    for (size_t i = 0; i != size_; ++i){
        *ppCur_node = new Node;
        (*ppCur_node)->data_ = (*ppCur_node_copy)->data_;
        ppCur_node = &((*ppCur_node)->next_);
        ppCur_node_copy = &((*ppCur_node_copy)->next_);
    }
}


// **** Operators ****

//


// **** Destructor ****

template<typename T>
List<T>::~List(){
    if (head_ != nullptr) {
        Node *pCur_node = head_;
        for (size_t i = 0; i != size_; ++i){
            Node *pNext_node = pCur_node->next_;
            delete pCur_node;
            pCur_node = pNext_node;
        }

        head_ = nullptr;
    }
}


// **** Getters ****

template<typename T>
T List<T>::GetFirst() const {

}


// **** Setters ****

//


// **** Utils ****

//


