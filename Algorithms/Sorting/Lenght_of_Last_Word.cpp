#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int lenght = 0;
        for (int pos = s.size() - 1; pos >= 0; pos--)
        {
            if (s[pos] == ' ')
                continue;
            else
            {
                while (pos > -1 && s[pos] != ' ')
                {
                    lenght++;
                    pos--;
                }
                break;
            }
        }
        return lenght;
    }
};
