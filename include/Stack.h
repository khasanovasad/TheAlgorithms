#ifndef STACK_H
#define STACK_H

#include <stdexcept> 

#include "DLinkedList.h"

namespace DSCpp {
    template <typename T>
    class Stack {
        private:
            DLinkedList<T> *list = nullptr;

        public:
            Stack();

            ~Stack();

            void Push(const T &element);

            T Pop();

            T& Top() const;

            [[nodiscard]] int Count() const;

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
        T tmp = list->ElementBack();
        list->RemoveBack();
        return tmp;
    }

    template <typename T>
    T& Stack<T>::Top() const {
        return list->ElementBack();     
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