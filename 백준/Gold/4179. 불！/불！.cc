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
using namespace std;
char board[1002][1002];
int fireDist[1002][1002];
int jDist[1002][1002];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    int x, y;
    cin >> y >> x;
    queue<pair<int, int>> fireQ;
    queue<pair<int, int>> jQ;
    for (int i = 0; i < y; i++) 
    {
        for (int j = 0; j < x; j++) 
        {
            cin >> board[i][j];
            fireDist[i][j] = -1;
            jDist[i][j] = -1;

            if (board[i][j] == 'F')
            {
                fireQ.push({ i, j });
                fireDist[i][j] = 0;
            }
            if (board[i][j] == 'J') 
            {
                jQ.push({ i, j });
                jDist[i][j] = 0;
            }
        }
    }
    while (!fireQ.empty())
    {
        pair<int, int>  cur = fireQ.front();
        fireQ.pop();
        for (int dir = 0; dir < 4; dir++)
        {
            int nx = cur.first + dx[dir];
            int ny = cur.second + dy[dir];
            if (nx < 0 || ny < 0 || nx >= y || ny >= x) continue;
            if (board[nx][ny] == '#') continue;
            if (fireDist[nx][ny] != -1) continue;
            fireDist[nx][ny] = fireDist[cur.first][cur.second] + 1;
            fireQ.push({ nx, ny });
        }
    }
    while (!jQ.empty()) {
        pair<int, int>  cur = jQ.front();
        jQ.pop();

        // 현재 위치가 가장자리에 있으면 탈출 성공
        if (cur.first == 0 || cur.second== 0 || cur.first == y - 1 || cur.second == x - 1) {
            cout << jDist[cur.first][cur.second] + 1 << "\n";
            return 0;
        }

        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.first + dx[dir];
            int ny = cur.second  + dy[dir];
            if (nx < 0 || ny < 0 || nx >= y || ny >= x) continue;
            if (board[nx][ny] == '#') continue;
            if (jDist[nx][ny] != -1) continue;

            int nextTime = jDist[cur.first][cur.second] + 1;
            // 불보다 먼저 도착해야 함
            if (fireDist[nx][ny] != -1 && fireDist[nx][ny] <= nextTime) continue;

            jDist[nx][ny] = nextTime;
            jQ.push({ nx, ny });
        }
    }
    cout << "IMPOSSIBLE\n";
    return 0;
}