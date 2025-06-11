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
vector<pair<int, int>> graph[1000];
vector<int> minDist;
int node, edge, endNode;
void bfs(int startNode)
{
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,startNode });
    minDist[startNode] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();
        if (dist > minDist[cur]) continue;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int cost = dist + graph[cur][i].second;
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

    cin >> node >> edge >> endNode;

    for (int i = 0; i < edge; i++)
    {
        int start, end, dist;
        cin >> start >> end >> dist;
        graph[start].push_back({ end,dist });
    }
    minDist.resize(node + 1, 1e9);

    bfs(endNode);
    vector<int> distFromEnd = minDist; // X→각 마을

    // 2. 각 노드에서 endNode까지의 최단거리 (왕복 "가는 길")
    vector<int> distToEnd(node + 1, 1e9);
    for (int i = 1; i <= node; ++i) {
        minDist.assign(node + 1, 1e9);
        bfs(i);
        distToEnd[i] = minDist[endNode]; // i→X
    }

    // 3. 왕복 시간 최댓값 찾기
    int answer = -1;
    for (int i = 1; i <= node; ++i) {
        if (distToEnd[i] < 1e9 && distFromEnd[i] < 1e9) {
            int roundTrip = distToEnd[i] + distFromEnd[i];
            answer = max(answer, roundTrip);
        }
    }
    cout << answer << '\n';
    
  
}