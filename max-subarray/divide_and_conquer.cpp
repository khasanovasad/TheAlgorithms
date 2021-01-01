#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

#define N 16

int find_max_crossing_subarray(std::vector<int>& arr, int low, int mid, int high);
int find_max_subarray(std::vector<int>& arr, int low, int high);

int main() {
    std::vector<int> arr = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
    std::cout << find_max_subarray(arr, 0, arr.size() - 1) << std::endl;
    return 0;
}

int max3(int a, int b, int c) {
    int a_or_b = std::max(a, b);
    return a_or_b > c ? a_or_b : c;
}

int find_max_crossing_subarray(std::vector<int>& arr, int low, int mid, int high) {
    int left_sum = INT_MIN, right_sum = INT_MIN;
    int sum;

    sum = 0;
    for (int i = mid; i >= low; --i) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    for (int i = mid + 1; i <= high; ++i) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return max3(left_sum, right_sum, left_sum + right_sum);
}

int find_max_subarray(std::vector<int>& arr, int low, int high) {
    if (low == high)
        return arr[low];
    else {
        int mid = (low + high) / 2;
        return max3(find_max_subarray(arr, low, mid),
                   find_max_subarray(arr, mid + 1, high),
                   find_max_crossing_subarray(arr, low, mid, high));
    }
}