#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>
using namespace std;

class PriorityQueue
{
private:
    vector<pair<int, int>> *array;
    int size;
    int capacity;

    int parent(int pos)
    {
        return (pos == 0) ? -1 : (pos - 1) / 2;
    }
    int left(int pos)
    {
        int l = 2 * pos + 1;
        return (l >= size) ? -1 : l;
    }
    int right(int pos)
    {
        int r = 2 * pos + 2;
        return (r >= size) ? -1 : r;
    }

public:
    PriorityQueue(int cap = 1000)
    {
        array = new vector<pair<int, int>>(cap);
        size = 0;
        capacity = cap;
    }
    void push(pair<int, int> key)
    {
        assert(size + 1 <= capacity);
        array->at(size++) = key;
        heapify_up(size - 1);
    }
    void heapify_up(int child_pos)
    {
        int par_pos = parent(child_pos);
        if (child_pos == 0 || array->at(par_pos).second >= array->at(child_pos).second)
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
        if (right_child != -1 && array->at(right_child).second > array->at(left_child).second)
            left_child = right_child;
        if (array->at(par_pos).second < array->at(left_child).second)
        {
            swap(array[par_pos], array[left_child]);
            heapify_down(left_child);
        }
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
        return array->at(0).first;
    }
    ~PriorityQueue()
    {
        delete[] array;
    }
};

int main()
{
}
