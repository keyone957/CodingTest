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
vector<vector<int>> arr;
vector<int> visit;
vector<int> answer;
void DFS(int node)
{
	if (visit[node]==1)
	{
		return;
	}
	visit[node] = 1;
	for (int i = 0; i < arr[node].size(); i++)
	{
		int next = arr[node][i];
		// --> 시작점 부터 다음 노드 확인하면서 끝에 다시 시작점으로 돌아오면 
		//visit된거이므로 이제 dfs멈춤
		//자식 노드로 가기 직전에 현재 노드가 다음번에 탐색할 노드의 부모 노드임.
		if (visit[next] != 1)
		{
			answer[next] = node;
			DFS(next);
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
	arr.resize(count + 1);
	visit.resize(count + 1);
	answer.resize(count + 1);
	for (int i = 1; i < count; i++)
	{
		int start, end;
		cin >> start >> end;
		arr[start].push_back(end);
		arr[end].push_back(start);
	}
	DFS(1);
	for (int i = 2; i < answer.size(); i++)
	{
		cout << answer[i] << "\n";
	}
}