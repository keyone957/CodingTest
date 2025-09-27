#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K;
    cin >> N >> K;
    vector<long long> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];
    nth_element(arr.begin(), arr.begin() + K - 1, arr.end());
    cout << arr[K - 1] << "\n";
    return 0;
}
