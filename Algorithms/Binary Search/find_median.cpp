#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n2 < n1)
            return findMedianSortedArrays(nums2, nums1);
        int l = 0;
        int h = n1;
        int mid = (n1 + n2 + 1) / 2;
        while (l <= h)
        {
            int mid1 = (l + h) / 2;
            int mid2 = mid - mid1;
            int maxleft1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int minright1 = (mid1 == n1) ? INT_MAX : nums1[mid1];
            int maxleft2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int minright2 = (mid2 == n2) ? INT_MAX : nums2[mid2];
            if (maxleft1 <= minright2 && maxleft2 <= minright1)
            {
                if ((n1 + n2) % 2 == 0)
                    return (max(maxleft1, maxleft2) + min(minright1, minright2)) / 2.0;
                else
                    return max(maxleft1, maxleft2);
            }
            else if (maxleft1 > minright2)
                h = mid1;
            else
                l = mid1 + 1;
        }
        return 0;
    }
};
// linear solution
// int m = nums1.size(), n = nums2.size();
// vector<int> res;
// int i = 0, j = 0;
// while (i < m && j < n)
// {
//     if (nums1[i] <= nums2[j])
//     {
//         res.push_back(nums1[i]);
//         i++;
//     }
//     else
//     {
//         res.push_back(nums2[j]);
//         j++;
//     }
// }
// while (i < m)
// {
//     res.push_back(nums1[i]);
//     i++;
// }
// while (j < n)
// {
//     res.push_back(nums2[j]);
//     j++;
// }
// int mid = (res.size() - 1) / 2;
// return (res.size() % 2 != 0) ? res[mid] : (res[mid] + res[mid + 1]) / 2.0;
