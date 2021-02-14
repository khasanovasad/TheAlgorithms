#include <vector>
#include <map>

namespace LeetCode::Easy
{
    auto TwoSum(std::vector<int>& nums, int target) -> std::vector<int>
    {
        std::map<int, int> dict;

        for (int i = 0; i < nums.size(); ++i)
        {
            auto it = dict.find(nums.at(i));
            if (it != dict.end())
            {
                return { dict[nums.at(i)], i };
            }
            dict.insert({target - nums.at(i), i});
        }

        return { };
    }
}