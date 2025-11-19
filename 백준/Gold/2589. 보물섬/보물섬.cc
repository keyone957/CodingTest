#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <unordered_set>
#include<unordered_map>
#include<math.h>
using namespace std;
int x, y;
char board[51][51];
int dist[51][51];
int answer;
void clear()
{
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            dist[i][j] = -1;
        }
    }
}
int bfs(int startX, int startY)
{
    int farDist = -1;
    int dx[4] = { 0,1,0,-1 };
    int dy[4] = { -1,0,1,0 };
    queue<pair<int, int>> q;
    q.push({ startY,startX });
    dist[startY][startX] = 0;
    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();
        int curX = cur.second;
        int curY = cur.first;
        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if (nextX<0 || nextY<0 || nextX>=x || nextY>=y) continue;
            if(dist[nextY][nextX]>=0||board[nextY][nextX]=='W') continue;
            dist[nextY][nextX] = dist[curY][curX] + 1;
            q.push({ nextY,nextX });
        }
    }
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            farDist = max(farDist, dist[i][j]);
        }
    }

    return farDist;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> y >> x;
    for (int i = 0; i < y; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < x; j++)
        {
            board[i][j] = input[j];
            dist[i][j] = -1;
        }
    }


    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            if (board[i][j] == 'L')
            {
                answer = max(bfs(j, i), answer);
                clear();
            }
           
        }
    }
    cout << answer;
}