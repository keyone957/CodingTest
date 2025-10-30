#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int result = 10;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1]) result += 5;
        else result += 10;
    }
    cout << result;
}
