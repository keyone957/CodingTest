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
using namespace std;
vector<pair<int,int>> board;//x축 y축 거리
vector<int>dist;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, t;
    cin >> n >> t;
    //visited.resize(n);
    dist.assign(n, -1);
    board.resize(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        board[i] = { y,x };
    }
    sort(board.begin(), board.end());
   
    queue<int> q; 
    for (int i = 0; i < n; i++)
    {
        int by = board[i].first;   // y좌표
        int bx = board[i].second;  // x좌표
        if (abs(bx - 0) <= 2 && abs(by - 0) <= 2)
        {
            dist[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        int y = board[cur].first;   // y좌표
        int x = board[cur].second;  // x좌표
        int d = dist[cur];

        if (y >= t) // 목표 도달
        {
            cout << d;
            return 0;
        }

        // 위쪽 탐색
        for (int i = cur + 1; i < n; i++)
        {
            int ny = board[i].first;
            if (ny - y > 2) break; // y차이가 2 초과하면 중단
            if (dist[i] != -1) continue;
            int nx = board[i].second;
            if (abs(x - nx) <= 2)
            {
                dist[i] = d + 1;
                q.push(i);
            }
        }

        // 아래쪽 탐색
        for (int i = cur - 1; i >= 0; i--)
        {
            int ny = board[i].first;
            if (y - ny > 2) break;
            if (dist[i] != -1) continue;
            int nx = board[i].second;
            if (abs(x - nx) <= 2)
            {
                dist[i] = d + 1;
                q.push(i);
            }
        }
    }
    cout << -1;
    return 0;
}