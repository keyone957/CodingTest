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
int arr[101][101];
int visit[101][101];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dx[4] = { -1,1,0,0 };
	int dy[4] = { 0,0,-1,1 };
	int r, c, count;
	cin >> r >> c >> count;
	for (int i = 0; i < count; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x][y] = 1;
	}
	vector<int>answer;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (arr[i][j] == 1 && visit[i][j] == 0)
			{
				queue<pair<int, int>>Q;
				visit[i][j] = 1;
				Q.push({ i,j });
				int size = 0;
				while (!Q.empty())
				{
					size++;
					pair<int, int> cur = Q.front(); Q.pop();
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 1 || nx > r || ny < 1 || ny > c) continue;
						if (visit[nx][ny] == 1 || arr[nx][ny] != 1) continue;
						visit[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
				answer.push_back(size);
			}
		}
	}
	sort(answer.begin(), answer.end());

	if (answer.empty()) cout << 0;
	else cout << answer.back();



}