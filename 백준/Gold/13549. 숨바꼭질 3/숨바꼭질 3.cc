#include <deque>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> dist(100001, -1);
    deque<int> dq;
    dq.push_back(N);
    dist[N] = 0;
    while (!dq.empty()) {
        int now = dq.front(); dq.pop_front();
        if (now == K) break; // 찾았다면 바로 끝내도 OK
        // 순간이동(0초)
        if (now * 2 <= 100000 && dist[now * 2] == -1) {
            dist[now * 2] = dist[now];
            dq.push_front(now * 2);
        }
        // 뒤로(1초)
        if (now - 1 >= 0 && dist[now - 1] == -1) {
            dist[now - 1] = dist[now] + 1;
            dq.push_back(now - 1);
        }
        // 앞으로(1초)
        if (now + 1 <= 100000 && dist[now + 1] == -1) {
            dist[now + 1] = dist[now] + 1;
            dq.push_back(now + 1);
        }
    }
    cout << dist[K];
}
