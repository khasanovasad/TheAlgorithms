#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "utils.h"

void selection_sort(int* const arr, const int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < size; ++j)
            if (arr[min_idx] > arr[j])
                min_idx = j;
        swap(&arr[i], &arr[min_idx]);
    }
}

int main(int argc, char *argv[]) {
    int size = std::atoi(argv[1]);
    int *arr = new int[size];

    fill_in_random(arr, size, 0);
    // fill_in_increasing(arr, size);
    // fill_in_decreasing(arr, size);

    std::clock_t start = std::clock();
    selection_sort(arr, size);
    std::clock_t stop = std::clock();

    assert_sort(arr, size);

    std::printf("Time elapsed: %f\n", ((double)(stop - start)/CLOCKS_PER_SEC));

    delete[] arr;
    return 0;
}
