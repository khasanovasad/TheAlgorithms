#include <iostream>
#include <string>
#include <vector>
#include <chrono>

#include "list.h"

void benchmark_time();
void test_copy_ctor();
void test_init_list();
void test_add_on_empty_list();
void test_add_at();
void test_delete_at();
void test_it_inc_decr();

int main(int args, char *argv[]) {
    // benchmarkTime();
    // testCopyCtor();
    // testInitList();
    // testInsertionOnEmptyList();
    testInsertAt();
    // testRemoveAt();
    // testPrePostIncrementDecrement();
}

void benchmark_time() {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    {
        dsa::list<int> mylist;
        for (int i = 0; i < 10'000'000; ++i)
            mylist.add_back(i);
        for (auto x : mylist)
            std::cout << x << "\n";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "Time elapsed: " << (double)duration.count() / (double)1000 << std::endl;
}

void test_copy_ctor() {
    do {
        dsa::list<std::string> mylist;
        for (int i = 0; i < 5; ++i)
            mylist.add_back("sex is good");
        dsa::list<std::string> mylist2(mylist);
        for (auto x : mylist2)
            std::cout << x << std::endl;
    } while (0);
}

void test_init_list() {
    do {
        dsa::list<int> mylist =  { 0, 1, 2, 3, 4 };
        for (int i = 5; i < 10; ++i)
            mylist.add_back(i);
        for (int x : mylist)
            std::cout << x << std::endl;
    } while (0);
}

void test_add_on_empty_list() {
    if (true) {
        do {
            dsa::list<int> mylist;
            mylist.add_at(89, mylist.begin());
            mylist.add_at(89, mylist.begin());
            mylist.add_at(89, mylist.begin());
            for (int x : mylist)
                std::cout << x << " ";
            std::cout << std::endl;
            // output: 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
        } while (0);
    } else {
        do {
            dsa::list<int> mylist;
            mylist.add_front(0);
            mylist.add_back(1);
            for (auto it = mylist.begin(); it != mylist.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
            // output: 0 1
        } while (0);
    }
}

void test_add_at() {
    do {
        dsa::list<int> mylist;
        for (int i = 0; i < 15; ++i)
            mylist.add_back(i);
        // mylist.delete_front();
        mylist.add_at(89, ++++++++++mylist.begin());
        mylist.add_at(89, mylist.begin());
        mylist.add_at(89, mylist.end());
        for (int x : mylist)
            std::cout << x << " ";
        std::cout << std::endl;
        // output: 89 0 1 2 3 4 89 5 6 7 8 9 10 11 12 13 14 89
    } while (0);
}

void test_delete_at() {
    do {
        dsa::list<int> mylist;
        for (int i = 0; i < 15; ++i)
            mylist.add_back(i);
        mylist.delete_at(++++mylist.begin());
        mylist.delete_at(mylist.begin());
        mylist.delete_at(--mylist.end());
        for (int x : mylist)
            std::cout << x << " ";
        std::cout << std::endl;
        // output: 1 3 4 5 6 7 8 9 10 11 12 13
    } while (0);
}

void test_it_inc_decr() {
    do {
        dsa::list<int> mylist;
        for (int i = 0; i < 15; ++i)
            mylist.add_back(i);
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
