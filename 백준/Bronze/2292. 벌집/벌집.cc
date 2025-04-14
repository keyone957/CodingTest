#include <iostream>
using namespace std;

int main() {
    long long N;
    cin >> N;
    
    // 중앙 방 1일 경우 바로 1 출력
    if (N == 1) {
        cout << 1;
        return 0;
    }
    
    int count = 1;           // 시작 방(1)을 포함한 단계 수
    long long maxValue = 1;  // 현재 단계에서 도달할 수 있는 최대 번호
    
    // 다음 단계로 넘어가면서 N이 최대 범위 안에 드는지 확인
    while (maxValue < N) {
        maxValue += 6 * count;
        count++;
    }
    
    cout << count;
    return 0;
}
