class Solution {
int dist[201][201];
int dx[2]={1,0};
int dy[2]={0,1};
public:
    int minPathSum(vector<vector<int>>& grid) {
        int y=grid.size();
        int x=grid[0].size();

        memset(dist, 0x3f, sizeof(dist));
        // for(int i=0;i<y;i++)
        // {
        //     for(int j=0;j<x;j++)
        //     {
        //         if(i==j)
        //         {
        //             dist[i][j]=0;
        //         }
        //     }
        // }
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({-grid[0][0],{0,0}});
        dist[0][0]=grid[0][0];
        while(!pq.empty())
        {
            pair<int,int> cur=pq.top().second;
            int curDist=-pq.top().first;
            pq.pop();
            if(dist[cur.first][cur.second]<curDist) continue;
            for(int i=0;i<2;i++)
            {
                int nextX = cur.second+dx[i];
                int nextY = cur.first+dy[i];
                if(nextX<0||nextY<0||nextX>=x||nextY>=y)continue;
                int nextDist=curDist+grid[nextY][nextX];
                if(nextDist<dist[nextY][nextX])
                {
                    dist[nextY][nextX]=nextDist;
                    pq.push({-nextDist,{nextY,nextX}});
                }
            }
        }
        
        return dist[y-1][x-1];
    }
};