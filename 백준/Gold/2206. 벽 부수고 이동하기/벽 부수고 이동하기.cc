#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

int N, M;
int board[1001][1001];
int dist[1001][1001][2]; // [y][x][벽부순여부]

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = row[j] - '0';
            dist[i][j][0] = 0; // 벽 안부순 거리
            dist[i][j][1] = 0; // 벽 부순 거리
        }
    }

    queue<tuple<int, int, int>> Q; // (y, x, 벽부쉈는지)
    Q.push(make_tuple(0, 0, 0));
    dist[0][0][0] = 1; // 시작점 (벽 안부순 상태) 거리 1

    while (!Q.empty())
    {
        tuple<int, int, int> cur = Q.front(); Q.pop();
        int y = get<0>(cur);
        int x = get<1>(cur);
        int broke = get<2>(cur);

        for (int dir = 0; dir < 4; dir++)
        {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;

            // (1) 벽이 아니고, 아직 방문 안 했을 때
            if (board[ny][nx] == 0 && dist[ny][nx][broke] == 0)
            {
                dist[ny][nx][broke] = dist[y][x][broke] + 1;
                Q.push(make_tuple(ny, nx, broke));
            }
            // (2) 벽이고, 아직 벽을 안 부쉈을 때만 부수고 감
            if (board[ny][nx] == 1 && broke == 0 && dist[ny][nx][1] == 0)
            {
                dist[ny][nx][1] = dist[y][x][broke] + 1;
                Q.push(make_tuple(ny, nx, 1));
            }
        }
    }

    int ans1 = dist[N-1][M-1][0];
    int ans2 = dist[N-1][M-1][1];
    if (ans1 == 0 && ans2 == 0)
        cout << -1 << "\n";
    else if (ans1 == 0)
        cout << ans2 << "\n";
    else if (ans2 == 0)
        cout << ans1 << "\n";
    else
        cout << min(ans1, ans2) << "\n";

    return 0;
}
