#include <iostream>
#include <cassert>
#include <queue>
using namespace std;

int min_nodes_rec(int height)
{
    if (height == 0)
        return 1;
    if (height == 1)
        return 2;

    return 1 + min_nodes_rec(height - 1) + min_nodes_rec(height - 2);
}
int min_nodes_ite(int height)
{
    if (height == 0)
        return 1;
    if (height == 1)
        return 2;

    int a = 1, b = 2;
    int sum = 0;
    while (height--)
        sum = a + b + 1, a = b, b = sum;

    return sum;
}

int main(int argc, char const *argv[])
{

    return 0;
}
