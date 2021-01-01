#include "utils.h"

using namespace std::chrono;

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
    int size = std::stoi(argv[1]);
    int *arr = new int[size];

    fill_in_random(arr, size, 0);
    // fill_in_increasing(arr, size);
    // fill_in_decreasing(arr, size);

    auto start = high_resolution_clock::now();
    insertion_sort(arr, size);
    auto stop = high_resolution_clock::now();

    assert_sort(arr, size);

    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "Time elapsed: " << (double)duration.count() / 1000 << "s" << std::endl;

    delete[] arr;
    return 0;
}
