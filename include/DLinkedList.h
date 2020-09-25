/**
 * @file    DLinkedList.h
 * @author  Asadbek Khasanov
 * @date    September 24, 2020
 * @brief   File containing the implementation of generic Doubly Linked List
 *          data structure.
 **/

#ifndef D_LINKED_LIST
#define D_LINKED_LIST

#include <cstdarg>
#include <stdexcept>

template <typename T>
struct DNode {
private:
    T element;
    DNode<T> *next;
    DNode<T> *prev;

    template <typename U>
    friend class DLinkedList;
};

template <typename T>
class DLinkedList {
private:
    DNode<T> *head;
    DNode<T> *trailer;

    /**
     * Function to create a node on the heap.
     * @param element value of the new node
     * @return pointer to the newly created node
     */
    DNode<T> *CreateNode(T element);

public:
    /**
     * Overloaded constructor that serves as a default constructor.
     */
    DLinkedList();

    /**
     * Overloaded constructor that takes arbitrary number of elements to
     * initialize the list with. The first argument should be the number of
     * arguments coming after arg_count.
     * @param arg_count number of argument that is being passed after arg_count
     * @param ... arg_count number of elements to initialize the list
     */
    explicit DLinkedList(int arg_count, ...);

    /**
     * Overloaded constructor that is used to initialize the list by copying the
     * elements of another list passed as a parameter.
     * @param d_list pre-existing list to copy from
     */
    DLinkedList(const DLinkedList *d_list);

    /**
     * Destructor to free the memory.
     */
    ~DLinkedList();

    /**
     * Function used to determine whether the list is empty or not.
     * @return true if there is no element in the list
     *         false otherwise
     */
    bool IsEmpty() const;

    /**
     * Inserts a new element at the beginning of the list.
     * @param element value of the new element
     * @return true on success
     *         false on failure
     */
    bool InsertFront(T element);

    /**
     * Inserts a new element at the end of the list.
     * @param element value of the new element
     * @return true on success
     *         false on failure
     */
    bool InsertBack(T element);

    /**
     * Inserts a new element at the specified position of the list.
     * @param element value of the new element
     * @param index position of the new node
     * @return true on success
     *         false on failure
     */
    bool InsertAt(T element, int index);

    /**
     * Function to get the value of the first element in the list.
     * Throws an exception if the list is empty.
     * @return value the first element in the list
     */
    T ElementFront() const;

    /**
     * Function to get the value of the last element in the list.
     * Throws an exception if the list is empty.
     * @return value the last element in the list
     */
    T ElementBack() const;

    /**
     * Function to get the value of the element at specified position
     * in the list. Throws an exception if the index is out of the range or
     * the list is empty.
     * @param index position of the required element
     * @return value of the element at specified position
     */
    T ElementAt(int index) const;

    /**
     * Function to remove the first element in the list and deallocating
     * it's memory.
     * @return true on success
     *         false on failure
     */
    bool RemoveFront();

    /**
     * Function to remove the last element in the list and deallocating
     * it's memory.
     * @return true on success
     *         false on failure
     */
    bool RemoveBack();

    /**
     * Function to remove the element at specified index and deallocating
     * it's memory.
     * @param index index of the element to  delete
     * @return true on success
     *         false on failure
     */
    bool RemoveAt(int index);

    /**
     * Function to clear the entire list making it empty. It also deallocates
     * the memory.
     */
    void Erase();

    /**
     * Function to count the total number of elements in the list.
     * @return size of the list
     */
    size_t Count() const;
};

template <typename T>
DLinkedList<T>::DLinkedList() {
   head = new DNode<T>();
   trailer = new DNode<T>();
   head->next = trailer;
   trailer->prev = head;
}

template <typename T>
DLinkedList<T>::DLinkedList(int arg_count, ...) {

}

template <typename T>
DLinkedList<T>::DLinkedList(const DLinkedList *d_list) {
    for (int i = 0; i < d_list->Size(); ++i)
        InsertBack(d_list->ElementBack(i));
}

template <typename T>
DLinkedList<T>::~DLinkedList() {
   Erase();
   delete head;
   delete trailer;
}

template <typename T>
DNode<T>* DLinkedList<T>::CreateNode(T element) {
    auto *new_node = new DNode<T>();
    if (new_node == nullptr)
        return nullptr;

    new_node->element = element;
    new_node->next = nullptr;
    new_node->prev = nullptr;
    return new_node;
}

template <typename T>
bool DLinkedList<T>::IsEmpty() const {
    if (head->next == trailer && trailer->prev == head) return true;
    else return false;
}

template <typename T>
bool DLinkedList<T>::InsertFront(T element) {
    DNode<T> *new_node = CreateNode(element);
    if (new_node != nullptr) { // mem allocation was successful
        if (IsEmpty()) {
            head->next = new_node;
            new_node->prev = head;
            trailer->prev = new_node;
            new_node->next = trailer;
        }
        else {
            new_node->prev = head;
            new_node->next = head->next;
            head->next->prev = new_node;
            head->next = new_node;
        }
        return true;
    }
    return false;
}

template <typename T>
bool DLinkedList<T>::InsertBack(T element) {
    DNode<T> *new_node = CreateNode(element);
    if (new_node != nullptr) { // mem allocation was successful
        if (IsEmpty()) {
            head->next = new_node;
            new_node->prev = head;
            trailer->prev = new_node;
            new_node->next = trailer;
        }
        else {
            new_node->next = trailer;
            new_node->prev = trailer->prev;
            trailer->prev->next = new_node;
            trailer->prev = new_node;
        }
        return true;
    }
    return false;
}

template <typename T>
bool DLinkedList<T>::InsertAt(T element, int index) {
    size_t size = Count();
    if (index >= size || index < 0) {
        throw std::out_of_range("Index Out Of Range");
    }
    else {
        if (index == 0)
            return InsertFront(element);
        else if (index == size - 1)
            return InsertBack(element);
        else {
            DNode<T> *new_node = CreateNode(element);
            if (new_node != nullptr) {
                DNode<T> *tmp = head->next;
                for (int i = 0; i < index; ++i) {
                    tmp = tmp->next;
                }
                new_node->next = tmp;
                new_node->prev = tmp->prev;
                tmp->prev->next = new_node;
                tmp->prev = new_node;
            }
        }
    }
}

template <typename T>
T DLinkedList<T>::ElementFront() const {
    return head->next->element;
}

template <typename T>
T DLinkedList<T>::ElementBack() const {
    return trailer->prev->element;
}

template <typename T>
T DLinkedList<T>::ElementAt(int index) const {
    size_t size = Count();
    if (index >= size || index < 0) {
        throw std::out_of_range("Index Out Of Range");
    }
    else {
        if (index == 0)
            return ElementFront();
        else if (index == size - 1)
            return ElementBack();
        else {
            DNode<T> *tmp = head->next;
            for (int i = 0; i < index; ++i) {
                tmp = tmp->next;
            }
            return tmp->element;
        }
    }
}

template <typename T>
bool DLinkedList<T>::RemoveFront() {
    if (!IsEmpty()) {
        DNode<T> *tmp = head->next;
        head->next = head->next->next;
        delete tmp;
        return true;
    }
    else
        return false;
}

template <typename T>
bool DLinkedList<T>::RemoveBack() {
    if (!IsEmpty()) {
        DNode<T> *tmp = trailer->prev;
        trailer->prev = trailer->prev->prev;
        trailer->prev->next = trailer;
        delete tmp;
        return true;
    }
    else
        return false;
}

template <typename T>
bool DLinkedList<T>::RemoveAt(int index) {
    size_t size = Count();
    if (index >= size || index < 0) {
        throw std::out_of_range("Index Out Of Range");
    }
    else {
        if (index == 0)
            return RemoveFront();
        else if (index == size - 1)
            return RemoveBack();
        else {
            DNode<T> *tmp = head->next;
            for (int i = 0; i < index; ++i) {
                tmp = tmp->next;
            }
            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;
            delete tmp;
            return true;
        }
    }
}

template <typename T>
void DLinkedList<T>::Erase() {
    DNode<T> *tmp;
    while (head->next != trailer) {
        tmp = head->next;
        head->next = tmp->next;
        delete tmp;
    }
    trailer->prev = head;
}

template <typename T>
size_t DLinkedList<T>::Count() const {
    size_t size = 0;
    DNode<T> *tmp = head->next;
    while (tmp != trailer) {
        tmp = tmp->next;
        ++size;
    }
    return size;
}

#endif // D_LINKED_LIST