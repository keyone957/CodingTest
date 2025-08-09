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
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int count;
    cin >> count;
    vector<int> dp;
    vector<int> arr;
    dp.resize(count);
    arr.resize(count);
   
    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];

    }
    dp[0] = arr[0];
    for (int i = 0; i < count; i++)
    {
        dp[i] = max(arr[i], dp[i - 1] + arr[i]);
    }
    int answer = *max_element(dp.begin(), dp.end());
    cout << answer;
}