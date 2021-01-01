#ifndef DSA_VECTOR_H
#define DSA_VECTOR_H

#include <cassert>

namespace dsa {

    template <typename T>
    class vector {

    public:
        vector(std::size_t init_capacity) {
            if (init_capacity == 0) {
                init_capacity = 4;
            }

            data_ = new T[init_capacity];
            capacity_ = init_capacity;
            length_ = 0;
        }

        vector(std::size_t init_capacity, const T& def_value) {
            if (init_capacity == 0) {
                init_capacity = 4;
            }

            data_ = new T[init_capacity];
            capacity_ = init_capacity;
            length_ = 0;
            for (std::size_t i = 0; i < capacity(); ++i) {
                data_[i] = def_value;
            }
        }

        ~vector() {
            delete[] data_;
            data_ = nullptr;
        }

        bool is_empty() const {
            return length() == 0;
        }

        std::size_t length() const {
            return length_;
        }

        std::size_t capacity() const {
            return capacity_;
        }

        void add_back(const T& to_be_added) {
            add_at(to_be_added, length());
        }

        void add_front(const T& to_be_added) {
            add_at(to_be_added, 0);
        }

        void add_at(const T& to_be_added, std::size_t index) {
            assert(index < length() + 1);

            resize();
            for (std::size_t i = length(); i > index; --i) {
                data_[i] = data_[i - 1];
            }
            data_[index] = to_be_added;
            ++length_;
        }

        T& get_back() const {
            return get_at(length() - 1);
        }

        T& get_front() const {
            return get_at(0);
        }

        T& get_at(std::size_t index) const {
            assert(length() != 0);
            assert(index < length());
            return data_[index];
        }

        T delete_back() {
            delete_back(length() - 1);
        }

        T delete_front() {
            delete_at(0);
        }

        T delete_at(std::size_t index) {
            assert(length() != 0);
            assert(index < length());

            resize();
            for (std::size_t i = index; i < length() - 1; ++i) {
                data_[i] = data_[i + 1];
            }
            --length_;
        }

        void shrink_to_fit() {
            capacity_ = length();
            T* tmp = new T[capacity()];
            for (std::size_t i = 0; i < length(); ++i)
                tmp[i] = data_[i];
            delete[] data_;
            data_ = tmp;
        }

    private:
        T* data_ = nullptr;
        std::size_t length_;
        std::size_t capacity_;

        void resize() {
            if (length() == capacity()) {
                T* tmp = new T[capacity() + capacity() / 2];
                for (std::size_t i = 0; i < length(); ++i)
                    tmp[i] = data_[i];
                delete[] data_;
                data_ = tmp;
                capacity_ += capacity() / 2;
            }
        }
    };
}

#endif // DSA_VECTOR_H
