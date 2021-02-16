#include <string>
#include <vector>

namespace LeetCode::Easy
{
    int SearchInsert(std::vector<int>& nums, int target)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums.at(i) == target || nums.at(i) > target)
            {
                return i;
            }
        }
        return nums.size();
    }
} // namespace LeetCode::Easy