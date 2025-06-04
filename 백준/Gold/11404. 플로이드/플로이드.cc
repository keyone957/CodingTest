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
vector<vector<long>> arr;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, bus;
	cin >> n;
	cin >> bus;
	arr.resize(n + 1, vector<long>(n + 1));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				arr[i][j] = 0;
			}
			else
			{
				arr[i][j] = 100000000;
			}
		}
	}
	for (int i = 0; i < bus; i++)
	{
		int start, end, dist;
		cin >> start >> end >> dist;
		if (arr[start][end] > dist)
		{
			arr[start][end] = dist;
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int e = 1; e <= n; e++)
			{
				arr[s][e] = min(arr[s][e], arr[s][k] + arr[k][e]);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 100000000)
			{
				cout << 0 << ' ';
			}
			else
			{
				cout << arr[i][j] << ' ';
			}
		}
		cout << '\n';
	}
}