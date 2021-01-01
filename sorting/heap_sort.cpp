#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "utils.h"

void max_heapify(int* const arr, const int size, const int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int largest = i;

    if (left < size && arr[largest] < arr[left])
        largest = left;
    if (right < size && arr[largest] < arr[right])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        max_heapify(arr, size, largest);
    }
}

void build_max_heap(int* const arr, const int size) {
    for (int i = (size - 1) / 2; i >= 0; --i)
        max_heapify(arr, size, i);
}


void heap_sort(int* const arr, const int size) {
    build_max_heap(arr, size);
    for (int i = size - 1; i >= 0; --i) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, i, 0);
    }
}

int main(int argc, char *argv[]) {
    int size = std::atoi(argv[1]);
    int *arr = new int[size];

    fill_in_random(arr, size, 0);
    // fill_in_increasing(arr, size);
    // fill_in_decreasing(arr, size);

    std::clock_t start = std::clock();
    heap_sort(arr, size);
    std::clock_t stop = std::clock();

    assert_sort(arr, size);

    std::printf("Time elapsed: %f\n", ((double)(stop - start)/CLOCKS_PER_SEC));

    delete[] arr;
    return 0;
}
