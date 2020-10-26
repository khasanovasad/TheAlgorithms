#include <iostream>
#include <string>
#include <vector>

#include "list.h"

void testInsertAt();
void testRemoveAt();

int main(int args, char *argv[]) {
    // testInsertAt();
    testRemoveAt();
}

void testInsertAt() {
    do {
        ds::List<int> mylist;
        for (int i = 0; i < 15; ++i)
            mylist.InsertBack(i);
        mylist.InsertAt(89, ++++++++++mylist.begin());
        mylist.InsertAt(89, mylist.begin());
        mylist.InsertAt(89, mylist.end());
        for (int x : mylist)
            std::cout << x << " ";
        std::cout << std::endl;
        // output: 89 1 2 3 4 89 5 6 7 8 9 10 11 12 13 14 89
    } while (0);
}

void testRemoveAt() {
    do {
        ds::List<int> mylist;
        for (int i = 0; i < 15; ++i)
            mylist.InsertBack(i);
        mylist.RemoveAt(++++mylist.begin());    
        mylist.RemoveAt(mylist.begin());    
        mylist.RemoveAt(mylist.end());    
        for (int x : mylist)
            std::cout << x << " ";
        std::cout << std::endl;
        // output: 1 3 4 5 6 7 8 9 10 11 12 13
    } while (1);
} 