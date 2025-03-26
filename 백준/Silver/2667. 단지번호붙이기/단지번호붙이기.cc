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
char arr[25][25];
int isUsed[25][25];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int dx[4] = { 1,0,-1,0 };
	int dy[4] = { 0,1,0,-1 };
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	vector<int> resultArr;
	int fulDangi = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int size = 0;
			if (arr[i][j] == '1' && isUsed[i][j] == 0)
			{
				fulDangi++;
				queue<pair<int, int>> Q;
				isUsed[i][j] = 1;
				Q.push({ i,j });
				while (!Q.empty())
				{
					pair<int, int> cur = Q.front(); Q.pop();
					size++;
					for (int i = 0; i < 4; i++)
					{
						int curX = cur.first + dx[i];
						int curY = cur.second + dy[i];
						if (curX < 0 || curX >= N || curY < 0 || curY >= N) continue;
						if (isUsed[curX][curY] == 1 || arr[curX][curY] == '0') continue;
						isUsed[curX][curY] = 1;
						Q.push({ curX, curY });
					}
				}
				resultArr.push_back(size);
			}
		
		}
	}
	cout << fulDangi<<"\n";
	sort(resultArr.begin(), resultArr.end());
	for (int i = 0; i < resultArr.size(); i++)
	{
		cout << resultArr[i] << "\n";
	}
}
