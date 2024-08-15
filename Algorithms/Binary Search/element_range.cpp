#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

class Solution
{
private:
    int findFirst(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int h = n - 1;
        int pos = -1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] == target)
            {
                pos = mid;
                h = mid - 1;
            }
            else if (nums[mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return pos;
    }
    int findLast(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int h = n - 1;
        int pos = -1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] == target)
            {
                pos = mid;
                l = mid + 1;
            }
            else if (nums[mid] > target)
                h = mid - 1;
            else
                l = mid + 1;
        }
        return pos;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int first = findFirst(nums, target);
        int last = findLast(nums, target);
        return {first, last};
    }
};
