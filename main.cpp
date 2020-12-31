#include <iostream>
#include <string>
#include <chrono>

#include "list.h"

void benchmarkTime();

int main(int args, char *argv[]) {
    benchmarkTime();
}

void benchmarkTime() {
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    {
        ds::list<int> mylist;
        for (int i = 0; i < 1'000'000; ++i)
            mylist.add_back(i);
        for (auto x : mylist)
            std::cout << x << "\n";
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "Time elapsed: " << (double)duration.count() / (double)1000 << std::endl;
}
