#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string input;
    cin >> input;

    int result = 0;
    string num = "";
    bool minus = false;

    for (int i = 0; i <= input.size(); i++) {
        // 숫자 끝 또는 문자열 마지막일 때
        if (i == input.size() || input[i] == '+' || input[i] == '-') {
            int n = stoi(num);
            if (minus) result -= n;
            else result += n;
            num = "";
        }
        if (i == input.size()) break;
        if (input[i] == '-') minus = true;
        if (input[i] == '+' || input[i] == '-') continue;
        num += input[i];
    }
    cout << result << '\n';
    return 0;
}
