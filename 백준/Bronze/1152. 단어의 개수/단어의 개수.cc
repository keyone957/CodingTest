#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    getline(cin, s);
    int count = 1;
    
    if(s.empty()) {
        cout << "0";
        return 0;
    }
    
    // 문자열이 공백으로 시작하면 count를 0으로 시작
    if(s[0] == ' ') count = 0;
    
    // 공백을 만날 때마다 count 증가
    for(int i = 1; i < s.length(); i++) {
        if(s[i-1] == ' ' && s[i] != ' ') count++;
    }
    
    // 문자열이 공백으로 끝나면 count 감소하지 않음
    cout << count;
    
    return 0;
}