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
vector<vector<int>> linkedArr;
vector<int> visited;
void DFS(int v)
{
	if (visited[v] == 1)
	{
		return;
	}
	visited[v] = 1;
	for (int i : linkedArr[v])
	{
		if (visited[i] == 0)
		{
			DFS(i);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n>> m;
	linkedArr.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;
		linkedArr[start].push_back(end);
		linkedArr[end].push_back(start);
	}
	int answer = 0;
	for (int i = 1; i < n+1; i++)
	{
		if (visited[i]!=1)
		{
			answer++;
			DFS(i);
		}
	}
	cout << answer;
}
