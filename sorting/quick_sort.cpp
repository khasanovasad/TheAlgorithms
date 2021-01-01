#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "utils.h"

int partition(int* const arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j)
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quick_sort(int* const arr, int low, int high) {
    if (low < high) {
        // arr[pi] is. now, in its right place
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main(int argc, char *argv[]) {
    int size = std::atoi(argv[1]);
    int *arr = new int[size];

    fill_in_random(arr, size, 0);
    // fill_in_increasing(arr, size);
    // fill_in_decreasing(arr, size);

    std::clock_t start = std::clock();
    quick_sort(arr, 0, size - 1);
    std::clock_t stop = std::clock();

    assert_sort(arr, size);

    std::printf("Time elapsed: %f\n", ((double)(stop - start)/CLOCKS_PER_SEC));

    delete[] arr;
    return 0;
}
