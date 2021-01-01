#include "utils.h"

using namespace std::chrono;

int partition(int* const arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j)
        if (arr[j] < pivot)
            std::swap(arr[++i], arr[j]);

    std::swap(arr[i + 1], arr[high]);
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
    int size = std::stoi(argv[1]);
    int *arr = new int[size];

    fill_in_random(arr, size, 0);
    // fill_in_increasing(arr, size);
    // fill_in_decreasing(arr, size);

    auto start = high_resolution_clock::now();
    quick_sort(arr, 0, size - 1);
    auto stop = high_resolution_clock::now();

    assert_sort(arr, size);

    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "Time elapsed: " << (double)duration.count() / 1000 << "s" << std::endl;

    delete[] arr;
    return 0;
}
