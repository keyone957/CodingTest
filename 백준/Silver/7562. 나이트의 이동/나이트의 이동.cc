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
int board[302][302];
int dist[302][302];
int isVisit[302][302];
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dx[8] = { -1,1,2,2,1,-1,-2,-2 };
	int dy[8] = { -2,-2,-1,1,2,2,1,-1 };
	int input;
	cin >> input;
	for (int i = 0; i < input; i++)
	{
		int chessSize;
		pair<int, int> startPoint;
		pair<int, int> endPoint;
		queue<pair<int, int>>Q;
		cin >> chessSize;
		cin >> startPoint.first >> startPoint.second;
		cin >> endPoint.first >> endPoint.second;
		for (int i = 0; i < 302; i++)
		{
			for (int j = 0; j < 302; j++)
			{
				board[i][j] = 0;
				isVisit[i][j] = 0;
				dist[i][j] = 0;
			}
		}
		while (!Q.empty())
		{
			Q.pop();
		}
		for (int i = 0; i < chessSize; i++)
		{
			for (int j = 0; j < chessSize; j++)
			{
				dist[i][j] = -1;
			}
		}
		dist[startPoint.first][startPoint.second] = 0;
		Q.push(startPoint);
		while (!Q.empty())
		{
			pair<int, int> cur = Q.front();
			if (cur.first == endPoint.first && cur.second == endPoint.second)
			{
				cout << dist[endPoint.first][endPoint.second]  << "\n";
				break;
			}
			Q.pop();
			for (int i = 0; i < 8; i++)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= chessSize || ny < 0 || ny >= chessSize)continue;
				if (dist[nx][ny] != -1)continue;
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				Q.push({ nx, ny });
			}
		}

	}
}