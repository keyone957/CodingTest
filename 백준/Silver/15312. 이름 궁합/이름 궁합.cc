#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    cin >> A >> B;
    const int stroke[26] = {
        3,2,1,2,3,3,2,3,3,2,2,1,2,2,1,2,2,2,1,2,1,1,1,2,2,1
    };

    vector<int> v;
    v.reserve(A.size() * 2);
    for (size_t i = 0; i < A.size(); ++i) {
        v.push_back(stroke[A[i] - 'A']);
        v.push_back(stroke[B[i] - 'A']);
    }

    while (v.size() > 2) {
        vector<int> tmp;
        tmp.reserve(v.size() - 1);
        for (size_t i = 0; i + 1 < v.size(); ++i) {
            tmp.push_back((v[i] + v[i + 1]) % 10);
        }
        v.swap(tmp);
    }

    cout << v[0] << v[1] << "\n";
    return 0;
}
