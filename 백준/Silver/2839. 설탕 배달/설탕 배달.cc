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
int dp[5001];//i 키로그램 설탕을 만들때 필요한 최소 봉지수
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int kg;
    cin >> kg;
    dp[0] = 0;
    dp[1] = -1;
    dp[2] = -1;
    dp[3] = 1;
    dp[4] = -1;
    dp[5] = 1;

    for (int i = 6; i <= kg; i++)
    {
        if (dp[i - 3] == -1 && dp[i - 5] == -1)
        {
            dp[i] = -1;
        }
        else if(dp[i-3]==-1)
        {
            dp[i] = dp[i - 5] + 1;
        }
        else if (dp[i - 5] == -1)
        {
            dp[i] = dp[i - 3] + 1;
        }
        else
        {
            dp[i] = min(dp[i - 3], dp[i - 5]) + 1;
        }
    }
    cout << dp[kg];
}