#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) 
            break;

        // 가장 긴 변을 c로 설정
        int sides[3] = {a, b, c};
        sort(sides, sides + 3); 

        // 피타고라스 정리 확인
        if (sides[0] * sides[0] + sides[1] * sides[1] == sides[2] * sides[2]) {
            cout << "right" << endl;
        } else {
            cout << "wrong" << endl;
        }
    }
    return 0;
}
