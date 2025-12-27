#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> dp(n + 1, 0);

    if (n >= 1) dp[1] = 1;
    if (n >= 2) dp[2] = 1;
    if (n >= 3) dp[3] = 1;

    for (int i = 4; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 3];
    }

    cout << dp[n];
    return 0;
}
