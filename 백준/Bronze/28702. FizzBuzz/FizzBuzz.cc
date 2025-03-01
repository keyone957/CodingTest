#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string fizzBuzz(long long n) {
    if(n % 15 == 0) return "FizzBuzz";
    if(n % 3 == 0) return "Fizz";
    if(n % 5 == 0) return "Buzz";
    return to_string(n);
}

bool isNumber(const string &s, long long &num) {
    // 문자열이 숫자라면 num에 저장.
    // 간단하게, 모든 문자가 digit이면 숫자로 판단.
    // (문제에서는 음수는 나오지 않으므로)
    for(char c : s) {
        if(!isdigit(c)) return false;
    }
    stringstream ss(s);
    ss >> num;
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a, b, c;
    cin >> a >> b >> c;
    
    long long n = -1;
    bool found = false;
    
    // 만약 세 문자열 중 하나라도 숫자이면, 해당 위치를 기준으로 n을 구한다.
    long long num;
    // 0번째 문자열이 숫자인 경우
    if(isNumber(a, num)){
        n = num;
        found = true;
    }
    // 1번째 문자열이 숫자인 경우
    else if(isNumber(b, num)){
        n = num - 1;
        found = true;
    }
    // 2번째 문자열이 숫자인 경우
    else if(isNumber(c, num)){
        n = num - 2;
        found = true;
    }
    
    // 세 문자열 모두 숫자가 아닌 경우
    if(!found){
        // FizzBuzz 패턴은 15의 주기를 갖습니다.
        // 1부터 15까지 후보를 대입하여 확인합니다.
        for(int i = 1; i <= 15; i++){
            if(fizzBuzz(i) == a && fizzBuzz(i+1) == b && fizzBuzz(i+2) == c){
                n = i;
                found = true;
                break;
            }
        }
    }
    
    // 다음 출력은 n+3에 해당
    cout << fizzBuzz(n+3) << "\n";
    return 0;
}
