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
int n, m;
int board[1001][1001];
int dp[1001][1001];
/*이 칸에 도착 했을 때
가장 최대값
그러면 3가지 값중에서 가장 큰 값으로 갱신을 해야함
1. 바로 윗 칸 + 현재 칸의 가치를 더한 값
2. 현재 칸의 가치 + (왼쪽에서부터 이 칸까지 왔을 때 모든 가치값 합)
3. 현재 칸의 가치 + (오른쪽에서부터 이 칸까지 왔을때 모든 가치값 합)

이 3가지 경로가 있음 3가지 값에서 가장 큰 값으로 갱신을 시켜야함
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    dp[0][0] = board[0][0];
    for (int i = 1; i < m; i++)
    {
        dp[0][i] = dp[0][i-1]+board[0][i];
    }
    //일단 먼저 첫번째 줄은 갱신시킴
    for (int i = 1; i < n; i++)
    {
        int leftSum[1001] = {0};
        int rightSum[1001] = {0};//현재 행에서 왼 오 모든 가치의 합을 임시배열
        leftSum[0] = dp[i - 1][0] + board[i][0];
        rightSum[m - 1] = dp[i - 1][m - 1] + board[i][m - 1];
        //일단 맨오른쪽과 맨 왼쪽의 값을 먼저 갱신
        
        for (int j = 1; j < m; j++)
        {   //leftsum[j] = i,j에 도착했을때 오른쪽방향에서 왔을때 가능한 최대값
            /*
            위 or 왼쪽-> 현재 위치까지 이동
            이 두값중 큰거
            */
           
            leftSum[j] = max(dp[i - 1][j], leftSum[j - 1])+board[i][j];
          /*  rightSum[j] = max(dp[i - 1][j], rightSum[j + 1] ) + board[i][j];
            dp[i][j] = max((rightSum[j], leftSum[j]),dp[i-1][j]+board[i][j]);*/
        }
        for (int a = m-2; a >= 0; a--)
         //오른쪽 끝에서부터 현재 위치까지 스캔하면서 
         //배열 갱신
        {
            rightSum[a] = max(dp[i - 1][a], rightSum[a + 1]) + board[i][a];
        }
        for (int b = 0; b < m; b++)
        {
            int leftRight = max(rightSum[b], leftSum[b]);
            dp[i][b] = leftRight;
        }

    }
    /*int a = max({ 1, 2, 3 });
    cout << a;*/
    cout << dp[n-1][m-1];
}