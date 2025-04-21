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
int arr[251][251] = { 0 };
int visited[251][251] = { 0 };
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int dx[8] = { 1,0,-1,0,-1,1,1,-1 };
	int dy[8] = { 0,1,0,-1,-1,-1,1,1 };
	int x, y;
	cin >> y >> x;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			cin >> arr[i][j];
		}
	}
	int answer = 0;
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			if (arr[i][j] == 1&&visited[i][j] == 0)
			{
				answer++;
				queue <pair<int,int>> Q;
				visited[i][j] = 1;
				Q.push({ i,j });
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front(); Q.pop();	
					for (int dir = 0; dir < 8; dir++)
					{
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];
						if (nx < 0 || nx >= y || ny < 0 || ny >= x) continue;
						if (visited[nx][ny] == 1 || arr[nx][ny] != 1) continue;
						visited[nx][ny] = 1;
						Q.push({ nx,ny });
					}
				}
			
			}
		}
	}
	cout << answer;
}