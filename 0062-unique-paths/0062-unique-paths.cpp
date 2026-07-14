class Solution {

//i j 도착했을때 경로의 갯수
//즉 이전 경로에서 계속 누적하면서 dp 테이블 갱신
public:
    int uniquePaths(int m, int n) {
    int dp[101][101]={0};
    for(int i=0;i<m;i++)
    {
        dp[i][0]=1;
    }
    for(int i=0;i<n;i++)
    {
        dp[0][i]=1;
    }
     for(int i=1;i<m;i++)
     {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            
        }
     }   
     return dp[m-1][n-1];
    }
};