#include <string>
#include <iostream>

#include "SLinkedList.h"

int main() {
    // Testing out SLinkedList
    /*
    do {
        SLinkedList<int> *list = new SLinkedList<int>();
        Print(list);
        for (int i = 0; i < 10; ++i)
            list->InsertBack(i);
        Print(list);
        for (int i = 9; i > -1; --i)
            list->InsertFront(i);
        Print(list);
        list->Erase();
        Print(list);
        delete list;
    } while (false);
    */
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
    do {
        SLinkedList<std::string> *slist1 = new SLinkedList<std::string>();
        slist1->InsertBack("zero");
        slist1->InsertBack("one");
        slist1->InsertBack("two");
        slist1->InsertBack("three");
        slist1->InsertBack("four");
        slist1->InsertBack("five");
        SLinkedList<std::string> *slist2 = new SLinkedList<std::string>(slist1);
        for (int i = 0; i < slist2->Size(); ++i) {
            std::cout << slist2->ElementAt(i) << " ";
        }
        std::cout << std::endl;
        delete slist1;
        delete slist2;
    } while (true);
    return 0;
}
