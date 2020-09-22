/**
 * @file    SLinkedList.h
 * @author  Asadbek Khasanov
 * @date    September 22, 2020
 * @brief   File contining the implementation of generic Singly Linked List
 *          data structure.
 **/

#ifndef S_LINKED_LIST_H
#define S_LINKED_LIST_H

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

template <typename T>
struct SNode {
    private:
        T element;
        SNode<T> *next;

        template <typename U>
        friend class SLinkedList;
};

template <typename T>
class SLinkedList {
    private:
        SNode<T> *head;      

        SNode<T>* CreateNode(T element);
    public:
        SLinkedList(int arg_count, ...);
        ~SLinkedList();

        bool InsertBack(T element);
        bool InsertFront(T element);
        bool InsertAt(T element, int index);

        T ElementBack() const;
        T ElementFront() const;
        T ElementAt(int index) const;

        bool RemoveBack();
        bool RemoveFront();
        bool RemoveAt(int index);

        size_t Size() const;
};

template <typename T>
SLinkedList<T>::SLinkedList(int arg_count, ...) {
    T tmp;
    va_list ap;
    va_start(ap, arg_count);

    tmp = va_arg(ap, T);
    SNode<T> *new_node = CreateNode(tmp);
    if (new_node != NULL)
        this->head = new_node;

    for (int i = 1; i < arg_count; ++i) {
        tmp = va_arg(ap, T);
        InsertBack(tmp);
    }
    va_end(ap);
}

template <typename T>
SLinkedList<T>::~SLinkedList() {
    SNode<T> *tmp;
    while (this->head != NULL) {
        tmp = this->head;
        this->head = this->head->next;
        delete tmp;
    }
}

template <typename T>
SNode<T>* SLinkedList<T>::CreateNode(T element) {
    SNode<T> *new_node = new SNode<T>();
    if (new_node == NULL) {
        return NULL;
    }
    else {
        new_node->element = element;
        new_node->next = NULL;
        return new_node;
    }
}

template <typename T>
bool SLinkedList<T>::InsertBack(T element) {
    SNode<T> *new_node = CreateNode(element);
    if (new_node == NULL) {
        return false;
    } 
    else {
        SNode<T> *tmp = this->head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = new_node;
        return true;
    }
}

template <typename T>
bool SLinkedList<T>::InsertFront(T element) {
    SNode<T> *new_node = CreateNode(element);
    if (new_node == NULL) {
        return false;
    } 
    else {
        new_node->next = this->head;
        this->head = new_node;
        return true;
    }
}

template <typename T>
bool SLinkedList<T>::InsertAt(T element, int index) {
    SNode<T> *new_node = CreateNode(element);
    size_t size = Size();
    if (new_node == NULL || index > size) {
        return false;
    }
    else {
        if (index == 0) {
            InsertFront(element);
        }
        else if (index == size) {
            InsertBack(element);
        }
        else {
            SNode<T> *tmp = this->head;
            for (int i = 0; i < index - 1; ++i) {
                tmp = tmp->next;
            }
            new_node->next = tmp->next;
            tmp->next = new_node;
        }
        return true;
    }
}

template <typename T>
T SLinkedList<T>::ElementBack() const {
    SNode<T> *tmp = this->head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    return tmp->element;
}

template <typename T>
T SLinkedList<T>::ElementFront() const {
    return this->head->element;
}

template <typename T>
T SLinkedList<T>::ElementAt(int index) const {
    size_t size = Size();
    if (index >= size || index < 0) {
        return INT_MIN;
    }
    else {
        if (index == 0) {
            return ElementFront();
        }
        else if (index == size - 1) {
            return ElementBack();
        }
        else  {
            SNode<T> *tmp = this->head;
            for (int i = 0; i < index; ++i) {
                tmp = tmp->next;
            }
            return tmp->element; 
        }
    }
}

template <typename T>
bool SLinkedList<T>::RemoveBack() {
    SNode<T> *tmp = this->head;
    while (tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    delete tmp->next;
    tmp->next = NULL;
    return true;
}

template <typename T>
bool SLinkedList<T>::RemoveFront() {
    SNode<T> *tmp = this->head->next;
    delete head;
    head = tmp;
    return true;
}

template <typename T>
bool SLinkedList<T>::RemoveAt(int index) {
    size_t size = Size();
    if (index >= size || index < 0) {
        return false;
    }
    else {
        if (index == 0) {
            RemoveFront();
        }
        else if (index == size - 1) {
            RemoveBack();
        }
        else {
            SNode<T> *tmp1 = this->head, *tmp2;
            for (int i = 0; i < index; ++i) {
                tmp2 = tmp1;
                tmp1 = tmp1->next;
            }
            tmp2->next = tmp1->next;
            delete tmp1;
        }
        return true;
    }
}

template <typename T>
size_t SLinkedList<T>::Size() const {
    SNode<T> *tmp = this->head;
    size_t size = 0;
    while (tmp != NULL) {
        tmp = tmp->next;
        ++size;
    }
    return size;
}

#endif // S_LINKED_LIST_H
