class Solution {
public:
    int climbStairs(int n) {
        int dp[46]={0};//-> i번까지 오는데 도달할수 있는 방법의 개수
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        int answer=0;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        if(n==1)
        {
            answer=dp[1];
        }
        else
        {
            answer=dp[n];
        }
        return answer;
    }
};