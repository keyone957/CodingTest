#include <bits/stdc++.h>
using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

int T; 
if (!(cin >> T)) return 0;
while (T--) {
    int N, M; 
    cin >> N >> M;
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    for (int i = 0; i < N; ++i) {
        int x; cin >> x;
        q.push({x, i});
        pq.push(x);
    }
    int printed = 0;
    while (true) {
        auto cur = q.front(); q.pop();
        if (cur.first == pq.top()) {
            pq.pop();
            ++printed;
            if (cur.second == M) {
                cout << printed << '\n';
                break;
            }
        } else {
            q.push(cur);
        }
    }
}
return 0;


}