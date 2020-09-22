#include <cstdio>
#include <string>
#include <iostream>

#include "SLinkedList.h"

void Print(const SLinkedList<int> *slist) {
   for (int i = 0; i < slist->Size(); ++i)
      printf("%d ", slist->ElementAt(i)); 
   printf("\n");
} 

int main() {
    // Testing out SLinkedList
    do {
        SLinkedList<int> *list = new SLinkedList<int>();
        Print(list);
        for (int i = 0; i < 10; ++i)
            list->InsertBack(i);
        Print(list);
        for (int i = 9; i > -1; --i)
            list->InsertFront(i);
        Print(list);
        delete list;
    } while (true);
    /*
    do {
        SLinkedList<int> *list = new SLinkedList<int>(1, 0);
        list->InsertBack(1);
        list->InsertBack(2);
        list->InsertBack(3);
        list->InsertBack(4);
        list->InsertBack(5);
        printf("%d\n", list->ElementAt(4));
        delete list;
    } while (false);
    */
    /*
    do {
        SLinkedList<std::string> *slist = new SLinkedList<std::string>();
        slist->InsertBack("0");
        slist->InsertBack("1");
        slist->InsertBack("2");
        slist->InsertBack("3");
        slist->InsertBack("4");
        slist->InsertBack("5");
        std::cout << slist->ElementAt(6) << std::endl;
        delete slist;
    } while (false);
    */

    // printf("Hello, World!\n");
    return 0;
}
