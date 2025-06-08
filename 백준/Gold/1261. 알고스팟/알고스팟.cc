#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int board[101][101];     // 미로
int minDist[101][101];   // 벽을 최소로 부순 횟수 저장

// 방향 (상하좌우)
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>> pq;

    // 초기값 설정: 시작점 (0,0)에서 출발. 벽을 부순 횟수는 0
    pq.push({ 0, {0, 0} });
    minDist[0][0] = 0;

    while (!pq.empty()) {
        int cost = -pq.top().first; // 부순 벽의 수 (최소 힙을 위해 음수 처리)
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        // 이미 더 적은 벽을 부수고 도착한 경로가 있으면 무시
        if (minDist[x][y] < cost) continue;

        // 인접한 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 배열 범위를 벗어나지 않는지 체크
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            // 다음 칸이 빈 방(0)이면 현재 cost로 이동
            // 벽(1)이면 cost+1로 이동
            int nextCost = cost + board[nx][ny];

            // 더 적은 수의 벽을 부수고 가는 경로 발견 시 갱신
            if (nextCost < minDist[nx][ny]) {
                minDist[nx][ny] = nextCost;
                pq.push({ -nextCost, {nx, ny} });
            }
        }
    }
}

int main() {
    cin >> M >> N;

    // 미로 입력 받기
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < M; j++)
            board[i][j] = line[j] - '0';
    }

    // minDist 초기화 (최대값으로 설정)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            minDist[i][j] = 1e9;

    // 다익스트라 시작
    dijkstra();

    // 정답 출력 (N-1, M-1 위치까지 최소로 벽 부순 횟수)
    cout << minDist[N-1][M-1] << '\n';
}
