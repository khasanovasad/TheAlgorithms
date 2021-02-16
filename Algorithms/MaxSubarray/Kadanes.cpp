#include <algorithm>
#include <iostream>
#include <vector>

int Kadanes(std::vector<int>& arr);

int main()
{
    std::vector<int> arr = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    std::cout << Kadanes(arr) << std::endl;
    return 0;
}

int Kadanes(std::vector<int>& arr)
{
    int best_sum = 0;
    int curr_sum = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        curr_sum = std::max(0, curr_sum + arr[i]);
        best_sum = std::max(best_sum, curr_sum);
    }
    return best_sum;
}
