#include <iostream>
#include <vector>

using namespace std;

// N!을 계산하여 벡터에 저장 (큰 수 연산)
vector<int> factorial(int n) {
    vector<int> result;
    result.push_back(1);
    
    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (int j = 0; j < result.size(); j++) {
            int product = result[j] * i + carry;
            result[j] = product % 10;
            carry = product / 10;
        }
        while (carry) {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }
    return result;
}

// 뒤에서부터 0의 개수를 세는 함수
int countTrailingZeros(int n) {
    vector<int> fact = factorial(n);
    int count = 0;
    for (int digit : fact) {
        if (digit == 0) count++;
        else break;
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    cout << countTrailingZeros(N) << endl;
    return 0;
}
