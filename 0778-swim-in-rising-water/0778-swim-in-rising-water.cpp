class Solution {
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int dist[51][51];
public:
    int swimInWater(vector<vector<int>>& grid) {
        int answer=0;
        int n=grid.size();
        bool arrive=false;
        memset(dist,-1,sizeof(dist));
        int t=0;
        while(!arrive)
        {
            if(grid[0][0]>t)
            { 
                t++;
                continue;
            }
            queue<pair<int,int>> q;
            q.push({0,0});
            dist[0][0]=0;
            while(!q.empty())
            {
                pair<int,int> cur=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nextX=cur.second+dx[i];
                    int nextY=cur.first+dy[i];
                    if(nextX<0||nextY<0||nextX>=n||nextY>=n) continue;
                    if(dist[nextY][nextX]!=-1)continue;
                    if(t<grid[nextY][nextX])continue;
                    dist[nextY][nextX]=dist[cur.first][cur.second]+1;
                    q.push({nextY,nextX});
                }
            }
            if(dist[n-1][n-1]==-1)
            {
                memset(dist,-1,sizeof(dist));
                t++;
            }
            else
            {
                arrive=true;
            }
        }

        return t;
    }
};