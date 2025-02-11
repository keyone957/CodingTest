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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int dist[102][102];
	//거리 정보를 넣어줄 dist 배열
	// 상하좌우의 칸을 볼때 값을 잘 넣어주자
	//배열을 미리 -1을 해놓고 vis배열 따로 두지 않아도 방문 여부를 알 수 있다
	string s[102];
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dist[i][j] = -1;
		}
	}
	queue<pair<int, int>> Q;
	dist[0][0] = 0;
	Q.push({ 0,0 });
	while (!Q.empty())
	{
		pair<int, int> cur = Q.front(); Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (dist[nx][ny] != -1 || s[nx][ny] != '1')continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			Q.push({ nx,ny });
		}
	}
	cout << dist[n - 1][m - 1] + 1;



}