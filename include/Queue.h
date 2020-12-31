/**
 * @file    Queue.h
 * @author  Asadbek Khasanov
 * @date    October 16, 2020
 * @brief   File containing the implementation of generic Queue
 *          data structure using generic doubly linked list.
 **/

#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

#include "list.h"

namespace ds {
    /**
     * Templated class as an interface to Queue ADT
     **/
    template <typename T>
    class Queue {
        private:
            // list<T> is the underlying data structure to hold
            // the actual data in certain organization. Queue class only 
            // controls how the data is accessed and inserted.
            list<T> *list = nullptr;

        public:
            Queue();      

            ~Queue();

            /**
             * Function to push element_ to the back of the queue.
             * @param element_ constant reference to T type object
             **/
            void Push(const T &element_);

            /**
             * Function to pop element_ from the front of the queue.
             * Thorows std::underflow_error if the queue is empty and
             * there is no element_ to pop.
             * @return copy of the element_ from the front of the queque
             **/
            T Pop();

            /**
             * Function to return a reference to the front of the queue.
             * Throws std::underflow_error if the queue is empty and
             * there is no element_ at the front of the queue.
             * @return reference to the front of the queue. 
             **/
            T& Front() const;

            /**
             * Function to return a reference to the back of the queue.
             * Throws std::underflow_error if the queue is empty and
             * there is no element_ at the back of the queue.
             * @return reference to the back of the queue. 
             **/
            T& Back() const;

            /**
             * Function that counts the number of element_s in the queue
             * and returns it. Discarding the return value will couse compiler
             * warnings.
             * @return number of element_s in the queue.
             **/
            [[nodiscard]] int Count() const;

            /**
             * Function to determine if the queue is empty.
             * Discarding the return value will couse compiler warnings.
             * @return true if the queue is empty
             *         false otherwise
             **/
            [[nodiscard]] bool IsEmpty() const;
    };

    template <typename T>
    Queue<T>::Queue() {
        list = new list<T>();
    }

    template <typename T>
    Queue<T>::~Queue() {
        delete list;
        list = nullptr;
    }

    template <typename T>
    void Queue<T>::Push(const T& element_) {
        list->add_back(element_);
    }

    template <typename T>
    T Queue<T>::Pop() {
        if (!IsEmpty()) {
            T tmp = list->get_front();
            list->delete_front();
            return tmp;
        } else {
            throw std::underflow_error("Queue Underflow!");
        }
    }

    template <typename T>
    T& Queue<T>::Front() const {
        if (!IsEmpty()) {
            return list->get_front();
        } else {
            throw std::underflow_error("Queue Underflow!");
        }
    }

    template <typename T>
    T& Queue<T>::Back() const {
        if (!IsEmpty()) {
            return list->get_back();
        } else {
            throw std::underflow_error("Queue Underflow!");
        }
    }

    template <typename T>
    [[nodiscard]] int Queue<T>::Count() const {
        return list->count();
    }

    template <typename T>
    [[nodiscard]] bool Queue<T>::IsEmpty() const {
        return list->is_empty();
    }
}

#endif // QUEUE_H
