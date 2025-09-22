#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; 
    cin >> s;
    int ans = 0, cur = 0;
    for (char c : s) {
        if (isupper(c)) {
            int need = (4 - (cur % 4)) % 4;
            ans += need;
            cur += need;
        }
        cur++;
    }
    cout << ans;
}
