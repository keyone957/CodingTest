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
char board[1002][1002];
int fireDist[1002][1002];
int dist[1002][1002];
/*
일단 먼저 불이 퍼지고 
그이후에 상근이 이동
*/
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--)
    {
        int w, h;
        int startX, startY;
        cin >> w >> h;
        int answer = 0;
        bool exit = false;
        queue<pair<int, int>> fireQ;
        queue<pair<int, int>> sangQ;
        for (int i = 0; i < h; i++)
        {
            string input;
            cin >> input;
            for (int j = 0; j < w; j++)
            {
                board[i][j] = input[j];
                fireDist[i][j] = -1;
                dist[i][j] = -1;
                if (input[j] == '@')
                {
                    sangQ.push({ i,j });
                    dist[i][j] = 0;
                }
                if (input[j] == '*')
                {
                    fireQ.push( {i , j});
                    fireDist[i][j] = 0;
                }
            }
        }
        while (!fireQ.empty())
        {
            pair<int, int> cur = fireQ.front();
            fireQ.pop();
            for (int dir = 0; dir < 4; dir++)
            {
                int nextX = cur.second + dx[dir];
                int nextY = cur.first + dy[dir];
                if (nextX < 0 || nextY < 0 || nextX >= w || nextY >= h) continue;
                if (board[nextY][nextX] == '#') continue;
                if (fireDist[nextY][nextX] != -1)continue;
                fireDist[nextY][nextX] = fireDist[cur.first][cur.second] + 1;
                fireQ.push({ nextY,nextX });
            }
        }
        while (!sangQ.empty())
        {
            pair<int, int> cur = sangQ.front();
            sangQ.pop();
            int curX = cur.second;
            int curY = cur.first;
            if (curX == 0 || curY == 0 || curY == h - 1 || curX == w - 1)
            {
                answer = dist[curY][curX] + 1;
                exit = true;
                break;
            }
            for (int dir = 0; dir < 4; dir++)
            {
                int nextX = cur.second + dx[dir];
                int nextY = cur.first + dy[dir];
                if (nextX < 0 || nextY < 0 || nextX >= w || nextY >= h) continue;
                if (board[nextY][nextX] == '#') continue;
                if (dist[nextY][nextX] != -1)continue;
                
                int nextTime = dist[curY][curX] + 1;
                // 불이 안퍼지거나 , 지훈이 도착시간이 불 도착시간 보다 작아야 아직 불이 안 온것이므로 갈 수 있음 
                if (fireDist[nextY][nextX] != -1 && fireDist[nextY][nextX] <= nextTime) continue;
                dist[nextY][nextX] = nextTime;
                sangQ.push({ nextY, nextX });
            }
        }
        if (exit)
        {
            cout << answer << '\n';
        }
        else
        {
            cout << "IMPOSSIBLE" << '\n';
        }

    }
}