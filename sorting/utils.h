#ifndef UTILS_H
#define UTILS_H

#include <cstdio>
#include <ctime>
#include <cassert>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void print_arr(const int* const arr, const int size, const char* const end) {
    for (int i = 0; i < size; ++i)
        std::printf("%d%c", arr[i], *end);
}

void fill_in_random(int* const arr,const int size, const int base) {
    std::srand(std::time(NULL));
    for (int i = 0; i < size; ++i)
        arr[i] = std::rand() % size + base;
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
