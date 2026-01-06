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
/*
n 지역개수
m 최대 수색 범위
r 길 개수

n개의 숫자로 각 구역에 아이템 수

간선 개수 만큼 startnode end node 간선 비용

최대 아이템 개수
*/
int n, m, r;

vector<pair<int,int>> adj[101];
int item[101];
int minDist[101];
int answer = 0;
void bfs(int curNode)
{
    fill(minDist, minDist + n + 1, 1e9);
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,curNode});
    minDist[curNode] = 0;
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if (minDist[cur] < cost) continue;

        for (int i = 0; i < adj[cur].size(); i++)
        {
            int nCost = cost + adj[cur][i].second;
            if (nCost < minDist[adj[cur][i].first])
            {
                minDist[adj[cur][i].first] = nCost;
                pq.push({ -nCost,adj[cur][i].first });
            }
        }
    }
    int itemCost=0;
    for (int i = 1; i <= n; i++)
    {
        if (minDist[i] <= m)
        {
            itemCost += item[i];
        }
    }
    answer = max(answer, itemCost);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> item[i];
    }
    for (int i = 0; i < r; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
      
        adj[start].push_back({end,cost});
        adj[end].push_back({ start,cost });
    }

    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }
    cout << answer;
}