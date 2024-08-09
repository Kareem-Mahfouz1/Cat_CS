#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int val = 0;
        int n = citations.size();
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < n; i++)
        {
            if (citations[i] >= i + 1)
            {
                val = i + 1;
            }
            else
            {
                break;
            }
        }
        return val;
    }
};