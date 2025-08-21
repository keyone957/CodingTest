#include <bits/stdc++.h>
using namespace std;

int arr[201][201];
int distv[201][201][31];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(distv, -1, sizeof(distv));

    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };
    int hx[8] = { -2,-1, 1, 2, 2, 1,-1,-2 };
    int hy[8] = { -1,-2,-2,-1, 1, 2, 2, 1 };

    int K, W, H;
    cin >> K >> W >> H;

    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> arr[i][j];

    if (H == 1 && W == 1) {
        cout << 0 << '\n';
        return 0;
    }

    queue<tuple<int,int,int>> q; // (x, y, remainK)
    q.push({0, 0, K});
    distv[0][0][K] = 0;

    while (!q.empty()) {
        auto [x, y, k] = q.front(); q.pop();
        int d = distv[x][y][k];

        // 일반 4방향
        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir], ny = y + dy[dir];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if (arr[nx][ny] == 1) continue;
            if (distv[nx][ny][k] != -1) continue;
            distv[nx][ny][k] = d + 1;
            if (nx == H - 1 && ny == W - 1) {
                cout << distv[nx][ny][k] << '\n';
                return 0;
            }
            q.push({nx, ny, k});
        }

        // 말 이동 8방향
        if (k > 0) {
            for (int dir = 0; dir < 8; ++dir) {
                int nx = x + hx[dir], ny = y + hy[dir];
                if (nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if (arr[nx][ny] == 1) continue;
                if (distv[nx][ny][k - 1] != -1) continue;
                distv[nx][ny][k - 1] = d + 1;
                if (nx == H - 1 && ny == W - 1) {
                    cout << distv[nx][ny][k - 1] << '\n';
                    return 0;
                }
                q.push({nx, ny, k - 1});
            }
        }
    }

    cout << -1 << '\n';
    return 0;
}
