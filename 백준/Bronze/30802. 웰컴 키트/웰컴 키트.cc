#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long N;
    cin >> N;
    long long c[6];
    for (int i = 0; i < 6; i++) cin >> c[i];
    long long T, P;
    cin >> T >> P;
    long long shirtBundles = 0;
    for (int i = 0; i < 6; i++) {
        shirtBundles += (c[i] + T - 1) / T;
    }
    cout << shirtBundles << "\n";
    long long penBundles = N / P;
    long long singlePens = N - penBundles * P;
    cout << penBundles << " " << singlePens;
    return 0;
}
