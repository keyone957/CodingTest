#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s, l;
    cin >> s >> l;
    
    // 버퍼 비우기 (cin과 getline 혼용 시 필수)
    cin.ignore();

    string text;
    getline(cin, text);

    // 알파벳은 26개이므로, 불필요한 회전을 줄이기 위해 나머지 연산 사용
    int shift = s % 26;

    for (int i = 0; i < l; ++i) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            // 대문자 처리
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            // 소문자 처리
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
        }
        // 공백이나 구두점('.')은 변환 없이 그대로 출력됩니다.
    }

    cout << text;

    return 0;
}