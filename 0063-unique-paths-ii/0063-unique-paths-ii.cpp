class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[101][101]={};
        int y=obstacleGrid.size();
        int x=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)
        {
            return 0;
        }
        dp[0][0]=1;
        for(int i=1;i<x;i++)
        {
            if(obstacleGrid[0][i]!=1&&dp[0][i-1]!=0)
            {
                dp[0][i]=1;
            }
        }
        for(int j=1;j<y;j++)
        {
            if(obstacleGrid[j][0]!=1&&dp[j-1][0]!=0)
            {
                dp[j][0]=1;
            }
        }
        
        for(int i=1;i<y;i++)
        {
            for(int j=1;j<x;j++)
            {
                if(obstacleGrid[i][j]==0)
                {
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[y-1][x-1];
    }
};