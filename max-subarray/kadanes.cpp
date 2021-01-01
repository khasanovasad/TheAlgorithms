#include <cstdio>

#define N 16

int max(int a, int b);
int kadanes(int arr[], int size);

int main() {
    int arr[N] = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
    std::printf("%d\n", kadanes(arr, N));
    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int kadanes(int arr[], int size) {
    int best_sum = 0;
    int curr_sum = 0;
    for (int i = 0; i < size; ++i) {
        curr_sum = max(0, curr_sum + arr[i]);
        best_sum = max(best_sum, curr_sum);
    }
    return best_sum;
}
