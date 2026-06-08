class Solution {
bool visit[15][15];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int answer=0;
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int y=grid.size();
        int x=grid[0].size();
        queue<pair<int,int>> q;
        int check=0;
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
                if(grid[i][j]==1)
                {
                    check++;
                }
            }
        }
        if(check==0)
        {
            return 0;
        }
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                pair<int,int> cur=q.front(); q.pop();
                for(int i=0;i<4;i++)
                {
                    int nextX=cur.second+dx[i];
                    int nextY=cur.first+dy[i];
                    if(nextX<0||nextY<0||nextY>=y||nextX>=x) continue;
                    if(grid[nextY][nextX]!=1) continue;
                    grid[nextY][nextX]=2;
                    q.push({nextY,nextX});
                }
            }
            answer++;
        }
        for(int i=0;i<y;i++)
        {
            for(int j=0;j<x;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return answer-1;
    }
};