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
vector<bool> visited;
int answer=0;
void DFS(vector<vector<int>> &arr, int node)
{
	if (visited[node] == 1)
	{
		return;
	}
	visited[node] = 1;
	
	for (int i = 0; i < arr[node].size(); i++)
	{
		int start = arr[node][i];
		if (visited[start] != 1)
		{
			answer++;
			DFS(arr, start);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int computer,edge;

	cin >> computer;
	cin >> edge;
	linkedArr.resize(computer+1);
	visited.resize(computer + 1);
	for (int i = 1; i <= edge; i++)
	{
		int start, end;
		cin >> start >> end;
		linkedArr[start].push_back(end);
		linkedArr[end].push_back(start);
	}
	DFS(linkedArr, 1);
	cout << answer;
}