#include <bits/stdc++.h>
using namespace std;

int main() {
    string A, B, C;
    cin >> A >> B >> C;
    
    long long a = stoll(A);
    long long b = stoll(B);
    long long c = stoll(C);
    
    // 수로 계산
    cout << (a + b - c) << "\n";
    
    // 문자열 덧셈 후 수 뺄셈
    string concat = A + B;
    long long d = stoll(concat);
    cout << (d - c) << "\n";
    
    return 0;
}
