#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n,vector<int>(m,-1));
    q.push({0,0});
    dist[0][0]=1;
    while(!q.empty())
    {
        pair<int,int> cur= q.front();
        q.pop();
        int cx=cur.first;
        int cy=cur.second;
        for(int i=0;i<4;i++)
        {
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx<0||nx>=n||ny<0||ny>=m) continue;
            if(maps[nx][ny]==0||dist[nx][ny]!=-1) continue;
            dist[nx][ny]=dist[cx][cy]+1;
            q.push({nx,ny});
        }
    }
   answer=dist[n-1][m-1];
    
    return answer;
}