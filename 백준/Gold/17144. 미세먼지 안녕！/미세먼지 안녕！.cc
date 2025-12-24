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
int r, c, t;
int board[1001][1001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int firstXDir[4] = { 1,0,-1,0 };
int firstYDir[4] = { 0,-1,0,1 };
int secondXDir[4] = { 1,0,-1,0 };
int secondYDir[4] = { 0,1,0,-1 };
/*
* 공기 청정기는 1번 열에만 설치, 가로 두칸 차지.
* -1이 공기 청정기 있는 위치
1. 미세먼지 4방향으로 확산
 그 칸에 공청정기 있거나 칸 없으면 확산 x
 확산 양은 그 칸 /5
 남은 미세먼지 양은 { 원래 있던 미세먼지 - (확산양*확산된 방향의 개수) }
2. 바람은 위 아래에서 각각 반시계, 시계 방향으로 순황.
만약에 이 바람에 닿으면 방향대로 한칸씩 이동. -> 이동할때 범위 밖으로 나가면 삭제되는듯

최종적으로 마지막에 미세 먼지양 출력.
*/

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int firstX, firstY, secondX, secondY;
    cin >> r >> c >> t;
    int findFirst = false;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> board[i][j];
            if (board[i][j] == -1 && !findFirst)
            {
                firstX = j;
                firstY = i;
                findFirst = true;
            }
            if (board[i][j] == -1 && findFirst)
            {
                secondX = j;
                secondY = i;
            }
        }
    }
    while (t--)
    {
        vector<vector<int>> temp(r, vector<int>(c, 0));//동시에 확산되는걸 temp안에 넣고 갱신위함
        temp[firstY][firstX] = -1;
        temp[secondY][secondX] = -1;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (board[i][j] <= 0) continue;//공청하고 빈공간 무시
                int spread = board[i][j] / 5;
                int cnt = 0;
                for (int a = 0; a < 4; a++)
                {
                    int nx = j + dx[a];
                    int ny = i + dy[a];
                    if (nx < 0 || ny < 0 || nx >= c || ny >= r) continue;
                    if (board[ny][nx] == -1) continue;//공기청정기 있는위치
                    temp[ny][nx] += spread;
                    cnt++;

                }
                temp[i][j] += board[i][j] - spread * cnt;
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                board[i][j] = temp[i][j];
            }
        }//보드 내용 저장


      // ===== 위쪽 공기청정기 (반시계) =====
        {
            int y = firstY, x = firstX;
            int dir = 0;          // right, up, left, down
            int prev = 0;

            while (true)
            {
                int ny = y + firstYDir[dir];
                int nx = x + firstXDir[dir];

                // upper loop 범위: 0 ~ firstY
                if (nx < 0 || ny < 0 || nx >= c || ny > firstY)
                {
                    dir = (dir + 1) % 4;
                    continue;
                }
                if (board[ny][nx] == -1) break;

                int cur = board[ny][nx];
                board[ny][nx] = prev;
                prev = cur;

                y = ny; x = nx;
            }
        }

        // ===== 아래쪽 공기청정기 (시계) =====
        {
            int y = secondY, x = secondX;
            int dir = 0;          // right, down, left, up
            int prev = 0;

            while (true)
            {
                int ny = y + secondYDir[dir];
                int nx = x + secondXDir[dir];

                // lower loop 범위: secondY ~ r-1
                if (nx < 0 || ny < secondY || nx >= c || ny >= r)
                {
                    dir = (dir + 1) % 4;
                    continue;
                }
                if (board[ny][nx] == -1) break;

                int cur = board[ny][nx];
                board[ny][nx] = prev;
                prev = cur;

                y = ny; x = nx;
            }
        }

        // 공기청정기 위치 복구
        board[firstY][firstX] = -1;
        board[secondY][secondX] = -1;
    }
    int answer = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] > 0)
                answer += board[i][j];
        }
    }

    cout << answer << '\n';
    return 0;
}