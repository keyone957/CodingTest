#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h1, m1, h2, m2, x;
    cin >> h1 >> m1;
    cin >> h2 >> m2;
    cin >> x;

    int cnt = 0;
    while (true) {
        if (h1 / 10 == x || h1 % 10 == x || m1 / 10 == x || m1 % 10 == x)
            cnt++;
        if (h1 == h2 && m1 == m2) break;
        m1++;
        if (m1 == 60) {
            m1 = 0;
            h1++;
            if (h1 == 24) h1 = 0;
        }
    }
    cout << cnt;
}
