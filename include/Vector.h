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
            /**
             * Default constructor.
             **/
            Vector() = default;

            /**
             * Overloaded constructor that reserves a certain block
             * of memory for later use.
             * @param initSize predefined, to be reserved size
             **/
            Vector(int initSize);

            /**
             * Overloaded constructor that initializes certain number
             * of elemenets with the given default value.
             * @param initSize initial size
             * @param defElem default value for elements
             **/
            Vector(int initSize, const T& defElem);

            /**
             * Overloaded copy constructor.
             * @param vector constant reference of Vector object
             * to copy from
             **/
            Vector(const Vector<T>& vector);

            /**
             * Destructor.
             **/ 
            ~Vector();

            /**
             * Function to push an element at the end of the vector.
             * @param constant referce of an element value
             **/
            void PushBack(const T &element);

            /**
             * Function to pop an element from the back of the vector.
             * Throws std::underflow_error if the vector is empty and
             * there is no element to pop.
             * @return value of the popped element
             **/ 
            T PopBack();

            /**
             * Function to get the reference of the last element in
             * the vector. Throws std::out_of_range if the vector is
             * empty and there is no element to return.
             * @return reference of the last element
             **/
            T& Back() const;

            /**
             * Function to get the reference of the first element in
             * the vector. Throws std::out_of_range if the vector is
             * empty and there is no element to return.
             * @return reference of the first element
             **/
            T& Front() const;

            /**
             * Function to get the referece of the element at specified
             * position. Throws std::out_of_range if the vector is empty
             * or given index is out of the range.
             * @param index position of the requested element
             * @return reference of the element at specified position
             **/
            T& At(int index) const;

            /**
             * Function to insert and element at specified position.
             * Throws std::out_of_range is the vector is empty or
             * given index is out of range. 
             * @param index position of the new element
             * @param newElem value of the new element
             **/
            void Insert(int index, const T &newElem);

            /**
             * Function to clear the entire vector, making it empty
             * by deallocating its memory.
             **/
            void Clear();

            /**
             * Function to erase the element at specified position.
             * Throws std::out_of_range if the index is out of the range.
             * @param index position of the element to remove.
             **/
            void Erase(int index);

            /**
             * Overloaded version of the Erase function that removes elements
             * in specifier range. Throws if the range is invalid or the vector
             * is empty.
             * @param from lower bound of the range
             * @param upto upper bound of the range (non inclusive)
             **/
            void Erase(int from, int upto);

            /**
             * Function to resize the vector. If the newSize is lesser than
             * the original, it shrinks the vector, otherwise grows.
             * @param newSize expected new size
             **/
            void Resize(int newSize);

            /**
             * Function to get the size of the vector.
             * @return number of elements in the vector
             **/
            [[nodiscard]] size_t Size() const;

            /**
             * Function to determine of the vector is empty.
             * @return true if empty
             *         false if not
             **/
            [[nodiscard]] bool IsEmpty() const;
    };

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
        if (size != 0) {
            if (index >= 0 && index < size)
                return ptr[index];
            else
                throw std::out_of_range("Invalid index!");
        } else {
            throw std::out_of_range("Attempt to access element of empty Vector!");
        }
    }

    template <typename T>
    void Vector<T>::Insert(int index, const T &newElem) {
        if (size != 0) {
            if (index >= 0 && index <= size) {
                Resize(size + 1);
                for (int i = size - 1; i > index; --i) {
                    At(i) = At(i - 1);
                }
                At(index) = newElem;
            } else {
                throw std::out_of_range("Invalid index!");
            } 
        } else {
            throw std::out_of_range("Attempt to insert to empty Vector!");
        }
    }

    template <typename T>
    void Vector<T>::Clear() {
        delete[] ptr;
        ptr = nullptr;
        size = 0;
    }

    template <typename T>
    void Vector<T>::Erase(int index) {
        if (size != 0) {
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
            } else {
                throw std::out_of_range("Invalid index!");
            }
        } else {
            throw std::out_of_range("Attempt to remove an element from empty Vector!");
        }
    }

    template <typename T>
    void Vector<T>::Erase(int from, int upto) {
        if (size != 0) {
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
            } else {
                throw std::out_of_range("Invalid range!");
            }
        } else {
            throw std::out_of_range("Attempty to remove elements from empty Vector!");
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