#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int l = 0, h = n - 1;
        int mid = (l + h) / 2;

        if (nums[l] <= nums[h]) // not rotated
            return nums[0];

        while (l <= h)
        {
            mid = (l + h) / 2;
            if (nums[mid] > nums[mid + 1]) // pivot to the right
            {
                mid = mid + 1;
                break;
            }
            if (nums[mid] < nums[mid - 1]) // the right pivot
                break;

            if (nums[mid] >= nums[l])
                l = mid + 1;
            else
                h = mid - 1;
        }
        return nums[mid];
    }
};