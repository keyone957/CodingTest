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
vector<pair<int, int>> graph[100001];
long long minDist[100001];
vector<int> endNodes;
void bfs(vector<int> startNodes)
{
	priority_queue<pair<long long, int>> pq;
	
	for (int i = 0; i < startNodes.size(); i++)
	{
		pq.push({ 0,endNodes[i] });
		minDist[endNodes[i]] = 0;
	}
	while (!pq.empty())
	{
		int cur = pq.top().second;
		long long dist = -pq.top().first;
		pq.pop();
		if (minDist[cur] < dist)continue;
		for (int i = 0; i < graph[cur].size(); i++)
		{
			long long cost = dist + graph[cur][i].second;
			if (cost < minDist[graph[cur][i].first])
			{
				minDist[graph[cur][i].first] = cost;
				pq.push(make_pair(-cost, graph[cur][i].first));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int node, edge, answerNode;

	cin >> node >> edge >> answerNode;
	for (int i = 0; i < edge; i++)
	{
		int start, end, dist;
		cin >> start >> end >> dist;
		graph[end].push_back({ start,dist });
	}
	fill(minDist, minDist +node+1, 0x7f7f7f7f7f7f);
	for (int i = 0; i < answerNode; i++)
	{
		int endNode;
		cin >> endNode;
		endNodes.push_back(endNode);
	}
	bfs(endNodes);
	int idx = max_element(minDist + 1, minDist + node + 1) - minDist;
	long long maxDist = minDist[idx];

    cout << idx << "\n" << maxDist << "\n";
	
}