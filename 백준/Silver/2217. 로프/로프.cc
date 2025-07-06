#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> ropes(N);

    // 각 로프의 최대 중량 입력받기
    for (int i = 0; i < N; i++) {
        cin >> ropes[i];
    }

    // 오름차순 정렬 (가장 약한 로프부터)
    sort(ropes.begin(), ropes.end());

    int answer = 0;
    // i번째부터 N-1번째까지 로프를 모두 사용한다고 할 때,
    // 들 수 있는 무게는 ropes[i] * (N - i)
    for (int i = 0; i < N; i++) {
        int weight = ropes[i] * (N - i);
        // 최대값 갱신
        answer = max(answer, weight);
    }

    cout << answer << '\n';
    return 0;
}
