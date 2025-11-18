#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 입출력 속도 향상 (선택 사항)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; // 색종이의 수
    cin >> N;

    // 100x100 도화지를 2차원 배열로 표현 (0: 색칠 안 됨, 1: 색칠 됨)
    // 인덱스를 1부터 100까지 사용하기 위해 크기를 101로 설정
    vector<vector<int>> canvas(101, vector<int>(101, 0));

    for (int i = 0; i < N; ++i) {
        int x, y; // 색종이의 왼쪽 아래 꼭짓점 좌표
        cin >> x >> y;

        // 색종이가 덮는 영역을 1로 표시
        // x좌표: x부터 x+9까지
        // y좌표: y부터 y+9까지
        for (int row = x; row < x + 10; ++row) {
            for (int col = y; col < y + 10; ++col) {
                // 도화지 범위(1~100)를 벗어나지 않으므로 별도 검사 필요 없음
                canvas[row][col] = 1; 
            }
        }
    }

    int total_area = 0; // 검은 영역의 넓이
    
    // 도화지 전체를 순회하며 1로 표시된 부분(검은색)의 개수를 셈
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            if (canvas[i][j] == 1) {
                total_area++;
            }
        }
    }

    cout << total_area << "\n";

    return 0;
}