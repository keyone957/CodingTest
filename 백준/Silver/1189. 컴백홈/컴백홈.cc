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
char board[6][6];
int visited[6][6];
int R, C, K;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1,  0 };
int answer = 0;
void dfs(int y, int x, int dist)
{
    if (y == 0 && x == C - 1) {
        if (dist == K) answer++;
        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
        if (visited[ny][nx] || board[ny][nx] == 'T') continue;
        visited[ny][nx] = 1;
        dfs(ny, nx, dist + 1);
        visited[ny][nx] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C >> K;
    for (int i = 0; i < R; i++)
    {
        string input;
        cin >> input;
        for (int j = 0; j < C; j++)
        {
            board[i][j] = input[j];
        }
    }
    visited[R - 1][0] = 1;
    dfs(R - 1, 0, 1); 
    cout << answer;
}