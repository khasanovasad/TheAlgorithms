/**
 * @file    Stack.h
 * @author  Asadbek Khasanov
 * @date    October 16, 2020
 * @brief   File containing the implementation of generic Stack data
 *          structure using generic doubly linked list.
 **/

#ifndef STACK_H
#define STACK_H

#include <stdexcept> 

#include "list.h"

namespace ds {
    /**
     * Templated class as an interface to Stack ADT
     **/
    template <typename T>
    class Stack {
        private:
            // list<T> is the underlying data structure to hold
            // the actual data in certain organization. Stack class only 
            // controls how the data is accessed and inserted.
            list<T> *list = nullptr;

        public:
            Stack();

            ~Stack();

            /**
             * Function to push element_ on to the stack.
             * @param element_ constant reference to T type object
             **/
            void Push(const T &element_);

            /**
             * Function to pop element_ from the top of the stack.
             * Thorows std::underflow_error if the stack is empty and
             * there is no element_ to pop.
             * @return copy of the element_ on the top of the stack.
             **/
            T Pop();

            /**
             * Function to return a reference to the top of the stack.
             * Throws std::underflow_error if the stack is empty and
             * there is no element_ on the top of the stack.
             * @return reference to the top of the stack. 
             **/
            T& Top() const;

            /**
             * Function that counts the number of element_s in the stack
             * and returns it. Discarding the return value will couse compiler
             * warnings.
             * @return number of element_s on the stack.
             **/
            [[nodiscard]] int Count() const;

            /**
             * Function that to determine if the stack is empty.
             * Discarding the return value will couse compiler warnings.
             * @return true if the stack is empty
             *         false otherwise
             **/
            [[nodiscard]] bool IsEmpty() const;
    };

    template <typename T>
    Stack<T>::Stack() {
        list = new list<T>();
    }

    template <typename T>
    Stack<T>::~Stack() {
        delete list;    
        list = nullptr;
    }

    template <typename T>
    void Stack<T>::Push(const T &element_) {
        list->add_back(element_);
    }

    template <typename T>
    T Stack<T>::Pop() {
        if (!IsEmpty()) {
            T tmp = list->get_back();
            list->delete_back();
            return tmp;
        } else {
            throw std::underflow_error("Stack Underflow!");
        }
    }

    template <typename T>
    T& Stack<T>::Top() const {
        if (!IsEmpty()) {
            return list->get_back();
        } else {
            throw std::underflow_error("Stack Underflow!");
        }
    }

    template <typename T>
    [[nodiscard]] int Stack<T>::Count() const {
        return list->count();
    }

    template <typename T>
    [[nodiscard]] bool Stack<T>::IsEmpty() const {
        return list->is_empty();
    }
}

#endif // STACK_H
