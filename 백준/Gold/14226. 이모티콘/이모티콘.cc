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
/*
* 이모티콘 s개 만들기.
1. 모두 복사해서 클립보드에 저장
2. 붙여넣기 함.
3. 이모티콘 중 하나 삭제.
모든 연산 1초 걸림. 
비어있는 상태에서는 붙여넣기 x 일부만 복사 x
일부만 삭제 x 
s개 이모티콘 만드는데 걸리는 시간의 최솟값

일단 이미 1개의 이모티콘을 입력해 놓은 상태고
위의 3가지 연산만 사용해서 이모티콘 s개 만들기.
dp?사용하면 되려나?
ex)
 input -> 6
 1. 복사(a)
 2. 붙 a a
 3. 붙 a a a
 4. 복 (a a a)
 5. 붙 a a a a a a
*/
int dp[1001][1001];
//dp [i][j] 
// 현재 화면에 i개의 이모티콘이 있고
// 현재 클립보드에 j개가 있을때 걸린시간.
int s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> s;
    /*
     복사 dp[i][i]=min(dp[i][i],dp[i][j]+1);
     붙혀넣기 dp[i+j][j]=min(dp[i+j][j],dp[i][j]+1);
     삭제 dp[i-1][j]=min(dp[i-1][j],dp[i][j]+1);    
    */

    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            dp[i][j] = 1e9;
        }
    }
    dp[1][0] = 0;
    for (int a = 0; a <= 2000; a++)
    {
        for (int i = 1; i <= 1000; i++)
        {
            for (int j =0; j <= 1000; j++)
            {
                if (dp[i][j] == a)
                {
                    dp[i][i] = min(dp[i][i], dp[i][j] + 1);
                    if (i + j <= 1000)
                    {
                        dp[i + j][j] = min(dp[i + j][j], dp[i][j] + 1);
                    }
                    if (i - 1 > 0)
                    {
                        dp[i - 1][j] = min(dp[i - 1][j], dp[i][j] + 1);
                    }
                }
            }
        }
    }
    int answer = 1e9;
    for (int i = 0; i <= 1000; i++)
    {
        answer = min(answer, dp[s][i]);
    }
    cout << answer;
}
