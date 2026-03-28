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
/*
n개의 물건 
각 물건은 무게 w 가치 v
최대k만큼의 무게만을 넣을 수 있는 배낭

*/
int n, k;
long long weight[101];
long long price[101];
long long dp[101][100001];
//i개의 물품을 담았을 때 최대 무게가 j인 가방에서 얻을 수 있는 최대 가치
//최대 무게 j인 배낭에서 i번째 물품을 담았을때의 최대 가치
//그러면 정답 출력은 dp[n][k]
/*
1. 최대 무게 초과 했을때
 -> 그냥 이전에 있던거 그대로 유지
 2. 이전의 배낭 최대 가치와 현재 넣을물건의 가치 중 큰 값을 넣어버려
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n>>k;
    for (int i = 1; i <= n; i++)
    {
        cin >> weight[i] >> price[i];
    }
    //dp[0][0] = 0;
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (weight[i] > j)//넣으려고 했을때 이미 배낭의 최대치를 넘어버렸을때 그냥 이전단계에서값을 그대로 가져옴
            {
                dp[i][j] = dp[i - 1][j];//이전 단계에서 값을 그대로 가져옴 더할수 없음
            }
            else//일단 배낭에다가 넣을 수 있을 때
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + price[i]);
                //현재 dp 테이블은 이전 물품의 가치와 , 이전 물품의 값에서 지금 넣으려는 물품의 무게를 빼고 새로 가치를 더한 값으로 갱신함.
            }
        }
    }

    cout << dp[n][k];
}