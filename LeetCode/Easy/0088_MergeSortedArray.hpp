#include <vector>

namespace LeetCode::Easy
{
    void Merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
    {
        std::vector<int> copy1(nums1);
        
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (copy1[i] < nums2[j])
            {
                nums1[k++] = copy1[i++];
            }
            else
            {
                nums1[k++] = nums2[j++];
            }
        }
        
        while (i < m)
        {
            nums1[k++] = copy1[i++];
        }
        while (j < n)
        {
            nums1[k++] = nums2[j++];
        }
    }
}