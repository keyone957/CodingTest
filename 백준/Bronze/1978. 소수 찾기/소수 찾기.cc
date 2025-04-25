#include <bits/stdc++.h>
using namespace std;

bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, cnt = 0, a;
    cin >> N;
    while (N--) {
        cin >> a;
        if (is_prime(a)) cnt++;
    }
    cout << cnt;
    return 0;
}
