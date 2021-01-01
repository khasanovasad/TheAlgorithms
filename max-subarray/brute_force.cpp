#include <cstdio>

#define N 16

int max_subarray(int *arr, int size);

int main() {
    int arr[N] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
    std::printf("%d\n", max_subarray(arr, N));
    return 0;
}

int max_subarray(int *arr, int size) {
    int best_sum = 0;
    int curr_sum = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            curr_sum += arr[j];
            if (best_sum < curr_sum) {
                best_sum = curr_sum;
            }
        }
        curr_sum = 0;
    }
    return best_sum;
}
