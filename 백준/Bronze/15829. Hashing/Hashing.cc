#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1234567891;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int L;
    string s;
    cin >> L >> s;

    ll result = 0;
    ll r = 1;

    for (int i = 0; i < L; i++) {
        int val = s[i] - 'a' + 1;
        result = (result + val * r) % MOD;
        r = (r * 31) % MOD;
    }

    cout << result << "\n";
    return 0;
}
