#include "Utils.hpp"

using namespace std::chrono;

int Partition(int *const arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; ++j)
    {
        if (arr[j] < pivot)
        {
            std::swap(arr[++i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void QuickSort(int *const arr, int low, int high)
{
    if (low < high)
    {
        // arr[pi] is. now, in its right place
        int pi = Partition(arr, low, high);

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
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
    QuickSort(arr, 0, size - 1);
    auto stop = high_resolution_clock::now();

    AssertSort(arr, size);

    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "Time elapsed: " << (double)duration.count() / 1000 << "s" << std::endl;

    delete[] arr;
    return 0;
}
