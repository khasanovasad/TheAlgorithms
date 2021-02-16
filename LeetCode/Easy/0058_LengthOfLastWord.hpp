#include <string>

namespace LeetCode::Easy
{
    int LengthOfLastWord(std::string s)
    {
        int walk = s.length() - 1;
        while (walk >= 0 && s[walk] == ' ')
        {
            --walk;
        }

        int count = 0;
        while (walk >= 0 && s[walk] != ' ')
        {
            ++count;
            --walk;
        }

        return count;
    }
} // namespace LeetCode::Easy