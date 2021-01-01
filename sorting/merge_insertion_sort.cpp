#include "utils.h"

using namespace std::chrono;

void insertion_sort(int* const arr, const int low, const int high) {
    for (int i = low + 1; i < high; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= low && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void merge(int* const arr, const int low, const int middle, const int high) {
    int n1 = (middle - low) + 1;
    int n2 = high - middle;

    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[low + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[(middle + 1) + j];

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
        if (L[i] < R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void merge_insertion_sort(int* const arr, const int low, const int high) {
    if ((high - low) <= 50) {
        insertion_sort(arr, low, high + 1);
    } else {
        if (low < high) {
            int middle = (high + low) / 2;
            merge_insertion_sort(arr, low, middle);
            merge_insertion_sort(arr, middle + 1, high);
            merge(arr, low, middle, high);
        }
    }
}

int main(int argc, char *argv[]) {
    int size = std::stoi(argv[1]);
    int *arr = new int[size];

    fill_in_random(arr, size, 0);
    // fill_in_increasing(arr, size);
    // fill_in_decreasing(arr, size);

    auto start = high_resolution_clock::now();
    merge_insertion_sort(arr, 0, size - 1);
    auto stop = high_resolution_clock::now();

    assert_sort(arr, size);

    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "Time elapsed: " << (double)duration.count() / 1000 << "s" << std::endl;

    delete[] arr;
    return 0;
}
