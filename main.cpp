#include <iostream>
#include <string>

#include "SLinkedList.h"
#include "DLinkedList.h"

void PrintList(DLinkedList<int> *d_list) {
    size_t size = d_list->Count();
    for (int i = 0; i < size; ++i)
        std::cout << d_list->ElementAt(i) << " ";
    std::cout << std::endl;
}

int main() {
    /*
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
    */
    /*
    do {
        auto *s_list = new SLinkedList<std::string>({ zero, one, two, three, four });
        for (int i = 0; i < s_list->Size(); ++i)
            std::cout << s_list->ElementAt(i) << " ";
        std::cout << std::endl;
        delete s_list;
    } while (true);
    */
    do {
        auto *d_list = new DLinkedList<std::string>({"zero", "one", "two", "three", "four"});
        for (int i = 0; i < d_list->Count(); ++i)
            std::cout << d_list->ElementAt(i) << " ";
        std::cout << std::endl;
        delete d_list;
    } while (true);
    return 0;
}