#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <math.h>
using namespace std;

class MinHeap
{
private:
    int *array{};
    int size{};
    int capacity{1000};
    int parent(int pos)
    {
        return floor((pos - 1) / 2);
    }
    int left(int pos)
    {
        int l = pow(2, pos) + 1;
        return (l >= size) ? -1 : l;
    }
    int right(int pos)
    {
        int r = pow(2, pos) + 2;
        return (r >= size) ? -1 : r;
    }
    void heapify()
    {
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify_down(i);
    }
    void heapify_up(int child_pos)
    {
        int par_pos = parent(child_pos);
        if (child_pos == 0 || array[par_pos] <= array[child_pos])
            return;
        swap(array[child_pos], array[par_pos]);
        heapify_up(par_pos);
    }
    void heapify_down(int par_pos)
    {
        int left_child = left(par_pos);
        int right_child = right(par_pos);
        if (left_child == -1)
            return;
        if (right_child != -1 && array[right_child] < array[left_child])
            left_child = right_child;
        if (array[par_pos] > array[left_child])
        {
            swap(array[par_pos], array[left_child]);
            heapify_down(left_child);
        }
    }

public:
    MinHeap()
    {
        array = new int[capacity];
        size = 0;
    }
    MinHeap(vector<int> &v)
    {
        assert(v.size() <= capacity);
        array = new int[capacity];
        size = v.size();
        for (int i = 0; i < v.size(); i++)
            array[i] = v[i];
        heapify();
    }
    void push(int key)
    {
        assert(size + 1 <= capacity);
        array[size++] = key;
        heapify_up(size - 1);
    }
    void pop()
    {
        assert(!isEmpty());
        array[0] = array[--size];
        heapify_down(0);
    }
    bool isEmpty()
    {
        return size == 0;
    }
    int top()
    {
        assert(!isEmpty());
        return array[0];
    }
    ~MinHeap()
    {
        delete[] array;
        array = nullptr;
    }
};
int main()
{
}