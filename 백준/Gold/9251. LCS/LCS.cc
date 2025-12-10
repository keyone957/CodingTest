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
int dp[1001][1001];
/*
예시
[A] [C] [A] Y [K] P
C [A] P [C] [A] [K]
LCS는 ACAK

*/
//첫번째 문자열의 i번째 글자까지 잘랐을때
//두번째 문자열의 j번째 글자까지 잘랐을때
//LCS 길이
/*
만일 문자 1[first 길이]==문자 2[second길이]
dp[first.size][second.size]=dp[first.size-1][second.size-1]+1;
다르면
dp[n][m]=max(dp[n-1][m],dp[n][m-1]);

*/

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string first,second;
    cin >> first;
    cin >> second;
    int n = first.size();
    int m = second.size();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (first[i-1] == second[j-1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m];
}