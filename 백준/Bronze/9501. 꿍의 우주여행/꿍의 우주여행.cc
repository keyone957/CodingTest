#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        int n, d;
        cin >> n >> d;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            double v, f, c;
            cin >> v >> f >> c;
            if ((f / c) * v >= d) cnt++;
        }
        cout << cnt << "\n";
    }
}
