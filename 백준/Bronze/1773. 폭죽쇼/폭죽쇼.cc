#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    cin >> n >> c;

    vector<bool> fire(c + 1, false);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        for (int j = t; j <= c; j += t) {
            fire[j] = true;
        }
    }

    int ans = 0;
    for (int i = 1; i <= c; i++) {
        if (fire[i]) ans++;
    }

    cout << ans;
    return 0;
}
