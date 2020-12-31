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

#include "list.h"

namespace ds {
    /**
     * Templated class as an interface to Deque ADT
     **/
    template <typename T>
    class Deque {
        private:
            // list<T> is the underlying data structure to hold
            // the actual data in certain organization. Deque class only 
            // controls how the data is accessed and inserted.
            list<T> *list = nullptr;

        public:
            Deque();

            ~Deque();

            /**
             * Function to push push element to the front of the deque.
             * @param element constant reference to the new element
             **/
            void PushFront(const T& element);

            /**
             * Function to push push element to the back of the deque.
             * @param element constant reference to the new element
             **/
            void PushBack(const T& element);

            /**
             * Function to pop element from the front of the deque.
             * Thorows std::underflow_error if the deque is empty and
             * there is no element to pop.
             * @return copy of the element from the front of the deque
             **/
            T PopFront();

            /**
             * Function to pop element from the back of the deque.
             * Thorows std::underflow_error if the deque is empty and
             * there is no element to pop.
             * @return copy of the element from the back of the deque
             **/
            T PopBack();

            /**
             * Function to return a reference to the front of the deque.
             * Throws std::underflow_error if the deque is empty and
             * there is no element at the front of the deque.
             * @return reference to the front of the deque. 
             **/
            T& Front() const;

            /**
             * Function to return a reference to the back of the deque.
             * Throws std::underflow_error if the deque is empty and
             * there is no element at the back of the deque.
             * @return reference to the back of the deque. 
             **/
            T& Back() const;

            /**
             * Function that counts the number of elements in the deque
             * and returns it. Discarding the return value will couse compiler
             * warnings.
             * @return number of elements in the deque.
             **/
            [[nodiscard]] size_t Count() const;

            /**
             * Function to determine if the deque is empty.
             * Discarding the return value will couse compiler warnings.
             * @return true if the deque is empty
             *         false otherwise
             **/
            [[nodiscard]] bool IsEmpty() const;
    };

    template <typename T>
    Deque<T>::Deque() {
        list = new list<T>();
    }

    template <typename T>
    Deque<T>::~Deque() {
        delete list;
        list = nullptr;        
    }

    template <typename T>
    void Deque<T>::PushFront(const T& element) {
        list->add_front(element);
    }

    template <typename T>
    void Deque<T>::PushBack(const T& element) {
        list->add_back(element);
    }

    template <typename T>
    T Deque<T>::PopFront() {
        if (!IsEmpty()) {
            T tmp = list->get_front();
            list->delete_front();
            return tmp;
        } else {
            throw std::underflow_error("Deque Underflow!");
        }
    }

    template <typename T>
    T Deque<T>::PopBack() {
        if (!IsEmpty()) {
            T tmp = list->get_back();
            list->delete_back();
            return tmp;
        } else {
            throw std::underflow_error("Deque Underflow!");
        }
    }

    template <typename T>
    T& Deque<T>::Front() const {
        return list->get_front();
    }

    template <typename T>
    T& Deque<T>::Back() const {
        return list->get_back();
    }

    template <typename T>
    [[nodiscard]] size_t Deque<T>::Count() const {
        return list->count();
    }

    template <typename T>
    [[nodiscard]] bool Deque<T>::IsEmpty() const {
        return list->is_empty();
    }
}

#endif // DEQUE_H
