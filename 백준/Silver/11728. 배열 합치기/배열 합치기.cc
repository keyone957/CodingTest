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
#include <unordered_set>
#include<unordered_map>
#include<math.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int size = n + m;
    queue<int> a;
    queue<int> b;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        a.push(input);
    }
    for (int i = 0; i < m; i++)
    {
        int input;
        cin >> input;
        b.push(input);
    }

    while (!a.empty() && !b.empty())
    {
        if (a.front() < b.front())
        {
            arr.push_back(a.front());
            a.pop();

        }
        else
        {
            arr.push_back(b.front());
            b.pop();
        }
    }
    while (!a.empty())
    {
        arr.push_back(a.front());
        a.pop();
    }
    while (!b.empty())
    {
        arr.push_back(b.front());
        b.pop();
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<<' ';
    }
}