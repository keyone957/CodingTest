#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    unordered_map<int, int> attendance_count;

    for (int i = 0; i < N; ++i) {
        int M;
        cin >> M;
        for (int j = 0; j < M; ++j) {
            int student_id;
            cin >> student_id;
            attendance_count[student_id]++;
        }
    }

    int result = 0;
    for (auto const& [id, count] : attendance_count) {
        if (count >= K) {
            result++;
        }
    }

    cout << result << endl;

    return 0;
}