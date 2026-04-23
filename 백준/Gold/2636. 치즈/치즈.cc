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
#include<cstring>
using namespace std;
int n, m;
int board[101][101];
bool isVisit[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
struct CheesePos
{
    int x;
    int y;
};
/*
외부 공기를 기준으로 bfs돌리기

치즈 녹아서 없어지는 시간
녹기 한시간전 남아있는 치즈 개수 출력

*/
void clear()
{
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<m;j++)
        {
            isVisit[i][j] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    int cheeseCnt = 0;
    int time=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 1)
            {
                cheeseCnt++;
            }
        }
    }
 
    while (true)
    {
        clear();
        queue<pair<int, int>> q;
        q.push({ 0,0 });
        isVisit[0][0] = true;
        vector<CheesePos> cheesePos;
      
        while (!q.empty())
        {
            pair<int, int> cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nextx = cur.second + dx[i];
                int nexty = cur.first + dy[i];
                if (nextx < 0 || nexty < 0 || nextx >= m || nexty >= n) continue;
                if (isVisit[nexty][nextx] == 1) continue;
                if (board[nexty][nextx] == 1)//그냥 치즈일때는 방문처리만함
                {
                    CheesePos cp;
                    cp.x = nextx;
                    cp.y = nexty;
                    cheesePos.push_back(cp);
                    isVisit[nexty][nextx] = true;
                }
                else 
                {
                    q.push({ nexty,nextx });
                    isVisit[nexty][nextx] = true;
                }
            }
        }
        int prev = cheeseCnt;
        for (int i = 0; i < cheesePos.size(); i++)
        {
            int y = cheesePos[i].y;
            int x = cheesePos[i].x;
            board[y][x] = 0;
            cheeseCnt--;
        }
        if (cheeseCnt == 0)
        {
            time++;
            cout << time << '\n';
            cout << prev;
            break;
        }
        time++;
    }

}