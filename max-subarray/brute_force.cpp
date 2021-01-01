#include <iostream>
#include <vector>

int max_subarray(std::vector<int>& arr);

int main() {
    std::vector<int> arr = { 13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7 };
    std::cout << max_subarray(arr) << std::endl;
    return 0;
}

int max_subarray(std::vector<int>& arr) {
    int best_sum = 0;
    int curr_sum = 0;
    for (int i = 0; i < arr.size(); ++i) {
        for (int j = i; j < arr.size(); ++j) {
            curr_sum += arr[j];
            if (best_sum < curr_sum) {
                best_sum = curr_sum;
            }
        }
        curr_sum = 0;
    }
    return best_sum;
}
