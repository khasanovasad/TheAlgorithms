#include "Utils.hpp"

using namespace std::chrono;

void Merge(int* const arr, int low, int middle, int high)
{
    int n1 = middle - low + 1;
    int n2 = high - middle;
    int *L = new int[n1];
    int *R = new int[n2];

    // separate sorted slices of array
    // into left and right arrays
    for (int i = 0; i < n1; ++i)
    {
        L[i] = arr[low + i];
    }
    for (int j = 0; j < n2; ++j)
    {
        R[j] = arr[middle + 1 + j];
    }

    // merge left and righ slices
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    // in case, some elements are left
    // in either L or R arrays
    while (i < n1)
    {
        arr[k++] = L[i++];
    }
    while (j < n2)
    {
        arr[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

void MergeSort(int* const arr, int low, int high)
{
    if (low < high)
    {
        int middle = (high + low) / 2;
        MergeSort(arr, low, middle);
        MergeSort(arr, middle + 1, high);
        Merge(arr, low, middle, high);
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
    MergeSort(arr, 0, size - 1);
    auto stop = high_resolution_clock::now();

    assert_sort(arr, size);

    auto duration = duration_cast<milliseconds>(stop - start);
    std::cout << "Time elapsed: " << (double)duration.count() / 1000 << "s" << std::endl;

    delete[] arr;
    return 0;
}
