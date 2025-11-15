#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    cin >> A >> B;

    int n = A.size();

    string AND(n, '0');
    string OR(n, '0');
    string XOR(n, '0');
    string NOTA(n, '0');
    string NOTB(n, '0');

    for (int i = 0; i < n; i++) {
        char a = A[i];
        char b = B[i];

        AND[i]  = (a == '1' && b == '1') ? '1' : '0';
        OR[i]   = (a == '1' || b == '1') ? '1' : '0';
        XOR[i]  = (a != b) ? '1' : '0';
        NOTA[i] = (a == '0') ? '1' : '0';
        NOTB[i] = (b == '0') ? '1' : '0';
    }

    cout << AND << "\n"
         << OR << "\n"
         << XOR << "\n"
         << NOTA << "\n"
         << NOTB;

    return 0;
}
