#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m >> k;

    int winner = 1;       // 우승할 반 번호
    int min_time = 2e9;   // 최소 시간 (큰 값으로 초기화)

    for (int i = 1; i <= k; ++i) {
        int f, d;
        cin >> f >> d;

        int time = (f - 1) + (m + 1 - d); // 층 간 이동 + 오른쪽 끝 계단까지 거리
        
        if (time < min_time) {
            min_time = time;
            winner = i;
        }
    }

    cout << winner;
    
    return 0;
}
