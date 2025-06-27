#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
int board[4000][4000];
int result[3];
int input;
bool check(int x, int y, int n) {
    // (x, y)에서 n x n 정사각형이 모두 같은 값인지 체크
    int first = board[x][y];
    for (int i = x; i < x + n; i++) {
        for (int j = y; j < y + n; j++) {
            if (board[i][j] != first)
                return false;
        }
    }
    return true;
}
void dfs(int x, int y, int n) {
    if (check(x, y, n)) {
        result[board[x][y] + 1]++;
        return;
    }
    int div = n / 3;
    for (int dx = 0; dx < 3; dx++) {
        for (int dy = 0; dy < 3; dy++) {
            dfs(x + dx * div, y + dy * div, div);
        }
    }
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> input;
    for (int i = 0; i < input; i++)
    {
        for (int j = 0; j < input; j++)
        {
            cin >> board[i][j];
        }
    }

    dfs(0, 0, input);
    cout << result[0] << '\n' << result[1] << '\n' << result[2];
}