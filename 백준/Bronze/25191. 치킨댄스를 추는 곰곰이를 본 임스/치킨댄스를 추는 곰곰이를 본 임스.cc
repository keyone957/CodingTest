#include <iostream>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    cout << min(N, (A / 2) + B) << endl;
    return 0;
}
