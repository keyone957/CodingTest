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
	int count;
	cin >> count;
	for (int a = 0; a < count; a++)
	{
		int board[52][52] = {0};
		bool visit[52][52] = {0};
		int x, y, target;
		cin >> y >> x>>target;
		
		for (int i = 0; i < target; i++)
		{
			int first, second;
			cin >> first >> second;
			board[first][second] = 1;
		}
		int mincount = 0;
		for (int q = 0; q < y; q++)
		{
			for (int w = 0; w < x; w++)
			{
				if (board[q][w] == 1&&visit[q][w]==0)
				{
					mincount++;
					queue<pair<int, int>>Q;
					visit[q][w] = 1;
					Q.push({ q,w });
					while (!Q.empty())
					{
						pair<int, int> cur = Q.front(); Q.pop();
						for (int dir = 0; dir < 4; dir++)
						{
							int nx = cur.first + dx[dir];
							int ny = cur.second + dy[dir];
							if (nx < 0 || nx >= y || ny < 0 || ny >= x) continue;
							if (visit[nx][ny] == 1 || board[nx][ny] != 1) continue;
							visit[nx][ny] = 1;
							Q.push({ nx,ny });
						}
					}
				}
			}
		}
		cout << mincount<<"\n";
	}


}