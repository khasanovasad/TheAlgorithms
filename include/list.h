#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>
#include <initializer_list>

namespace ds {
    template <typename T>
    struct node {
        T element;
        node<T>* next_ = nullptr;
        node<T>* prev_ = nullptr;
    };

    template <typename T>
    class iterator {
    public:
        T& operator*() {
            return v_->element;
        }

        bool operator==(const iterator& it) const {
            return v_ == it.v_;
        }

        bool operator!=(const iterator& it) const {
            return v_ != it.v_;
        }

        // pre increment
        iterator& operator++() {
            v_ = v_->next_;
            return *this;
        }

        // pre decrement
        iterator& operator--() {
            v_ = v_->prev_;
            return *this;
        }

        // post increment
        iterator operator++(int) {
            auto tmp = iterator(this->v_);
            v_ = v_->next_;
            return tmp;
        }

        // post decrement
        iterator operator--(int) {
            auto tmp = iterator(this->v_);
            v_ = v_->prev_;
            return tmp;
        }

        template <typename TU>
        friend class list;

    private:
        explicit iterator(node<T> *node) {
            v_ = node;
        }

        node<T> *v_;
    };

    template <typename T>
    class list {
    public:
        list() {
            init();
        }

        list(std::initializer_list<T> i_list) {
            init();
            for (T elem : i_list) {
                add_back(elem);
            }
        }

        list(const list &list) {
            init();
            for (auto x : list) {
                add_back(x);
            }
        }

        ~list() {
            erase();
            delete head_;
            delete trailer_;
        }

        [[nodiscard]] bool is_empty() const {
            if (head_->next_ == trailer_ && trailer_->prev_ == head_) {
                return true;
            } else {
                return false;
            }
        }

        [[nodiscard]] size_t count() const {
            size_t size = 0;
            node<T> *tmp = head_->next_;
            while (tmp != trailer_) {
                tmp = tmp->next_;
                ++size;
            }
            return size;
        }

        void add_front(T element) {
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

        void add_back(T element) {
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

        void add_at(T element, const iterator<T>& it) {
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

        T& get_front() const {
            return head_->next_->element;
        }

        T& get_back() const {
            return trailer_->prev_->element;
        }

        T& get_at(const iterator<T>& it) const {
            return it.v_->element;
        }

        void delete_front() {
            if (!is_empty()) {
                node<T> *tmp = head_->next_;
                head_->next_ = head_->next_->next_;
                delete tmp;
            } else {
            }
        }

        void delete_back() {
            if (!is_empty()) {
                node<T> *tmp = trailer_->prev_;
                trailer_->prev_ = trailer_->prev_->prev_;
                trailer_->prev_->next_ = trailer_;
                delete tmp;
            } else {
            }
        }

        void delete_at(const iterator<T>& it) {
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

        void erase() {
            node<T> *tmp;
            while (head_->next_ != trailer_) {
                tmp = head_->next_;
                head_->next_ = tmp->next_;
                delete tmp;
            }
            trailer_->prev_ = head_;
        }

        iterator<T> begin() const {
            return iterator<T>(head_->next_);
        }

        iterator<T> end() const {
            return iterator<T>(trailer_);
        }

        /* NEED TO IMPLEMENT */
        void cbegin() const;
        void cend() const;

        void rbegin() const;
        void rend() const;

        void crbegin() const;
        void crend() const;
        /* NEED TO IMPLEMENT */

    private:
        void init() {
            head_ = new node<T>();
            trailer_ = new node<T>();
            head_->next_ = trailer_;
            head_->prev_ = nullptr;
            trailer_->prev_ = head_;
            trailer_->next_ = nullptr;
        }

        node<T>* create_node(const T& element) {
            auto *new_node = new node<T>();
            new_node->element = element;
            new_node->next_ = nullptr;
            new_node->prev_ = nullptr;
            return new_node;
        }

        node<T>* head_;
        node<T>* trailer_;
    };
}

#endif // LIST_H
