#include <iostream>
#include <vector>
using namespace std;

void rotate(int n, int d)
{
    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> map[i][j];

    vector<vector<int>> temp = map;
    int c = n / 2;

    if (d == 0 || d % 360 == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << temp[i][j] << ' ';
            cout << '\n';
        }
        return;
    }

    if (d > 0) { // 시계방향
        int cnt = d / 45;
        while (cnt--) {
            for (int i = 0; i < n; i++)
                temp[i][c] = map[i][i];
            for (int i = 0; i < n; i++)
                temp[i][n - 1 - i] = map[i][c];
            for (int i = n - 1; i >= 0; i--)
                temp[c][n - 1 - i] = map[i][n - 1 - i];
            for (int i = n - 1; i >= 0; i--)
                temp[i][i] = map[c][i];
            map = temp;
        }
    } else { // 반시계방향
        int cnt = -d / 45;
        while (cnt--) {
            for (int i = 0; i < n; i++)
                temp[i][i] = map[i][c];
            for (int i = 0; i < n; i++)
                temp[c][i] = map[i][i];
            for (int i = n - 1; i >= 0; i--)
                temp[i][n - 1 - i] = map[c][n - 1 - i];
            for (int i = n - 1; i >= 0; i--)
                temp[i][c] = map[i][n - 1 - i];
            map = temp;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << temp[i][j] << ' ';
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int arrsize, angle;
        cin >> arrsize >> angle;
        rotate(arrsize, angle);
    }
}
