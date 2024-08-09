#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int index = 0;
        for (int j = index; j < nums.size(); j++)
        {
            if (index == 0 || nums[index - 1] != nums[j])
            {
                nums[index] = nums[j];
                index++;
            }
        }
        return index;
    }
};
