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
#include <cmath>
char board[102][102];
bool Wvis[102][102];
bool Bvis[102][102];
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >>m;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	
	int WSum = 0;
	int BSum = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int curW = 0;
			if (board[i][j] == 'W' && Wvis[i][j] == 0)
			{
				
				queue<pair<int, int>> Q;
				Wvis[i][j] = 1;
				Q.push({ i,j });
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front(); Q.pop();
					curW++;
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
						if (Wvis[nx][ny] == 1 || board[nx][ny] == 'B') continue;
						Wvis[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
				WSum += pow(curW, 2);
				//WSum =WSum+ curW ^ 2;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int curB = 0;
			if (board[i][j] == 'B' && Bvis[i][j] == 0)
			{

				queue<pair<int, int>> Q;
				Bvis[i][j] = 1;
				Q.push({ i,j });
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front(); Q.pop();
					curB++;
					for (int dir = 0; dir < 4; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
						if (Bvis[nx][ny] == 1 || board[nx][ny] == 'W') continue;
						Bvis[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
				BSum += pow(curB, 2);
				//WSum =WSum+ curW ^ 2;
			}
		}
	}
	cout << WSum << ' ' << BSum;
}