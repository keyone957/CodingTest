class Solution {
bool visit[255][255];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int answer=0;
public:
    int countServers(vector<vector<int>>& grid) {
        int y=grid.size();
        int x=grid[0].size();
        int row[255];
        int col[255];
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(grid[i][j]==1)
                {
                    row[i]++;
                    col[j]++;
                }

            }
        }
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(grid[i][j]==1&&(row[i]>1||col[j]>1))
                {
                   answer++;
                }

            }
        }
        return answer;
        
    }
};
