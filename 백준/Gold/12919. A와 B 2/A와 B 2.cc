#include <iostream>
#include <algorithm>
using namespace std;

string S, T;
int answer = 0;

void dfs(string cur) {
    if (cur.size() < S.size()) return;
    if (cur == S) {
        answer = 1;
        return;
    }
    if (cur.back() == 'A') {
        string next = cur;
        next.pop_back();
        dfs(next);
    }
    if (cur.front() == 'B') {
        string next = cur;
        reverse(next.begin(), next.end());
        next.pop_back();
        dfs(next);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> S >> T;
    dfs(T);
    cout << answer;
    return 0;
}
