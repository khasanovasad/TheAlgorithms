#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <string>

void PrintTimeElapsed()
{
    return;
}

void PrintArray(const int *const arr, const int size, const char *const end)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << *end;
    }
}

void FillRandom(int *const arr, const int size, const int base)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(base, size);
    for (int i = 0; i < size; ++i)
    {
        arr[i] = distrib(gen);
    }
}

void FillDecreasing(int *const arr, const int size)
{
    int j = size - 1;
    for (int i = 0; i < size; ++i)
    {
        arr[i] = j--;
    }
}

void FillIncreasing(int *const arr, const int size)
{
    for (int i = 0; i < size; ++i)
    {
        arr[i] = i;
    }
}

bool IsSorted(const int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

void AssertSort(const int *arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        assert(arr[i] <= arr[i + 1]);
    }
}

#endif // UTILS_H
