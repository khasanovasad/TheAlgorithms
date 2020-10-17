/**
 * @file    SLinkedList.h
 * @author  Asadbek Khasanov
 * @date    September 22, 2020
 * @brief   File containing the implementation of generic Singly Linked List
 *          data structure.
 **/

#ifndef S_LINKED_LIST_H
#define S_LINKED_LIST_H

#include <stdexcept>
#include <initializer_list>

namespace DSCpp {
    /**
     * Structure to represent a node in the list. All member variables are private.
     * Only SLinkedList class has access to them through friendship.
     **/
    template <typename T>
    struct SNode {
        private:
            T element;
            SNode<T> *next;

            template <typename U>
            friend class SLinkedList;
    };

    /**
     * Templated class to work as a singly linked list.
     **/
    template <typename T>
    class SLinkedList {
        private:
            /* Pointer to the first element in the list  */
            SNode<T> *head;      

            /**
             * Function to create a new node by allocating memory on the heap.
             * Throws std::bad_alloc if unable to allocate memory.
             * @param element generic variable as a value of the node
             * @return pointer to the newly created node if mem. alloc. was
             * successful, otherwise NULL
             **/
            SNode<T>* CreateNode(T element);
        public:
            /**
             * Overloaded constructor that takes arbitrary number of arguments and
             * initializes the list with them.
             * @param i_list std::initializer_list to populate from
             **/
            SLinkedList(std::initializer_list<T> i_list);

            /**
             * Overloaded copy constructor.
             * @param s_list constant pointer to SLinkedList object to copy from
             **/
            SLinkedList(const SLinkedList &s_list);

            /**
             * Overloaded constructor that serves as default.
             **/
            SLinkedList();

            /**
             * Destructor to free the memory.
             **/
            ~SLinkedList();

            /**
             * Function that adds an element to the end of the list.
             * @param element element to be added.
             * @return ture on success
             *         false on failure
             **/
            void InsertBack(T element);

            /**
             * Function that adds an element to the beginning of the list.
             * @param element element to be added
             **/
            void InsertFront(T element);

            /**
             * Function that adds an element at the given position. 
             * @param element element to be added
             * @param index index the position of the new element
             **/
            void InsertAt(T element, int index);

            /**
             * Function that returns the last element in the list.
             * @return reference of queried element
             **/
            T& ElementBack() const;

            /**
             * Function that returns the first element in the list.
             * @return reference of queried element
             **/
            T& ElementFront() const;

            /**
             * Function that returns the element at the specific position from the
             * list.
             * @param index position of the desired element
             * @return reference of queried element
             **/
            T& ElementAt(int index) const;

            /**
             * Function that removes the last element in the list and frees it's
             * memory.
             * @return true on success
             *         false on failure
             **/
            bool RemoveBack();

            /**
             * Function that removes the first element in the list and frees it's
             * memory.
             * @return true on success
             *         false on failure
             **/
            bool RemoveFront();

            /**
             * Function that removes an element at the specified position and frees
             * it's memory.
             * @param index position of the about to be deleted element
             * @return true on success
             *         false on failure
             **/
            bool RemoveAt(int index);

            /**
             * Function that deletes all the elements of the list making it empty.
             * @return true on success
             *         false on failure
             **/
            void Erase();
            
            /**
             * Function that gives the number of elements in the list.
             * @return number of elements in the list
             **/
            [[nodiscard]] size_t Count() const;
    };

    template <typename T>
    SLinkedList<T>::SLinkedList(std::initializer_list<T> i_list) {
        this->head = nullptr;
        for (T elem : i_list) {
            InsertBack(elem);
        }
    }

    template <typename T>
    SLinkedList<T>::SLinkedList(const SLinkedList &s_list) {
        this->head= nullptr;
        for (int i = 0; i < s_list->Count(); ++i) {
            InsertBack(s_list->ElementAt(i));
        }
    }

    template <typename T>
    SLinkedList<T>::SLinkedList() {
        this->head = nullptr;
    }

    template <typename T>
    SLinkedList<T>::~SLinkedList() {
        Erase();
    }

    template <typename T>
    SNode<T>* SLinkedList<T>::CreateNode(T element) {
        auto *new_node = new SNode<T>();
        new_node->element = element;
        new_node->next = nullptr;
        return new_node;
    }

    template <typename T>
    void SLinkedList<T>::InsertBack(T element) {
        SNode<T> *new_node = CreateNode(element);
        if (this->head == nullptr) {
            this->head = new_node;
        }
        else {
            SNode<T> *tmp = this->head;
            while (tmp->next != nullptr) {
                tmp = tmp->next;
            }
            tmp->next = new_node;
        }
    }

    template <typename T>
    void SLinkedList<T>::InsertFront(T element) {
        SNode<T> *new_node = CreateNode(element);
        if (this->head == NULL) {
            this->head = new_node;
        }
        else {
            new_node->next = this->head;
            this->head = new_node;
        }
    }

    template <typename T>
    void SLinkedList<T>::InsertAt(T element, int index) {
        SNode<T> *new_node = CreateNode(element);
        size_t size = Count();
        if (new_node == NULL || index > size) {
            throw std::out_of_range("Index Out Of Range");
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
        }
    }

    template <typename T>
    T& SLinkedList<T>::ElementBack() const {
        SNode<T> *tmp = this->head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        return tmp->element;
    }

    template <typename T>
    T& SLinkedList<T>::ElementFront() const {
        return this->head->element;
    }

    template <typename T>
    T& SLinkedList<T>::ElementAt(int index) const {
        size_t size = Count();
        if (index >= size || index < 0) {
            throw std::out_of_range("Index Out Of Range");
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
        while (tmp->next->next != nullptr) {
            tmp = tmp->next;
        }
        delete tmp->next;
        tmp->next = nullptr;
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
        size_t size = Count();
        if (index >= size || index < 0) {
            throw std::out_of_range("Index Out Of Range");
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
    void SLinkedList<T>::Erase() {
        SNode<T> *tmp;
        while (this->head != NULL) {
            tmp = this->head;
            this->head = this->head->next;
            delete tmp;
        }
    }

    template <typename T>
    size_t SLinkedList<T>::Count() const {
        if (this->head == nullptr) {
            return 0;
        }
        else {
            SNode<T> *tmp = this->head;
            size_t size = 0;
            while (tmp != nullptr) {
                tmp = tmp->next;
                ++size;
            }
            return size;
        }
    }
}
#endif // S_LINKED_LIST_H