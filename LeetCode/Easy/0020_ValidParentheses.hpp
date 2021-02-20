#include <map>
#include <stack>
#include <string>

namespace LeetCode::Easy
{
    bool IsValid(std::string s)
    {
        std::stack<char> comeGo;
        std::map<char, char> brackets {
            { ')', '(' },
            { '}', '{' },
            { ']', '[' },
        };

        for (char ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                comeGo.push(ch);
            }
            else if (comeGo.size() == 0 || comeGo.top() != brackets[ch])
            {
                return false;
            }
            else
            {
                comeGo.pop();
            }
        }

        return comeGo.size() == 0;
    }
} // namespace LeetCode::Easy