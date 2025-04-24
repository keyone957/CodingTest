#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    int mx = 0;
    for (int i = 1; i <= K; i++) {
        int t = N * i, r = 0;
        while (t > 0) {
            r = r * 10 + (t % 10);
            t /= 10;
        }
        mx = max(mx, r);
    }
    cout << mx;
    return 0;
}
