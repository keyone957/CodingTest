#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L, D;
    cin >> N >> L >> D;

    vector<bool> isSong(500000, false);

    int t = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < L; j++) {
            isSong[t++] = true;
        }
        t += 5; // 쉬는 시간
    }

    for (int i = 0; i < isSong.size(); i += D) {
        if (!isSong[i]) {
            cout << i;
            break;
        }
    }
    return 0;
}
