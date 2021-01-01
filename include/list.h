#ifndef DSA_LIST_H
#define DSA_LIST_H

#include <initializer_list>
#include <cassert>

namespace dsa {

    template <typename T>
    class node {

    public:
        node() = default;

        node(const T& element_) {
            this->element_ = element_;
            this->next_ = nullptr;
            this->prev_ = nullptr;
        }

        T element_;
        node<T>* next_ = nullptr;
        node<T>* prev_ = nullptr;
    };

    template <typename T>
    class iterator {

    public:
        T& operator*() {
            return v_->element_;
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
            init_head_tail();
        }

        list(std::initializer_list<T> i_list) {
            init_head_tail();
            for (T elem : i_list) {
                add_back(elem);
            }
        }

        list(const list &list) {
            init_head_tail();
            for (auto x : list) {
                add_back(x);
            }
        }

        ~list() {
            erase();
            delete head_;
            delete tail_;
        }

        [[nodiscard]] bool is_empty() const {
            if (head_->next_ == tail_ && tail_->prev_ == head_) {
                return true;
            } else {
                return false;
            }
        }

        [[nodiscard]] std::size_t count() const {
            std::size_t size = 0;
            node<T> *tmp = head_->next_;
            while (tmp != tail_) {
                tmp = tmp->next_;
                ++size;
            }
            return size;
        }

        void add_front(const T& to_be_added) {
            add_at(to_be_added, begin());
        }

        void add_back(const T& to_be_added) {
            add_at(to_be_added, end());
        }

        void add_at(const T& to_be_added, const iterator<T>& it) {
            auto* new_node = new node<T>(to_be_added);
            if (!is_empty()) {
                it.v_->prev_->next_ = new_node;
                new_node->prev_ = it.v_->prev_;
                it.v_->prev_ = new_node;
                new_node->next_ = it.v_;
            } else  {
                head_->next_ = new_node;
                new_node->prev_ = head_;
                tail_->prev_ = new_node;
                new_node->next_ = tail_;
            }
        }

        T& get_front() const {
            return head_->next_->element_;
        }

        T& get_back() const {
            return tail_->prev_->element_;
        }

        T& get_at(const iterator<T>& it) const {
            return it.v_->element_;
        }

        T delete_front() {
            return delete_at(begin());
        }

        T delete_back() {
            return delete_at(--end());
        }

        T delete_at(const iterator<T>& it) {
            assert(!is_empty());
            assert(it != end());

            it.v_->prev_->next_ = it.v_->next_;
            it.v_->next_->prev_ = it.v_->prev_;

            T deleted = it.v_->element_;
            delete it.v_;

            return deleted;
        }

        void erase() {
            node<T> *tmp;
            while (head_->next_ != tail_) {
                tmp = head_->next_;
                head_->next_ = tmp->next_;
                delete tmp;
            }
            tail_->prev_ = head_;
        }

        iterator<T> begin() const {
            return iterator<T>(head_->next_);
        }

        iterator<T> end() const {
            return iterator<T>(tail_);
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
        void init_head_tail() {
            head_ = new node<T>();
            tail_ = new node<T>();
            head_->next_ = tail_;
            head_->prev_ = nullptr;
            tail_->prev_ = head_;
            tail_->next_ = nullptr;
        }

        node<T>* head_;
        node<T>* tail_;
    };
}

#endif // DSA_LIST_H
