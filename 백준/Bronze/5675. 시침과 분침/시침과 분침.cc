#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int A;
    while (cin >> A) {
        cout << (A % 6 == 0 ? 'Y' : 'N') << '\n';
    }

    return 0;
}
