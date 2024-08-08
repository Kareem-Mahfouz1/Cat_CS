#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
void Bubble_Sort(vector<int> &arr) // time O(n^2), space O(1)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
}
void Count_Sort(vector<int> &arr) // time O(MAX_VALUE), space O(MAX_VALUE)
{
    int n = arr.size();
    const int MAX_VALUE = *max_element(arr.begin(), arr.end());
    int freq[MAX_VALUE + 1] = {0};

    for (int item : arr)
        freq[item]++;

    for (int i = 1; i < MAX_VALUE + 1; i++)
        freq[i] += freq[i - 1];

    vector<int> res(n);

    for (int i = 0; i < n; i++)
    {
        int val = arr[i];
        res[freq[val] - 1] = val;
        freq[val]--;
    }
    arr = res;
}
void Insertion_Sort(int arr[], int n) // time O(n^2), space O(1)
{
    int key, j;
    for (int i = 1; i < n; i++)
    {
        j = i - 1;
        key = arr[i];
        while (j >= 0 && arr[j] > key) // shifting elements
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key; // assigning the element to its right place
    }
}
void Selection_Sort(vector<int> &arr) // time O(n^2), space O(1)
{
    int n = arr.size();
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) // finding minimum
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(arr[i], arr[min_idx]);
    }
}

void Merge(vector<int> &nums, int l, int m, int r)
{
    int s1 = m - l + 1;
    int s2 = r - m;
    vector<int> L(s1);
    vector<int> R(s2);
    for (int i = 0; i < s1; i++)
        L[i] = nums[l + i];

    for (int i = 0; i < s2; i++)
        R[i] = nums[m + i + 1];

    int i = 0, j = 0, k = l;
    while (i < s1 && j < s2)
    {
        if (L[i] <= R[j])
        {
            nums[k] = L[i];
            i++;
        }
        else
        {
            nums[k] = R[j];
            j++;
        }

        k++;
    }

    while (j < s2)
    {
        nums[k] = R[j];
        j++, k++;
    }

    while (i < s1)
    {
        nums[k] = L[i];
        i++, k++;
    }
}
void Merge_Sort(vector<int> &arr, int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        Merge_Sort(arr, l, m);
        Merge_Sort(arr, m + 1, r);

        Merge(arr, l, m, r);
    }
}
void Merge_Sort(vector<int> &arr) // time O(n log(n)), space O(n)
{
    if (!arr.empty())
        Merge_Sort(arr, 0, arr.size() - 1);
}

void display(vector<int> arr)
{
    for (int item : arr)
    {
        cout << item << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums = {1, 5, 9, 3, 0, 7, 2};
    Merge_Sort(nums);
    display(nums);
}
