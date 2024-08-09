#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int end = nums.size() - 1;
        int i = 0;
        int k = nums.size();
        while (i <= end)
        {
            if (nums[i] == val)
            {
                k--;
                swap(nums[i], nums[end]);
                end--;
            }
            else
                i++;
        }
        return k;
    }
};
