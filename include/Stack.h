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

#include "DLinkedList.h"

namespace DSCpp {
    /**
     * Templated class as an interface to Stack ADT
     **/
    template <typename T>
    class Stack {
        private:
            // DLinkedList<T> is the underlying data structure to hold
            // the actual data in certain organization. Stack class only 
            // controls how the data is accessed and inserted.
            DLinkedList<T> *list = nullptr;

        public:
            Stack();

            ~Stack();

            /**
             * Function to push element on to the stack.
             * @param element constant reference to T type object
             **/
            void Push(const T &element);

            /**
             * Function to pop element from the top of the stack.
             * Thorows std::underflow_error if the stack is empty and
             * there is no element to pop.
             * @return copy of the element on the top of the stack.
             **/
            T Pop();

            /**
             * Function to return a reference to the top of the stack.
             * Throws std::underflow_error if the stack is empty and
             * there is no element on the top of the stack.
             * @return reference to the top of the stack. 
             **/
            T& Top() const;

            /**
             * Function that counts the number of elements in the stack
             * and returns it. Discarding the return value will couse compiler
             * warnings.
             * @return number of elements on the stack.
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
        list = new DLinkedList<T>();
    }

    template <typename T>
    Stack<T>::~Stack() {
        delete list;    
        list = nullptr;
    }

    template <typename T>
    void Stack<T>::Push(const T &element) {
        list->InsertBack(element); 
    }

    template <typename T>
    T Stack<T>::Pop() {
        if (!IsEmpty()) {
            T tmp = list->ElementBack();
            list->RemoveBack();
            return tmp;
        } else {
            throw std::underflow_error("Stack Underflow!");
        }
    }

    template <typename T>
    T& Stack<T>::Top() const {
        if (!IsEmpty()) {
            return list->ElementBack();     
        } else {
            throw std::underflow_error("Stack Underflow!");
        }
    }

    template <typename T>
    [[nodiscard]] int Stack<T>::Count() const {
        return list->Count();
    }

    template <typename T>
    [[nodiscard]] bool Stack<T>::IsEmpty() const {
        return list->IsEmpty();
    }
}

#endif // STACK_H