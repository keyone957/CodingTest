/*
코인 배열에 있는 코인을 중복해서 여러번 사용할 수 있음
목표 금액 amount에 도달할 때 최소 동전개수 구하기
어떤 조합으로도 만들 수 없다면 -1
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[100001]; //i원을 만들기 위해 필요한 최소 동전의 개수
        std::fill(dp, dp + 100001, 1e9); 
        int cnt=coins.size();
        dp[0]=0;
    int answer=0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0;j<cnt;j++)
            {
                if(i-coins[j]>=0)
                {
                    if(dp[i-coins[j]]!=1e9)
                    {
                        dp[i]=min(dp[i],dp[i-coins[j]]+1);
                    }
                }
            }
        }
        if(dp[amount]==1e9)
        {
            answer=-1;
        }
        else
        {
            answer=dp[amount];
        }
        return answer;
    }
};