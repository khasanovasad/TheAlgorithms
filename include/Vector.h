/**
 * @file    Vector.h
 * @author  Asadbek Khasanov 
 * @date    October 19, 2020
 * @brief   File containing the implementation of generic Vector
 *          data structure.
 **/

#ifndef VECTOR_H
#define VECTOR_H

#include <stdexcept>

namespace DSCpp {
    /**
     * Templated class as an interface to Vector.
     **/
    template <typename T>
    class Vector {
        private:


        public:
            Vector();

            ~Vector();
    };

    template <typename T>
    Vector<T>::Vector() {

    }

    template <typename T>
    Vector<T>::~Vector() {

    }
}

#endif // VECTOR_H