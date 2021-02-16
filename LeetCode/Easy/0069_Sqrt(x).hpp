#include <climits>

namespace LeetCode::Easy
{
    int MySqrt(int x)
    {
        if (x <= 1)
        {
            return x;
        }

        int low = 0;
        int high = x;
        int result = -1;

        while (low <= high)
        {
            int64_t guess = low + (high - low) / 2;
            int64_t square = guess * guess;
            bool overflow = (guess > INT_MAX / guess);

            if (!overflow && square == x)
            {
                return guess;
            }
            else if (overflow || square > x)
            {
                high = guess - 1;
            }
            else
            {
                result = guess;
                low = guess + 1;
            }
        }
        return result;
    }
} // namespace LeetCode::Easy