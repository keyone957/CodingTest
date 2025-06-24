#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, d, k, c;
    cin >> N >> d >> k >> c;
    vector<int> sushi(N);
    for (int i = 0; i < N; i++)
        cin >> sushi[i];

    vector<int> cnt(d + 1, 0);
    int kind = 0;
    int ans = 0;

    // 초기 윈도우
    for (int i = 0; i < k; i++) {
        if (cnt[sushi[i]] == 0) kind++;
        cnt[sushi[i]]++;
    }

    // 쿠폰 초밥 체크
    ans = kind + (cnt[c] == 0 ? 1 : 0);

    // 슬라이딩 윈도우 (원형)
    for (int i = 1; i < N; i++) {
        int left = sushi[i - 1];
        int right = sushi[(i + k - 1) % N];

        // 왼쪽 초밥 빼기
        cnt[left]--;
        if (cnt[left] == 0) kind--;

        // 오른쪽 초밥 넣기
        if (cnt[right] == 0) kind++;
        cnt[right]++;

        // 쿠폰 초밥 유무 체크
        int cur = kind + (cnt[c] == 0 ? 1 : 0);
        ans = max(ans, cur);
    }
    cout << ans << "\n";
    return 0;
}
