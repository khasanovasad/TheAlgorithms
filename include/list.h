/**
 * @file    list.h
 * @author  Asadbek Khasanov
 * @date    September 24, 2020
 * @brief   File containing the implementation of generic 
 *          Doubly Linked list data structure.
 */

#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>
#include <initializer_list>

namespace ds {
    template <typename T>
    class list {
    private:
        template <typename U>
        struct node {
            U element;
            node<U> *next_ = nullptr;
            node<U> *prev_ = nullptr;
        };

    public:
        class iterator {
        public:
            T& operator*();

            bool operator==(const iterator& it) const;
            bool operator!=(const iterator& it) const;

            // pre increment & decrement
            iterator& operator++();
            iterator& operator--();
            // post increment & decrement
            iterator operator++(int);
            iterator operator--(int);

            template <typename U>
            friend class list;

        private:
            explicit iterator(node<T> *node);

            node<T> *v_;
        };

        list();
        list(std::initializer_list<T> i_list);
        list(const list &list);
        ~list();

        [[nodiscard]] bool is_empty() const;
        [[nodiscard]] size_t count() const;

        void add_front(T element);
        void add_back(T element);
        void add_at(T element, const iterator& it);

        T& get_front() const;
        T& get_back() const;
        T& get_at(const iterator& it) const;

        void delete_front();
        void delete_back();
        void delete_at(const iterator& it);

        void erase();

        iterator begin() const;
        iterator end() const;

        void cbegin() const {
        }

        void cend() const {
        }

        void rbegin() const {
        }
        void rend() const {
        }

        void crbegin() const {
        }
        void crend() const {
        }

    private:
        void init();

        node<T>* create_node(const T& element);

        node<T>* head_;
        node<T>* trailer_;
    };

    template <typename T>
    list<T>::iterator::iterator(node<T> *node) {
        v_ = node;
    }

    template <typename T>
    T& list<T>::iterator::operator*() {
        return v_->element;
    }

    template <typename T>
    bool list<T>::iterator::operator==(const iterator& it) const {
        return v_ == it.v_;
    }

    template <typename T>
    bool list<T>::iterator::operator!=(const iterator& it) const {
        return v_ != it.v_;
    }

    template <typename T>
    typename list<T>::iterator& list<T>::iterator::operator++() {
        v_ = v_->next_;
        return *this;
    }

    template <typename T>
    typename list<T>::iterator& list<T>::iterator::operator--() {
        v_ = v_->prev_;
        return *this;
    }

    template <typename T>
    auto list<T>::iterator::operator++(int) -> typename list<T>::iterator {
        auto tmp = iterator(this->v_);
        v_ = v_->next_;
        return tmp;
    }

    template <typename T>
    auto list<T>::iterator::operator--(int) -> typename list<T>::iterator {
        auto tmp = iterator(this->v_);
        v_ = v_->prev_;
        return tmp;
    }

    template <typename T>
    auto list<T>::begin() const -> typename list<T>::iterator {
        return iterator(head_->next_);
    }

    template <typename T>
    auto list<T>::end() const -> typename list<T>::iterator {
        return iterator(trailer_);
    }

    template <typename T>
    list<T>::list() {
        init();
    }

    template <typename T>
    list<T>::list(std::initializer_list<T> i_list) {
        init();
        for (T elem : i_list)
            add_back(elem);
    }

    template <typename T>
    list<T>::list(const list &list) {
        init();
        for (auto x : list)
            add_back(x);
    }

    template <typename T>
    list<T>::~list() {
        erase();
       delete head_;
       delete trailer_;
    }

    template <typename T>
    void list<T>::init() {
        head_ = new node<T>();
        trailer_ = new node<T>();
        head_->next_ = trailer_;
        head_->prev_ = nullptr;
        trailer_->prev_ = head_;
        trailer_->next_ = nullptr;
    }

    template <typename T>
    auto list<T>::create_node(const T& element) -> typename list<T>::template node<T>* {
        auto *new_node = new node<T>();
        new_node->element = element;
        new_node->next_ = nullptr;
        new_node->prev_ = nullptr;
        return new_node;
    }

    template <typename T>
    [[nodiscard]] bool list<T>::is_empty() const {
        if (head_->next_ == trailer_ && trailer_->prev_ == head_) return true;
        else return false;
    }

    template <typename T>
    void list<T>::add_front(T element) {
        node<T> *new_node = create_node(element);
        if (is_empty()) {
            head_->next_ = new_node;
            new_node->prev_ = head_;
            trailer_->prev_ = new_node;
            new_node->next_ = trailer_;
        }
        else {
            new_node->prev_ = head_;
            new_node->next_ = head_->next_;
            head_->next_->prev_ = new_node;
            head_->next_ = new_node;
        }
    }

    template <typename T>
    void list<T>::add_back(T element) {
        node<T> *new_node = create_node(element);
        if (is_empty()) {
            head_->next_ = new_node;
            new_node->prev_ = head_;
            trailer_->prev_ = new_node;
            new_node->next_ = trailer_;
        }
        else {
            new_node->next_ = trailer_;
            new_node->prev_ = trailer_->prev_;
            trailer_->prev_->next_ = new_node;
            trailer_->prev_ = new_node;
        }
    }

    template <typename T>
    void list<T>::add_at(T element, const iterator& it) {
        if (it == begin()) {
            add_front(element);
        } else if (it == end()) {
            add_back(element);
        } else {
            node<T> *new_node = create_node(element);
            it.v_->prev_->next_ = new_node;
            new_node->prev_ = it.v_->prev_;
            it.v_->prev_ = new_node;
            new_node->next_ = it.v_;
        }
    }

    template <typename T>
    T& list<T>::get_front() const {
        return head_->next_->element;
    }

    template <typename T>
    T& list<T>::get_back() const {
        return trailer_->prev_->element;
    }

    template <typename T>
    T& list<T>::get_at(const iterator& it) const {
        return it.v_->element;
    }

    template <typename T>
    void list<T>::delete_front() {
        if (!is_empty()) {
            node<T> *tmp = head_->next_;
            head_->next_ = head_->next_->next_;
            delete tmp;
        } else {
        }
    }

    template <typename T>
    void list<T>::delete_back() {
        if (!is_empty()) {
            node<T> *tmp = trailer_->prev_;
            trailer_->prev_ = trailer_->prev_->prev_;
            trailer_->prev_->next_ = trailer_;
            delete tmp;
        } else {
        }
    }

    template <typename T>
    void list<T>::delete_at(const iterator& it) {
        if (it == begin()) {
            delete_front();
        } else if (it == end()){
            delete_back();
        } else {
            it.v_->prev_->next_ = it.v_->next_;
            it.v_->next_->prev_ = it.v_->prev_;
            delete it.v_;
        }
    }

    template <typename T>
    void list<T>::erase() {
        node<T> *tmp;
        while (head_->next_ != trailer_) {
            tmp = head_->next_;
            head_->next_ = tmp->next_;
            delete tmp;
        }
        trailer_->prev_ = head_;
    }

    template <typename T>
    [[nodiscard]] size_t list<T>::count() const {
        size_t size = 0;
        node<T> *tmp = head_->next_;
        while (tmp != trailer_) {
            tmp = tmp->next_;
            ++size;
        }
        return size;
    }
}

#endif // LIST_H
