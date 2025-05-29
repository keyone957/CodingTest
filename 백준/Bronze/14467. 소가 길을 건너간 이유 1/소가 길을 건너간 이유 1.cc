#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;

    vector<int> lastPosition(11, -1); // 소 번호 1~10, 초기값 -1 (아직 관찰 안됨)
    int crossings = 0;

    for (int i = 0; i < N; i++) {
        int cow, pos;
        cin >> cow >> pos;

        // 이전 위치가 있고, 다르면 건넌 횟수 증가
        if (lastPosition[cow] != -1 && lastPosition[cow] != pos) {
            crossings++;
        }
        lastPosition[cow] = pos; // 현재 위치 업데이트
    }

    cout << crossings << "\n";
    return 0;
}
