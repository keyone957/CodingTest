#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> passwordMap;

    string site, password;
    for (int i = 0; i < N; i++) {
        cin >> site >> password;
        passwordMap[site] = password;
    }

    for (int i = 0; i < M; i++) {
        cin >> site;
        cout << passwordMap[site] << '\n';
    }

    return 0;
}
