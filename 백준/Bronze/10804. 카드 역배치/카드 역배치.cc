#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int cards[21];
    
    // 카드 초기화
    for(int i = 1; i <= 20; i++) {
        cards[i] = i;
    }

    // 10개의 구간 입력 및 처리
    for(int t = 0; t < 10; t++) {
        int a, b;
        cin >> a >> b;
        reverse(cards + a, cards + b + 1);
    }

    // 최종 카드 상태 출력
    for(int i = 1; i <= 20; i++) {
        cout << cards[i] << " ";
    }

    return 0;
}
