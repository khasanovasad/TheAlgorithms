/**
 * @file    Deque.h
 * @author  Asadbek Khasanov
 * @date    October 17, 2020
 * @brief   File containing the implementation of generic Double Ended
 *          Queue with doubly linked list as its underlying sturcture.
 **/

#ifndef DEQUE_H
#define DEQUE_H

#include <stdexcept>

#include "DLinkedList.h"

namespace DSCpp {
    template <typename T>
    class Deque {
        private:
            DLinkedList<T> *list = nullptr;

        public:
            Deque();

            ~Deque();

            /**
             * Function to push push element to the front of the deque.
             * @param element constant reference to the new element
             **/
            void PushFront(const T& element);


            void PushBack(const T& element);


            T PopFront();


            T PopBack();


            T& Front() const;


            T& Back() const;


            [[nodiscard]] size_t Count() const;


            [[nodiscard]] bool IsEmpty() const;
    };

    template <typename T>
    Deque<T>::Deque() {
        list = new DLinkedList<T>();
    }

    template <typename T>
    Deque<T>::~Deque() {
        delete list;
        list = nullptr;        
    }

    template <typename T>
    void Deque<T>::PushFront(const T& element) {
        list->InsertFront(element);
    }

    template <typename T>
    void Deque<T>::PushBack(const T& element) {
        list->InsertBack(element);
    }

    template <typename T>
    T Deque<T>::PopFront() {
        if (!IsEmpty()) {
            T tmp = list->ElementFront();
            list->RemoveFront();
            return tmp;
        } else {
            throw std::underflow_error("Deque Underflow!");
        }
    }

    template <typename T>
    T Deque<T>::PopBack() {
        if (!IsEmpty()) {
            T tmp = list->ElementBack();
            list->RemoveBack();
            return tmp;
        } else {
            throw std::underflow_error("Deque Underflow!");
        }
    }

    template <typename T>
    T& Deque<T>::Front() const {
        return list->ElementFront();
    }

    template <typename T>
    T& Deque<T>::Back() const {
        return list->ElementBack();
    }

    template <typename T>
    [[nodiscard]] size_t Deque<T>::Count() const {
        return list->Count();
    }

    template <typename T>
    [[nodiscard]] bool Deque<T>::IsEmpty() const {
        return list->IsEmpty();
    }
}

#endif // DEQUE_H