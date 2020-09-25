#include <string>
#include <iostream>

#include "SLinkedList.h"
#include "DLinkedList.h"

void PrintList(DLinkedList<int> *d_list) {
    size_t size = d_list->Count();
    for (int i = 0; i < size; ++i)
        std::cout << d_list->ElementAt(i) << " ";
    std::cout << std::endl;
}

int main() {
    do {
        auto *d_list = new DLinkedList<int>();
        for (int i = 0; i < 10; ++i) {
            d_list->InsertBack(i);
        }
        PrintList(d_list);
        d_list->InsertAt(69, 4);
        PrintList(d_list);
        d_list->RemoveAt(4);
        PrintList(d_list);
        d_list->RemoveFront();
        PrintList(d_list);
        d_list->RemoveBack();
        PrintList(d_list);
        delete d_list;
    } while (true);
    return 0;
}
