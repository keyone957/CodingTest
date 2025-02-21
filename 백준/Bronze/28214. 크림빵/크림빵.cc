#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K, P;
    cin >> N >> K >> P;  // N: 묶음 수, K: 묶음 당 빵 수, P: 허용되는 크림 없는 빵 개수

    vector<int> bread;
    for (int i = 0; i < N * K; ++i) {
        int x;
        cin >> x;
        bread.push_back(x);  // 각 빵에 크림이 들어있는지 여부를 벡터에 저장
    }

    int count = 0;  // 팔 수 있는 묶음의 수
    for (int i = 0; i < N; ++i) {
        int cream_less_count = 0;  // 크림이 없는 빵의 수
        for (int j = 0; j < K; ++j) {
            if (bread[i * K + j] == 0) {
                cream_less_count++;  // 크림이 없는 빵이면 증가
            }
        }
        if (cream_less_count < P) {
            count++;  // 크림이 없는 빵이 P개 미만이면 팔 수 있음
        }
    }

    cout << count << endl;  // 팔 수 있는 묶음의 수 출력
    return 0;
}
