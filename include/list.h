/**
 * @file    List.h
 * @author  Asadbek Khasanov
 * @date    September 24, 2020
 * @brief   File containing the implementation of generic 
 *          Doubly Linked List data structure.
 **/

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>
#include <initializer_list>

namespace ds {
    template <typename T>
    class List {
    private:
        template <typename U>
        struct Node {
            U element;
            Node<U> *next = nullptr;
            Node<U> *prev = nullptr;
        };

    public:
        class Iterator {
        public:
            T& operator*();

            bool operator==(const Iterator& it) const;
            bool operator!=(const Iterator& it) const;

            // pre increment & decrement
            Iterator& operator++();
            Iterator& operator--();
            // post increment & decrement
            Iterator operator++(int);
            Iterator operator--(int);

            template <typename U>
            friend class List;
        private:
            /**
             * Private constructor to initialize an iterator with
             * with the given node as parameter. Only accessed by
             * List class that is defined as friend.
             * @param u pointer to the Node object.
             */
            Iterator(Node<T> *node);

            Node<T> *v_;
        };

        /**
         * Overloaded constructor that serves as a default constructor.
         */
        List();

        /**
         * Overloaded constructor that takes arbitrary number of arguments to
         * populate the list
         * @param i_list std::initializer_list to populate from
         */
        List(std::initializer_list<T> i_list);

        /**
         * Overloaded constructor that is used to initialize the list by copying the
         * elements of another list passed as a parameter.
         * @param d_list pre-existing list to copy from
         */
        List(const List &list);

        /**
         * Destructor to free the memory.
         */
        ~List();

        /**
         * Function used to determine whether the list is empty or not.
         * @return true if there is no element in the list
         *         false otherwise
         */
        [[nodiscard]] bool IsEmpty() const;

        /**
         * Inserts a new element at the beginning of the list.
         * @param element value of the new element
         */
        void InsertFront(T element);

        /**
         * Inserts a new element at the end of the list.
         * @param element value of the new element
         */
        void InsertBack(T element);

        /**
         * Inserts a new element at the specified position of the list.
         * @param element value of the new element
         * @param index position of the new node
         */
        void InsertAt(T element, const Iterator& it);

        /**
         * Function to get the value of the first element in the list.
         * Throws an exception if the list is empty.
         * @return reference value the first element in the list
         */
        T& ElementFront() const;

        /**
         * Function to get the value of the last element in the list.
         * Throws an exception if the list is empty.
         * @return reference value the last element in the list
         */
        T& ElementBack() const;

        /**
         * Function to get the value of the element at specified position
         * in the list. Throws an exception if the index is out of the range or
         * the list is empty.
         * @param index position of the required element
         * @return reference value of the element at specified position
         */
        T& ElementAt(const Iterator& it) const;

        /**
         * Function to remove the first element in the list and deallocating
         * it's memory.
         */
        void RemoveFront();

        /**
         * Function to remove the last element in the list and deallocating
         * it's memory.
         */
        void RemoveBack();

        /**
         * Function to remove the element at specified index and deallocating
         * it's memory.
         * @param index index of the element to  delete
         */
        void RemoveAt(const Iterator& it);

        /**
         * Function to clear the entire list making it empty. It also deallocates
         * the memory.
         */
        void Erase();

        /**
         * Function to count the total number of elements in the list.
         * @return size of the list
         */
        [[nodiscard]] size_t Count() const;

        /**
         * Function that returns an iterator to the end of the list.
         * @return iterator at the end of the list
         */
        Iterator begin() const;

        /**
         * Function that returns an iterator to the end of the list.
         * @return iterator at the end of the list
         */
        Iterator end() const;

    private:
        /**
         * Function that sets the head__ and the trailer_ of the list up. It's
         * basically called at the beginning of the each overloaded constructors.
         * Throws std::bad_alloc if unable to allocate memory.
         */
        void Init();

        /**
         * Function to create a node on the heap. Throws std::bad_alloc if
         * unable to allocate memory.
         * @param element value of the new node
         * @return pointer to the newly created node
         */
        Node<T> *CreateNode(T element);

        Node<T> *head_;
        Node<T> *trailer_;
    };

    template <typename T>
    List<T>::Iterator::Iterator(Node<T> *node) {
        v_ = node;
    }

    template <typename T>
    T& List<T>::Iterator::operator*() {
        return v_->element;
    }

    template <typename T>
    bool List<T>::Iterator::operator==(const Iterator& it) const {
        return v_ == it.v_;
    }

    template <typename T>
    bool List<T>::Iterator::operator!=(const Iterator& it) const {
        return v_ != it.v_;
    }

    template <typename T>
    typename List<T>::Iterator& List<T>::Iterator::operator++() {
        v_ = v_->next;
        return *this;
    }

    template <typename T>
    typename List<T>::Iterator& List<T>::Iterator::operator--() {
        v_ = v_->prev;
        return *this;
    }

    template <typename T>
    typename List<T>::Iterator List<T>::Iterator::operator++(int) {
        auto tmp = Iterator(this->v_);
        v_ = v_->next;
        return tmp;
    }

    template <typename T>
    typename List<T>::Iterator List<T>::Iterator::operator--(int) {
        auto tmp = Iterator(this->v_);
        v_ = v_->prev;
        return tmp;
    }

    template <typename T>
    typename List<T>::Iterator List<T>::begin() const {
        return Iterator(head_->next);
    }

    template <typename T>
    typename List<T>::Iterator List<T>::end() const {
        return Iterator(trailer_);
    }

    template <typename T>
    List<T>::List() {
        Init();
    }

    template <typename T>
    List<T>::List(std::initializer_list<T> i_list) {
        Init();
        for (T elem : i_list)
            InsertBack(elem);
    }

    template <typename T>
    List<T>::List(const List &list) {
        Init();
        for (auto x : list)
            InsertBack(x);
    }

    template <typename T>
    List<T>::~List() {
       Erase();
       delete head_;
       delete trailer_;
    }

    template <typename T>
    void List<T>::Init() {
        head_ = new Node<T>();
        trailer_ = new Node<T>();
        head_->next = trailer_;
        trailer_->prev = head_;
    }

    template <typename T>
    typename List<T>::template Node<T>* List<T>::CreateNode(T element) {
        auto *new_node = new Node<T>();
        new_node->element = element;
        new_node->next = nullptr;
        new_node->prev = nullptr;
        return new_node;
    }

    template <typename T>
    [[nodiscard]] bool List<T>::IsEmpty() const {
        if (head_->next == trailer_ && trailer_->prev == head_) return true;
        else return false;
    }

    template <typename T>
    void List<T>::InsertFront(T element) {
        Node<T> *new_node = CreateNode(element);
        if (IsEmpty()) {
            head_->next = new_node;
            new_node->prev = head_;
            trailer_->prev = new_node;
            new_node->next = trailer_;
        }
        else {
            new_node->prev = head_;
            new_node->next = head_->next;
            head_->next->prev = new_node;
            head_->next = new_node;
        }
    }

    template <typename T>
    void List<T>::InsertBack(T element) {
        Node<T> *new_node = CreateNode(element);
        if (IsEmpty()) {
            head_->next = new_node;
            new_node->prev = head_;
            trailer_->prev = new_node;
            new_node->next = trailer_;
        }
        else {
            new_node->next = trailer_;
            new_node->prev = trailer_->prev;
            trailer_->prev->next = new_node;
            trailer_->prev = new_node;
        }
    }

    template <typename T>
    void List<T>::InsertAt(T element, const Iterator& it) {
        if (it == begin()) {
            InsertFront(element);
        } else if (it == end()) {
            InsertBack(element);
        } else {
            Node<T> *new_node = CreateNode(element);
            it.v_->prev->next = new_node;
            new_node->prev = it.v_->prev;
            it.v_->prev = new_node;
            new_node->next = it.v_;
        }
    }

    template <typename T>
    T& List<T>::ElementFront() const {
        return head_->next->element;
    }

    template <typename T>
    T& List<T>::ElementBack() const {
        return trailer_->prev->element;
    }

    template <typename T>
    T& List<T>::ElementAt(const Iterator& it) const {
        return it.v_->element;
    }

    template <typename T>
    void List<T>::RemoveFront() {
        if (!IsEmpty()) {
            Node<T> *tmp = head_->next;
            head_->next = head_->next->next;
            delete tmp;
        } else {
        }
    }

    template <typename T>
    void List<T>::RemoveBack() {
        if (!IsEmpty()) {
            Node<T> *tmp = trailer_->prev;
            trailer_->prev = trailer_->prev->prev;
            trailer_->prev->next = trailer_;
            delete tmp;
        } else {
        }
    }

    template <typename T>
    void List<T>::RemoveAt(const Iterator& it) {
        if (it == begin()) {
            RemoveFront();
        } else if (it == end()){
            RemoveBack();
        } else {
            it.v_->prev->next = it.v_->next;
            it.v_->next->prev = it.v_->prev;
            delete it.v_;
        }
    }

    template <typename T>
    void List<T>::Erase() {
        Node<T> *tmp;
        while (head_->next != trailer_) {
            tmp = head_->next;
            head_->next = tmp->next;
            delete tmp;
        }
        trailer_->prev = head_;
    }

    template <typename T>
    [[nodiscard]] size_t List<T>::Count() const {
        size_t size = 0;
        Node<T> *tmp = head_->next;
        while (tmp != trailer_) {
            tmp = tmp->next;
            ++size;
        }
        return size;
    }
}

#endif // LIST_H