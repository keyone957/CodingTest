#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    // students[학년][성별] (학년: 1~6, 성별: 0 여, 1 남)
    int students[7][2] = {0};

    for (int i = 0; i < N; ++i) {
        int S, Y;
        cin >> S >> Y;
        students[Y][S]++;
    }

    int total_rooms = 0;

    for (int grade = 1; grade <= 6; ++grade) {
        for (int gender = 0; gender <= 1; ++gender) {
            int count = students[grade][gender];
            if (count > 0) {
                // (인원 / 방 정원)을 올림 계산
                total_rooms += (count + K - 1) / K;
            }
        }
    }

    cout << total_rooms;

    return 0;
}