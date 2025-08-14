#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, B, H, W;
    cin >> N >> B >> H >> W;

    int ans = INT_MAX;

    for (int i = 0; i < H; i++) {
        int p;
        cin >> p;

        bool ok = false;
        for (int j = 0; j < W; j++) {
            int a;
            cin >> a;
            if (a >= N) ok = true;
        }

        if (ok) {
            long long cost = 1LL * p * N;
            if (cost <= B) {
                ans = min(ans, (int)cost);
            }
        }
    }

    if (ans == INT_MAX) {
        cout << "stay home\n";
    } else {
        cout << ans << "\n";
    }

    return 0;
}
