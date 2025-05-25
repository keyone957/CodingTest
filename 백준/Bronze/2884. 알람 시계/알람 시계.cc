#include <iostream>
using namespace std;

int main() {
    int H, M;
    cin >> H >> M;

    // 45분 일찍 알람 설정
    M -= 45;
    if (M < 0) {
        M += 60;
        H--;
        if (H < 0) H = 23;
    }

    cout << H << " " << M << "\n";

    return 0;
}
