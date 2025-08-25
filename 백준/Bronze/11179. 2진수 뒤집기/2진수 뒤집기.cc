#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unsigned long long n;
    if (!(cin >> n)) return 0;
    
    unsigned long long res = 0;
    while (n) {
        res = (res << 1) | (n & 1);
        n >>= 1;
    }
    cout << res;
    return 0;
}
