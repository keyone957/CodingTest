#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> meetings;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    meetings.reserve(N);

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        meetings.push_back({end, start}); // (끝, 시작)
    }

    sort(meetings.begin(), meetings.end()); // 끝 → 시작 기준 정렬

    int count = 0;
    int last_end = 0;

    for (int i = 0; i < N; i++) {
        int end = meetings[i].first;
        int start = meetings[i].second;
        if (start >= last_end) {
            count++;
            last_end = end;
        }
    }

    cout << count << '\n';
    return 0;
}
