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
	int dx[8] = { 1,0,-1,0,-1,1,1,-1 };
	int dy[8] = { 0,1,0,-1,-1,-1,1,1 };

	while (true)
	{
		int x = -1;
		int y = -1;
		int landCount = 0;
		int board[52][52] = { 0 };
		bool visit[52][52] = { 0 };
		cin >> y >> x;
		if (y == 0 && x == 0) break;
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				cin >> board[i][j];
			}
		}
		
		for (int i = 0; i < x; i++)
		{
			for (int j = 0; j < y; j++)
			{
				if (board[i][j] == 1&&visit[i][j]==0)
				{
					landCount++;
					queue<pair<int, int>>Q;
					visit[i][j] = 1;
					Q.push({ i,j });
					while (!Q.empty())
					{
						pair<int, int> cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 8; dir++)
						{
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || nx >= x || ny < 0 || ny >= y) continue;
							if (visit[nx][ny] == 1 || board[nx][ny] != 1) continue;
							visit[nx][ny] = 1;
							Q.push({ nx,ny });
						}
					}
				}
			}
		}
		cout <<  landCount << "\n";
	}

}