#include <iostream>
#include <string>

#include "SLinkedList.h"
#include "DLinkedList.h"

int main(int args, char *argv[]) {
    DLinkedList<std::string> d_list1 = { "zero", "one", "two", "three", "four" };
    DLinkedList<std::string> d_list2 = d_list1;
    for (int i = 0; i < d_list2.Count(); ++i) {
        std::cout << d_list2.ElementAt(i) << " ";
    }
    std::cout << std::endl;
    return 0;
}
