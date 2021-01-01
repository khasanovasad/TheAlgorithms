#include <cstdio>
#include <cstdlib>
#include <ctime>

#include "utils.h"

void merge(int* const arr, int low, int middle, int high) {
    int n1 = middle - low + 1;
    int n2 = high - middle;
    int *L = new int[n1];
    int *R = new int[n2];

    // separate sorted slices of array
    // into left and right arrays
    for (int i = 0; i < n1; ++i)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[middle + 1 + j];

    // merge left and righ slices
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
        if (L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];

    // in case, some elements are left
    // in either L or R arrays
    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void merge_sort(int* const arr, int low, int high) {
    if (low < high) {
        int middle = (high + low) / 2;
        merge_sort(arr, low, middle);
        merge_sort(arr, middle + 1, high);
        merge(arr, low, middle, high);
    }
}

int main(int argc, char *argv[]) {
    int size = std::atoi(argv[1]);
    int *arr = new int[size];

    fill_in_random(arr, size, 0);
    // fill_in_increasing(arr, size);
    // fill_in_decreasing(arr, size);

    std::clock_t start = std::clock();
    merge_sort(arr, 0, size - 1);
    std::clock_t stop = std::clock();

    assert_sort(arr, size);

    std::printf("Time elapsed: %f\n", ((double)(stop - start)/CLOCKS_PER_SEC));

    delete[] arr;
    return 0;
}
