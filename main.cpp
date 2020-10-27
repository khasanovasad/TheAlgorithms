#include <iostream>
#include <string>
#include <vector>

#include "List.h"

void testCopyCtor();
void testInitList();
void testInsertionOnEmptyList();
void testInsertAt();
void testRemoveAt();
void testPrePostIncrementDecrement();

int main(int args, char *argv[]) {
    testCopyCtor();
    // testInitList();
    // testInsertionOnEmptyList();
    // testInsertAt();
    // testRemoveAt();
    // testPrePostIncrementDecrement();
}

void testCopyCtor() {
    do {
        ds::List<std::string> mylist;
        for (int i = 0; i < 5; ++i)
            mylist.InsertBack("sex is good");
        ds::List<std::string> mylist2(mylist);
        for (auto x : mylist2)
            std::cout << x << std::endl;
    } while (0);
}

void testInitList() {
    do {
        ds::List<int> mylist =  { 0, 1, 2, 3, 4 };
        for (int i = 5; i < 10; ++i)
            mylist.InsertBack(i);
        for (int x : mylist)
            std::cout << x << std::endl;
    } while (0);
}

void testInsertionOnEmptyList() {
    if (true) {
        do {
            ds::List<int> mylist; 
            mylist.InsertAt(89, mylist.begin());
            mylist.InsertAt(89, mylist.begin());
            mylist.InsertAt(89, mylist.begin());
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
