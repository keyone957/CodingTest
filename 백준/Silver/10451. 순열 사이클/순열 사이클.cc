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

void DFS(vector<vector<int>>& arr,int node,vector<int>& visited)
{
	if (visited[node] == 1) return;
	visited[node] = 1;
	for (int i = 0; i < arr[node].size(); i++)
	{
		int start = arr[node][i];
		if (/*arr[node][i]==1 && */visited[start] != 1)
		{
			DFS(arr, start, visited);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count;
	cin >> count;
	vector<int> answerArr;
	for (int i = 0; i < count; i++)
	{
		int num;
		cin >> num;
		vector<vector<int>>linkArr;
		vector<int> visit;
		linkArr.resize(num + 1);
		visit.resize(num + 1);
		for (int j = 1; j < num + 1; j++)
		{
			int end;
			cin >> end;
			linkArr[j].push_back(end);
		}
		int answer=0;

		for (int a = 1; a < num + 1; a++)
		{
			if (visit[a] != 1)
			{
				DFS(linkArr, a, visit);
				answer++;
			}
		}
		answerArr.push_back(answer);
	}
	for (int i = 0; i < answerArr.size(); i++)
	{
		cout << answerArr[i] << "\n";
	}
}