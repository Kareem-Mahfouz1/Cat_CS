#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int r = matrix.size();
        int c = matrix[0].size();
        int l = 0;
        int h = (r * c) - 1;
        while (l <= h)
        {
            int mid = (h + l) / 2;
            int row = mid / c;
            int col = mid % c;
            if (target == matrix[row][col])
                return true;
            else if (target > matrix[row][col])
                l = mid + 1;
            else
                h = mid - 1;
        }
        return false;
    }
};
