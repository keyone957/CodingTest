#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> time_start(N + 1, 0); // 악보가 시작하는 시간 (0-based index)

    // 누적 시간 저장
    for (int i = 1; i <= N; i++) {
        int duration;
        cin >> duration;
        time_start[i] = time_start[i - 1] + duration; // 이전 시간에 현재 악보 길이 더하기
    }

    // 질문에 대한 답변
    while (Q--) {
        int T;
        cin >> T;

        // 현재 T초에 부르고 있는 악보 찾기 (이진 탐색 upper_bound 사용)
        int index = upper_bound(time_start.begin(), time_start.end(), T) - time_start.begin();
        cout << index << "\n";
    }

    return 0;
}
