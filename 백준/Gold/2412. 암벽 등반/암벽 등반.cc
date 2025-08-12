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
        board[i] = { x,y };
    }
    //sort(board.begin(), board.end());
    sort(board.begin(), board.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
        });
    queue<int> q; 
    for (int i = 0; i < n; i++)
    {
        int bx = board[i].first;
        int by = board[i].second;
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

        int x = board[cur].first;
        int y = board[cur].second;
        int d = dist[cur];

        if (y >= t) { // 목표 도달
            cout << d;
            return 0;
        }

        //for (int i = 0; i < n; i++)
        //{
        //    if (dist[i] != -1) continue; // 이미 방문
        //    int nx = board[i].first;
        //    int ny = board[i].second;

        //    if (abs(x - nx) <= 2 && abs(y - ny) <= 2)
        //    {
        //        dist[i] = d + 1;
        //        q.push(i);
        //    }
        //}
         // 위쪽 탐색
        for (int i = cur + 1; i < n; i++) {
            int ny = board[i].second;
            if (ny - y > 2) break; // 더 이상 못 감
            if (dist[i] != -1) continue;
            int nx = board[i].first;
            if (abs(x - nx) <= 2) {
                dist[i] = d + 1;
                q.push(i);
            }
        }

        // 아래쪽 탐색
        for (int i = cur - 1; i >= 0; i--) {
            int ny = board[i].second;
            if (y - ny > 2) break;
            if (dist[i] != -1) continue;
            int nx = board[i].first;
            if (abs(x - nx) <= 2) {
                dist[i] = d + 1;
                q.push(i);
            }
        }
    }

    cout << -1;
    return 0;
  

}