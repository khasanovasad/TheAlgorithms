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
    bool IsEmpty();

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
     * @param pos position of the new node
     * @return true on success
     *         false on failure
     */
    bool InsertAt(T element, int pos);

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
     * @param pos index of the element to  delete
     * @return true on success
     *         false on failure
     */
    bool RemoveAt(int pos);

    /**
     * Function to clear the entire list making it empty. It also deallocates
     * the memory.
     */
    void Erase();

    /**
     * Function to count the total number of elements in the list.
     * @return size of the list
     */
    size_t Count();
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
   while (!IsEmpty())
       RemoveFront();
   delete head;
   delete trailer;
}

template <typename T>
DNode<T>* DLinkedList<T>::CreateNode(T element) {
    auto *new_node = new DNode<T>();
    if (new_node == nullptr)
        return nullptr;

    new_node->element = element;
    new_node->head = nullptr;
    new_node->trailer = nullptr;
    return new_node;
}

template <typename T>
bool DLinkedList<T>::IsEmpty() {
    if (head->next == trailer) return true;
    else return false;
}

template <typename T>
bool DLinkedList<T>::InsertFront(T element) {
    return false;
}

template <typename T>
bool DLinkedList<T>::InsertBack(T element) {
    return false;
}

template <typename T>
bool DLinkedList<T>::InsertAt(T element, int pos) {
    return false;
}

template <typename T>
bool DLinkedList<T>::RemoveFront() {
    return false;
}

template <typename T>
bool DLinkedList<T>::RemoveBack() {
    return false;
}

template <typename T>
bool DLinkedList<T>::RemoveAt(int pos) {
    return false;
}

template <typename T>
void DLinkedList<T>::Erase() {

}

template <typename T>
size_t DLinkedList<T>::Count() {
    return 0;
}
#endif // D_LINKED_LIST