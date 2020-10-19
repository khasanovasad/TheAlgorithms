/**
 * @file    Vector.h
 * @author  Asadbek Khasanov 
 * @date    October 19, 2020
 * @brief   File containing the implementation of generic Vector
 *          data structure.
 **/

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>

namespace DSCpp {
    /**
     * Templated class as an interface to Vector.
     **/
    template <typename T>
    class Vector {
        private:
            // keeps track of the number of elemnts
            size_t size = 0;

            // pointer to the actual data
            T *ptr = nullptr;


        public:
            Vector();

            Vector(int initSize);

            Vector(int initSize, const T& defElem);

            Vector(const Vector<T>& vector);

            ~Vector();


            void PushBack(const T &element);


            T PopBack();


            T& Back() const;


            T& Front() const;


            T& At(int index) const;


            void Insert(int index, const T &element);


            void Clear();


            void Erase(int index);


            void Erase(int from, int upto);


            void Resize(int size);


            [[nodiscard]] size_t Size() const;


            [[nodiscard]] bool IsEmpty() const;
    };

    template <typename T>
    Vector<T>::Vector() {
    }

    template <typename T>
    Vector<T>::Vector(int initSize) {
        Resize(initSize);
    }

    template <typename T>
    Vector<T>::Vector(int initSize, const T &defElem) {
        Resize(initSize);
        for (int i = 0; i < Size(); ++i) {
            At(i) = defElem;
        }
    }

    template <typename T>
    Vector<T>::Vector(const Vector<T>& vector) {
        Resize(vector->Count());
        for (int i = 0; i < vector.Count(); ++i) {
            At(i) = vector.At(i);
        }
    }

    template <typename T>
    Vector<T>::~Vector() {
        delete[] ptr;
        ptr = nullptr;
        size = 0;
    }

    template <typename T>
    void Vector<T>::PushBack(const T &element) {
        Resize(size + 1);
        At(size - 1) = element;
    }

    template <typename T>
    T Vector<T>::PopBack() {
        if (size != 0) {
            T tmp = At(size - 1);
            Resize(size - 1);
            return tmp;
        } else {
            throw std::underflow_error("Popping from empty vector!");
        }
    }

    template <typename T>
    T& Vector<T>::Back() const {
        if (size != 0) 
            return At(size - 1);
        else
            throw std::out_of_range("Attemt to access element of empty Vector!");
    }

    template <typename T>
    T& Vector<T>::Front() const {
        if (size != 0)
            return At(0);
        else
            throw std::out_of_range("Attemt to access element of empty Vector!");
    }

    template <typename T>
    T& Vector<T>::At(int index) const {
        if (index >= 0 && index < size)
            return ptr[index];
        else if (size == 0)
            throw std::out_of_range("Attemt to access element of empty Vector!");
        else
            throw std::out_of_range("Invalid index!");
    }

    template <typename T>
    void Vector<T>::Insert(int index, const T &element) {
        if (index < size && index >= 0)
            At(index) = element;
    }

    template <typename T>
    void Vector<T>::Clear() {
        delete[] ptr;
        ptr = nullptr;
        size = 0;
    }

    template <typename T>
    void Vector<T>::Erase(int index) {
        if (index < size && index >= 0) {
            T *tmpPtr = new T[size - 1];
            for (int i = 0; i < size; ++i) {
                if (i < index)
                    tmpPtr[i] = this->ptr[i];
                else if (i > index)
                    tmpPtr[i - 1] = this->ptr[i]; 
                else
                    continue;
            }
            delete[] this->ptr;
            this->ptr = tmpPtr;
            size = size - 1;
        }
    }

    template <typename T>
    void Vector<T>::Erase(int from, int upto) {
        if (from >= 0 && upto <= this->size && from < upto) {
            int newSize = this->size - (upto - from);
            T *tmpPtr = new T[newSize];
            for (int i = 0; i < this->size; ++i) {
                if (i < from)
                    tmpPtr[i] = this->ptr[i];
                else if (i >= from && i < upto)
                    continue;
                else if (i >= upto)
                    tmpPtr[i - (this->size - newSize)] = this->ptr[i]; 
            }
            delete[] this->ptr;
            this->ptr = tmpPtr;
            this->size = newSize; 
        }
    }

    template <typename T>
    void Vector<T>::Resize(int newSize) {
        if (newSize != this->size) {
            T *tmpPtr = new T[newSize];
            if (newSize > size) // Grow
                for (int i = 0; i < this->size; ++i)
                    tmpPtr[i] = this->ptr[i];
            else if (newSize < size) // Shrink
                for (int i = 0; i < newSize; ++i)
                    tmpPtr[i] = this->ptr[i];
            delete[] this->ptr;
            this->ptr = tmpPtr;
            this->size = newSize;
        }
    }

    template <typename T>
    [[nodiscard]] size_t Vector<T>::Size() const {
        return size;
    }

    template <typename T>
    [[nodiscard]] bool Vector<T>::IsEmpty() const {
        return ptr == nullptr;
    }
}

#endif // VECTOR_H