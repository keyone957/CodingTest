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
vector<vector<int>> linkList;
vector<int> visited;
int answer = 1;
void dfs(int node)
{
	if (visited[node] != 0)
	{
		cout << visited[node]<<'\n';
		return;
	}
	visited[node]= answer++;
	for (int i = 0; i < linkList[node].size(); i++)
	{
		int start = linkList[node][i];
		if (visited[start] == 0)
		{
			dfs(start);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int points, line, startPoints;
	cin >> points >> line >> startPoints;
	linkList.resize(points+1);
	visited.resize(points + 1);
	for (int i = 0; i < line; i++)
	{
		int start, end;
		cin >> start >> end;
		linkList[start].push_back(end);
		linkList[end].push_back(start);
	}
	for (int i = 1; i <= points; i++)
	{
		sort(linkList[i].begin(), linkList[i].end());
	}
	dfs(startPoints);
	for (int i = 1; i <= points; i++)
	{
		cout << visited[i] << '\n';
	}
}