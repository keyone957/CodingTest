#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int arr[1001] = {0};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;

    int maxHeight = 0;
    int maxIndex = 0;
    int sum = 0;
    int size = 0;
    for (int i = 0; i < count; i++)
    {
        int L, H;
        cin >> L >> H;
        arr[L] = H;
        size = max(size, L);
        if (maxHeight < H)
        {
            maxHeight = H;
            maxIndex = L;
        }
    }
    int leftMax = 0;
    for (int i = 1; i < maxIndex; i++)
    {
        leftMax = max(leftMax, arr[i]);
        sum += leftMax;
    }
    int rightMax = 0;
    for (int i = size; i > maxIndex; i--)
    {
        rightMax = max(rightMax, arr[i]);
        sum += rightMax;
    }
    cout << sum + maxHeight;
}