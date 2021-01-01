#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "utils.h"

void insertion_sort(int* const arr, const int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char *argv[]) {
    int size = std::atoi(argv[1]);
    int *arr = new int[size];

    fill_in_random(arr, size, 0);
    // fill_in_increasing(arr, size);
    // fill_in_decreasing(arr, size);

    std::clock_t start = std::clock();
    insertion_sort(arr, size);
    std::clock_t stop = std::clock();

    assert_sort(arr, size);

    std::printf("Time elapsed: %f\n", ((double)(stop - start)/CLOCKS_PER_SEC));

    delete[] arr;
    return 0;
}
