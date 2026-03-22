#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    bool seats[101] = { false };
    int rejected = 0;

    for (int i = 0; i < N; ++i) {
        int seat_num;
        cin >> seat_num;
        if (seats[seat_num]) {
            rejected++;
        } else {
            seats[seat_num] = true;
        }
    }

    cout << rejected;

    return 0;
}