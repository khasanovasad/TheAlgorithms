#include "Utils.hpp"

using namespace std::chrono;

void SelectionSort(int* const arr, const int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }
        std::swap(arr[i], arr[min_idx]);
    }
}

int main(int argc, char *argv[])
{
    int size = std::stoi(argv[1]);
    int *arr = new int[size];

    fill_in_random(arr, size, 0);
    // fill_in_increasing(arr, size);
    // fill_in_decreasing(arr, size);

    auto start = high_resolution_clock::now();
    SelectionSort(arr, size);
    auto stop = high_resolution_clock::now();

    assert_sort(arr, size);

    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "Time elapsed: " << (double)duration.count() / 1000 << "s" << std::endl;

    delete[] arr;
    return 0;
}
