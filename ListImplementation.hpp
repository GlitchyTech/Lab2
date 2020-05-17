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

//template<typename T>
//List<T> * operator+(List<T> a, List<T> b){
//    List<T> *pNew_list = ;
//    size_t new_size = a.GetSize() + b.GetSize();
//
//    for (size_t i = 0; i < new_size; ++i){
//        if (i == a.GetSize()){
//
//        }
//        else
//    }
//}

template<typename T>
std::ostream & operator<<(std::ostream & os, List<T> list) { return os << list.GetFirst(); }


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
size_t List<T>::GetSize() const { return size_; }

template<typename T>
T List<T>::GetElementData(size_t i) const {
    IsErrorOutOfRange(i, GetSize());

    Node *pCur_node = GetHead();
    for (size_t iElem = 0; iElem < i; ++iElem){
        pCur_node = pCur_node->GetNext();
    }

    return pCur_node->GetData();
}

template<typename T>
T & List<T>::GetElementData(size_t i) {
    IsExceptionOutOfRange(i, GetSize());

    Node *pCur_node = GetHead();
    for (size_t iElem = 0; iElem < i; ++iElem){
        pCur_node = pCur_node->GetNext();
    }

    return pCur_node->GetData();
}

template<typename T>
T List<T>::GetFirst() const {
    IsExceptionLength(GetSize(), 1);
    return GetElementData(0);
}

template<typename T>
T & List<T>::GetFirst() {
    IsExceptionLength(GetSize(), 1);
    return GetElementData(0);
}

template<typename T>
T List<T>::GetLast() const {
    IsExceptionLength(GetSize(), 1);
    return GetElementData(GetSize() - 1);
}

template<typename T>
T & List<T>::GetLast() {
    IsExceptionLength(GetSize(), 1);
    return GetElementData(GetSize() - 1);
}


// Creates unique list so that changing one of them \
doesn't affect the other (I tested this)

template<typename T>
List<T> * List<T>::GetSubList(size_t start, size_t end) {
    IsEndBiggerStart(start + 1, end);
    IsExceptionOutOfRange(start, GetSize());
    IsExceptionOutOfRange(end, GetSize());

    List<T> *pNew_list = new List;
    Node *pCur_node = &GetNode(start);
    for (size_t i = 0; i < end - start; ++i){
        pNew_list->Append(pCur_node->GetData());
        pCur_node = pCur_node->GetNext();
    }

    return pNew_list;
}

// **** Setters ****

template<typename T>
void List<T>::SetSize(size_t newSize) { size_ = newSize; }


// **** Modifiers ****

template<typename T>
void List<T>::InsertAt(size_t i, T data){
    IsExceptionOutOfRange(i, GetSize() + 1);

    if (i == 0){
        Node *pNew_head = new Node(data, GetHead());
        SetHead(pNew_head);
    }
    else {
        Node *pCur_node = &GetNode(i - 1);
        Node *pNext_node = pCur_node->GetNext();
        pCur_node->next_ = new Node(data, pNext_node);
    }

    SetSize(GetSize() + 1);
}

template<typename T>
void List<T>::Prepend(T data) { InsertAt(0, data); }

template<typename T>
void List<T>::Append(T data) { InsertAt(GetSize(), data); }

// ****** Private Methods ******


// **** Getters ****

template<typename T>
typename List<T>::Node * List<T>::GetHead() const { return head_; }

template<typename T>
typename List<T>::Node & List<T>::GetNode(size_t i){
    IsExceptionOutOfRange(i, GetSize());

    Node *pCur_node = GetHead();
    for (size_t iElem = 0; iElem < i; ++iElem){
        pCur_node = pCur_node->GetNext();
    }

    return *pCur_node;
}

template<typename T>
typename List<T>::Node List<T>::GetNode(size_t i) const {
    IsExceptionOutOfRange(i, GetSize());

    Node *pCur_node = GetHead();
    for (size_t iElem = 0; iElem < i; ++iElem){
        pCur_node = pCur_node->GetNext();
    }

    return *pCur_node;
}


// **** Setters ****

template<typename T>
void List<T>::SetHead(Node *pNewHead) { head_ = pNewHead; }