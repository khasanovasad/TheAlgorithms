#include <iostream>
#include <string>
#include <vector>

#include "list.h"

void testInitList();
void testInsertionOnEmptyList();
void testInsertAt();
void testRemoveAt();
void testPrePostIncrementDecrement();

int main(int args, char *argv[]) {
    testInsertionOnEmptyList();
    // testInsertAt();
    // testRemoveAt();
    // testPrePostIncrementDecrement();
}

void testInitList() {
    do {

    } while (0);
}

void testInsertionOnEmptyList() {
    if (true) {
        do {
            ds::List<int> mylist; 
            for (auto it = mylist.begin(); it != mylist.end(); ++it)
                mylist.InsertAt(89, it);
            for (int x : mylist)
                std::cout << x << " ";
            std::cout << std::endl;
            // output: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 
        } while (0);
    } else {
        do {
            ds::List<int> mylist; 
            mylist.InsertFront(0);
            mylist.InsertBack(1);
            for (auto it = mylist.begin(); it != mylist.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
            // output: 0 1 
        } while (0);
    }
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
    } while (0);
} 

void testPrePostIncrementDecrement() {
    do {
        ds::List<int> mylist;
        for (int i = 0; i < 15; ++i)
            mylist.InsertBack(i);
        for (int x : mylist)
            std::cout << x << " ";
        std::cout << std::endl;
        std::cout << *(++mylist.begin()) << std::endl;
        std::cout << *(mylist.begin()++) << std::endl;
        std::cout << *(--mylist.end()) << std::endl;
        std::cout << *(mylist.end()--) << std::endl;
        // output: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
        //         0 \n 1 \n 14 \n 13
    } while (0);
}