#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, h = n - 1;
        int h2 = h, l2 = l;
        int mid = (l + h) / 2;
        if (nums[l] <= nums[h])
            return search(nums, target, l, h);

        while (l <= h)
        {
            mid = (l + h) / 2;
            if (nums[mid] > nums[mid + 1])
            {
                mid = mid + 1;
                break;
            }
            if (nums[mid] < nums[mid - 1])
                break;

            if (nums[mid] >= nums[l])
                l = mid + 1;
            else
                h = mid - 1;
        }
        int res = search(nums, target, mid, h2);
        if (res != -1)
            return res;
        return search(nums, target, l2, mid - 1);
    }
    int search(vector<int> &nums, int target, int l, int h)
    {
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};
