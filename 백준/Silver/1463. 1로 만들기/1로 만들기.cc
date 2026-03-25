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
int dp[1000003];//i숫자까지 왔을때 연산회수
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    //dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1] +1;
        if (i% 3 == 0)
        {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        if (i % 2 == 0)
        {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }
    cout << dp[n];
}