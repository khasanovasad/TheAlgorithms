#include <string>
#include <vector>

namespace LeetCode::Easy
{
    std::string LongestCommonPrefix(std::vector<std::string>& strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }

        std::string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            if (prefix.length() > strs[i].length())
            {
                prefix.erase(strs[i].length());
            }

            for (int j = 0; j < prefix.length(); ++j)
            {
                if (prefix[j] != strs[i][j])
                {
                    prefix = prefix.substr(0, j);
                    if (prefix == "")
                    {
                        return prefix;
                    }
                    break;
                }
            }
        }
        return prefix;
    }
} // namespace LeetCode::Easy