#include <string>
#include <vector>

using namespace std;
vector<int> dp;
int solution(int n, vector<int> money) {
    int answer = 0;
    //n 원을 배열에 있는 동전을 가지고 거스름돈이 나올 수 있는 경우의 수
    //
    int arrSize=money.size();
    dp.resize(n+1);
    dp[0]=1;//0원을 만드는 경우의 수 1
    for(int i=0;i<arrSize;i++)
    {
        int coin=money[i];
        for(int j=coin;j<=n;j++)
        {
            dp[j]+=dp[j-coin];
        }
        
    }
    
    
    answer=dp[n]%1000000007;
    
    return answer;
}