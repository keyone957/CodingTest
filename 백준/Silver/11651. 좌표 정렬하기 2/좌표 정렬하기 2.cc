#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 정렬을 위한 비교 함수
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first; // y좌표가 같으면 x좌표 오름차순
    }
    return a.second < b.second; // y좌표 오름차순
}

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> points(N);
    
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    sort(points.begin(), points.end(), compare);
    
    for (const auto& point : points) {
        cout << point.first << " " << point.second << "\n";
    }
    
    return 0;
}