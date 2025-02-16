#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    // N개의 문자열을 입력받고 처리
    for(int i = 0; i < N; i++) {
        string name;
        cin >> name;
        
        // 문자열의 각 문자를 소문자로 변환
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        
        // 변환된 문자열 출력
        cout << name << endl;
    }
    
    return 0;
}