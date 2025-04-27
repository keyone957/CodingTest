#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b) {
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<string> words(N);
    for (int i = 0; i < N; ++i) {
        cin >> words[i];
    }

    sort(words.begin(), words.end(), compare);

    words.erase(unique(words.begin(), words.end()), words.end());

    for (const auto &word : words)
        cout << word << '\n';

    return 0;
}