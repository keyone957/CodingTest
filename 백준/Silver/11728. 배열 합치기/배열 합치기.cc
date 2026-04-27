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
#include<cstring>
using namespace std;
int n, m;
vector<int> a;
vector<int> b;
vector<int> resultArr;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        a.push_back(num);
    }
    for (int j = 0; j < m; j++)
    {
        int num;
        cin >> num;
        b.push_back(num);
    }
    int aIdx = 0;
    int bIdx = 0;
    while (aIdx < n && bIdx < m)
    {

        if (a[aIdx] > b[bIdx])
        {
            resultArr.push_back(b[bIdx]);
            bIdx++;
        }
        else
        {
            resultArr.push_back(a[aIdx]);
            aIdx++;
        }
    }
    while (aIdx < n)
    {
        resultArr.push_back(a[aIdx]);
        aIdx++;
    }
    while (bIdx < m)
    {
        resultArr.push_back(b[bIdx]);
        bIdx++;
    }
    for (int i = 0; i < resultArr.size(); i++)
    {
        cout << resultArr[i] << ' ';
    }
}