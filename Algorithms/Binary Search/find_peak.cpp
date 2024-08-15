#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int n = nums.size();
        // edge cases
        if (n == 1)
            return 0;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int l = 0;
        int h = n - 1;
        while (l < h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] > nums[mid + 1])
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
