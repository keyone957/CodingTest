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
int n;
int L[21];
int J[21];
int dp[21][100];
//dp 테이블
//i번째 사람까지 봤을때 
//현재 체력이 j일때 얻을 수 있는 최대 기쁨

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int hp = 100;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> L[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> J[i];
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 100; j++)
        {
            dp[i][j] = dp[i - 1][j];//인사 안하는 경우
            if (j - L[i - 1] > 0)//죽지 않았다면
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - L[i - 1]] + J[i - 1]);
            }
        }
    }

    int answer = 0;
    for (int j = 0; j <= 100; j++) 
    {
        answer = max(answer, dp[n][j]);
    }

    cout << answer;

}