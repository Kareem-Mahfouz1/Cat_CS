#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        int m;
        while (i <= j)
        {
            m = (j + i) / 2;
            if (target == nums[m])
                return m;
            else if (target > nums[m])
                i = m + 1;
            else
                j = m - 1;
        }
        return i;
    }
};
