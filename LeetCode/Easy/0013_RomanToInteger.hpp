#include <map>
#include <string>
#include <vector>

namespace LeetCode::Easy
{
    int RomanToInt(std::string s)
    {
        std::map<char, int> values
        {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 },
        };

        int result = 0, i;
        for (i = 0; i < s.length() - 1; ++i)
        {
            if (values[s[i]] < values[s[i + 1]])
            {
                result += values[s[i + 1]] - values[s[i]];
                ++i;
            }
            else
            {
                result += values[s[i]];
            }
        }

        if (i == s.length() - 1)
        {
            result += values[s[i]];
        }

        return result;
    }
} // namespace LeetCode::Easy