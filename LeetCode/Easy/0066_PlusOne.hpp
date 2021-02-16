#include <algorithm>
#include <vector>

namespace LeetCode::Easy
{
    auto PlusOneRecursive(std::vector<int>& digits, int currIdx) -> std::vector<int>;
    auto PlusOneIterative(std::vector<int>& digits) -> std::vector<int>;

    auto PlusOne(std::vector<int>& digits) -> std::vector<int>
    {
        return PlusOneRecursive(digits, digits.size() - 1);
        // return PlusOneIterative(digits);
    }

    auto PlusOneRecursive(std::vector<int>& digits, int currIdx) -> std::vector<int>
    {
        if (currIdx < 0)
        {
            digits.insert(digits.begin(), 1);
            return digits;
        }
        else if (digits[currIdx] != 9)
        {
            ++digits[currIdx];
            return digits;
        }
        else
        {
            digits[currIdx] = 0;
            return PlusOneRecursive(digits, currIdx - 1);
        }
    }

    auto PlusOneIterative(std::vector<int>& digits) -> std::vector<int>
    {
        bool flag = true;

        for (int i = digits.size() - 1; i >= 0; --i)
        {
            if (digits[i] != 9)
            {
                ++digits[i];
                flag = false;
                break;
            }
            else
            {
                digits[i] = 0;
            }
        }

        if (flag)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
} // namespace LeetCode::Easy