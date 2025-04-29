#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        // 오른쪽 정렬을 위해 앞에 공백을 N-i개 출력
        cout << string(N - i, ' ') << string(i, '*') << '\n';
    }
    return 0;
}