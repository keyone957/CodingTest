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
#include <unordered_set>
#include<unordered_map>
#include<math.h>
using namespace std;
vector<pair<int,int>> adj[100001];
vector<int> dist;
int v;
void bfs(int startNode)
{
    queue<pair<int, int>> q;
    q.push({ startNode,0 });
    dist[startNode] = 0;
    while (!q.empty())
    {
        pair<int,int> cur = q.front();
        int curNode = cur.first;
        int curDist = cur.second;
        q.pop();
        for (int i = 0; i < adj[curNode].size(); i++)
        {
            int node = adj[curNode][i].first;
            int cost = adj[curNode][i].second;
            if (dist[node] == -1)
            {
                dist[node] = curDist + cost;
                q.push({ node,curDist +cost });
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v;
    for (int i = 0; i < v; i++)
    {
        int start;
        cin >> start;
        while (1)
        {
            int end, cost;
            cin >> end;
            if (end == -1)
            {
                break;
            }
            cin >> cost;
            adj[start].push_back({ end,cost });
        }
    }
    dist.resize(v + 1, -1);
    bfs(1);
    int firstNode = 1;//일단 제일 거리가 먼 노드
    int maxDist = -1;
    for (int i = 1; i <= v; i++)
    {
        if (dist[i] > maxDist)
        {
            maxDist = dist[i];
            firstNode = i;
        }
    }
    dist.assign(v + 1, -1); // -1로 다시 초기화
    bfs(firstNode);

    int answer = *max_element(dist.begin() + 1, dist.end());
    cout << answer;
}
