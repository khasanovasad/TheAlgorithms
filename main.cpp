#include <stdio.h>
#include <string.h>

#include "SLinkedList.h"

int main() {
    // Testing out SLinkedList
    /*do {
        SLinkedList<int> *list = new SLinkedList<int>(7, 7, 7, 7, 7, 7, 7, 7);
        list->PrintList();
        for (int i = 0; i < 10; ++i)
            list->InsertBack(i);
        list->PrintList();
        for (int i = 9; i > -1; --i)
            list->InsertFront(i);
        list->PrintList();
        delete list;
    } while (true);*/
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

    // printf("Hello, World!\n");
    return 0;
}
