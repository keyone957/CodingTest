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

int board[21][21];
int dist[21][21];
int boardSize;

void clear()
{
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            dist[i][j] = -1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int dx[4] = { 1,0,-1,0 };
    int dy[4] = { 0,1,0,-1 };
    int initSize = 2;
    queue<pair<int, int>>q;
    cin >> boardSize;
    clear();
    int isOne = 0;// 물고기가 보드에 하나만 있을 경우를 확인
    pair<int, int> onlyOneFishPos;//하나만있을 시 그때 물고기 위치
    int eatCnt = 0;//상어가 물고기 먹은 횟수
    int sharkX, sharkY;
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < boardSize; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == 9)
            {
                q.push({ i,j });
                sharkX = i; sharkY = j;
                dist[i][j] = 0;//처음 아기상어 찾기 + 방문처리
                board[i][j] = 0;//빈칸처리
            }
            if (board[i][j] != 0 && board[i][j] != 9)
            {
                isOne++;
                onlyOneFishPos = { i,j };
            }
        }
    }

    int totalTime = 0;
    while (true)
    {
        clear();
        queue<pair<int, int>> q;
        q.push({ sharkX, sharkY });
        dist[sharkX][sharkY] = 0;

        int minDist = 1e9;
        int fx = -1, fy = -1;

        // BFS: dist 모두 갱신 & 먹을 수 있는 가장 가까운 물고기 찾기
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= boardSize || ny >= boardSize) continue;
                if (dist[nx][ny] != -1) continue;
                if (board[nx][ny] > initSize) continue;

                dist[nx][ny] = dist[x][y] + 1;

                // 먹을 수 있는 물고기
                if (board[nx][ny] >= 1 && board[nx][ny] < initSize) {
                    // 조건 1: 더 가까움
                    if (dist[nx][ny] < minDist) {
                        minDist = dist[nx][ny];
                        fx = nx;
                        fy = ny;
                    }
                    // 조건 2: 거리가 같으면 위/왼쪽 우선
                    else if (dist[nx][ny] == minDist) {
                        if (nx < fx || (nx == fx && ny < fy)) {
                            fx = nx;
                            fy = ny;
                        }
                    }
                }
                q.push({ nx, ny });
            }
        }

        // 더 이상 먹을 수 있는 물고기가 없으면 끝
        if (fx == -1 && fy == -1) break;

        // 먹는다: 상어 위치, 크기, eatCnt, 시간 갱신
        sharkX = fx;
        sharkY = fy;
        board[fx][fy] = 0;
        totalTime += minDist;
        eatCnt++;

        if (eatCnt == initSize)
        {
            initSize++;
            eatCnt = 0;
        }
    }
    cout << totalTime;
    return 0;
}