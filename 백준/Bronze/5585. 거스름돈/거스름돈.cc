#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int change = 1000 - n;
    int coins[] = {500, 100, 50, 10, 5, 1};
    int cnt = 0;
    for (int c : coins) {
        cnt += change / c;
        change %= c;
    }
    cout << cnt;
}
