#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, string>> members;
    members.reserve(N);

    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        members.emplace_back(age, name);
    }

    stable_sort(members.begin(), members.end(),
                [](const auto &a, const auto &b) {
                    return a.first < b.first;
                });

    for (const auto &p : members) {
        cout << p.first << ' ' << p.second << '\n';
    }

    return 0;
}
