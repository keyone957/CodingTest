#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
#include<queue>
using namespace std;
int solution(vector<string> maps) {
    int answer = 0;
   
    int xSize=maps[0].size();
    int ySize=maps.size();
    int laberX,laberY,exitX,exitY;
    vector<vector<int>> dist(ySize,vector<int>(xSize,-1));
    queue<pair<int,int>> Q;
    int laberDist;
    int dx[4]={-1,0,1,0};
    int dy[4]={0,-1,0,1};
    for(int i=0;i<ySize;i++)
    {
        for(int j=0;j<xSize;j++)
        {
            if(maps[i][j]=='L')
            {
                laberX=j;
                laberY=i;                
            }
            else if(maps[i][j]=='S')
            {
                Q.push({i,j});
                dist[i][j]=0;
            }
            else if(maps[i][j]=='E')
            {
                exitX=j;
                exitY=i;
            }
            
        }
    }

    while(!Q.empty())
    {
        pair<int,int>cur =Q.front();Q.pop();
        int cx=cur.second;
        int cy=cur.first;
        if(cx==laberX&&cy==laberY)
        {
            laberDist=dist[laberY][laberX];
            break;
        }
        for(int i=0;i<4;i++)
        {
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx<0||nx>=xSize||ny<0||ny>=ySize) continue;
            if(maps[ny][nx]=='X'||dist[ny][nx]!=-1) continue;
            dist[ny][nx]=dist[cy][cx]+1;
            Q.push({ny,nx});
        }
    }
    if (dist[laberY][laberX] == -1) return -1;
    dist.assign(ySize, vector<int>(xSize, -1)); 
    
     queue<pair<int,int>> Q1;
    Q1.push({laberY,laberX});
     dist[laberY][laberX] = 0;
     while(!Q1.empty())
    {
        pair<int,int>cur =Q1.front();Q1.pop();
        int cx=cur.second;
        int cy=cur.first;
        if(cx==exitX&&cy==exitY)
        {
            answer=dist[exitY][exitX]+laberDist;
            break;
           
        }
        for(int i=0;i<4;i++)
        {
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx<0||nx>=xSize||ny<0||ny>=ySize) continue;
            if(maps[ny][nx]=='X'||dist[ny][nx]!=-1) continue;
            dist[ny][nx]=dist[cy][cx]+1;
            Q1.push({ny,nx});
        }
    }
    if (dist[exitY][exitX] == -1) return -1; // 출구 도달 불가
    return answer;
}