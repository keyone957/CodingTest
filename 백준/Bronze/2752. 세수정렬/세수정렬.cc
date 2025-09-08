#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    if (cin >> a >> b >> c) {
        int x[3] = {a, b, c};
        sort(x, x + 3);
        cout << x[0] << ' ' << x[1] << ' ' << x[2];
    }
    return 0;
}
