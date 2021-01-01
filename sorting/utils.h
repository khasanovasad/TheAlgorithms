#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include <string>
#include <cassert>

void print_time_elapsed() {
    return;
}

void print_arr(const int* const arr, const int size, const char* const end) {
    for (int i = 0; i < size; ++i)
        std::cout << arr[i] << *end;
}

void fill_in_random(int* const arr,const int size, const int base) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(base, size);
    for (int i = 0; i < size; ++i)
        arr[i] = distrib(gen);
}

void fill_in_decreasing(int* const arr, const int size) {
    int j = size - 1;
    for (int i = 0; i < size; ++i)
        arr[i] = j--;
}

void fill_in_increasing(int* const arr, const int size) {
    for (int i = 0; i < size; ++i)
        arr[i] = i;
}

void assert_sort(int* const arr, const int size) {
    for (int i = 0; i < size - 1; ++i)
        assert(arr[i] <= arr[i + 1]);
}

#endif // UTILS_H
