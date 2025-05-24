#include <iostream>
using namespace std;
using ll = long long;

int N;
ll K;

// 수박 x개를 만들 수 있는지 판별
bool canMake(ll x) {
    // 각 단계별로 필요한 과일 수
    for (int i = N; i > 1; --i) {
        // i단계 과일 x개를 만들기 위해 i-1단계 과일이 2x개 필요
        // i-1단계에서 이만큼 뺴고 상위 단계에 넘겨줘야 함
        if (x > (1e18 / 2)) return false; // 오버플로 방지
        x *= 2;
        if (x > K) return false; // 체리 부족
    }
    return x <= K;
}

int main() {
    cin >> N >> K;

    ll left = 0, right = K, ans = 0;
    while (left <= right) {
        ll mid = (left + right) / 2;
        if (canMake(mid)) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}
