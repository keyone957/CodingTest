#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());

    int cut = (int)round(n * 0.15);
    long long sum = 0;
    for (int i = cut; i < n - cut; i++) sum += v[i];
    int cnt = n - 2 * cut;

    cout << (int)round((double)sum / cnt);
    return 0;
}
