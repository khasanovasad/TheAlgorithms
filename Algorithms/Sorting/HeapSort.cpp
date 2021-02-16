#include "Utils.hpp"

using namespace std::chrono;

void MaxHeapify(int *const arr, const int size, const int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    int largest = i;

    if (left < size && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right < size && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        MaxHeapify(arr, size, largest);
    }
}

void BuildMaxHeap(int *const arr, const int size)
{
    for (int i = (size - 1) / 2; i >= 0; --i)
    {
        MaxHeapify(arr, size, i);
    }
}

void HeapSort(int *const arr, const int size)
{
    BuildMaxHeap(arr, size);
    for (int i = size - 1; i >= 0; --i)
    {
        std::swap(arr[0], arr[i]);
        MaxHeapify(arr, i, 0);
    }
}

int main(int argc, char *argv[])
{
    int size = std::stoi(argv[1]);
    int *arr = new int[size];

    FillRandom(arr, size, 0);
    // fill_in_increasing(arr, size);
    // fill_in_decreasing(arr, size);

    auto start = high_resolution_clock::now();
    HeapSort(arr, size);
    auto stop = high_resolution_clock::now();

    AssertSort(arr, size);

    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "Time elapsed: " << (double)duration.count() / 1000 << "s" << std::endl;

    delete[] arr;
    return 0;
}
