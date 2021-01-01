#include "utils.h"

using namespace std::chrono;

void max_heapify(int* const arr, const int size, const int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int largest = i;

    if (left < size && arr[largest] < arr[left])
        largest = left;
    if (right < size && arr[largest] < arr[right])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
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
        std::swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }
}

int main(int argc, char *argv[]) {
    int size = std::stoi(argv[1]);
    int *arr = new int[size];

    fill_in_random(arr, size, 0);
    // fill_in_increasing(arr, size);
    // fill_in_decreasing(arr, size);

    auto start = high_resolution_clock::now();
    heap_sort(arr, size);
    auto stop = high_resolution_clock::now();

    assert_sort(arr, size);

    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "Time elapsed: " << (double)duration.count() / 1000 << "s" << std::endl;

    delete[] arr;
    return 0;
}
