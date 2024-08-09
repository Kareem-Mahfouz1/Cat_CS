#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int item : nums)
        {
            mp[item]++;
        }
        for (auto item : mp)
        {
            if (item.second > n / 2)
                return item.first;
        }
        return 0;
    }
};
