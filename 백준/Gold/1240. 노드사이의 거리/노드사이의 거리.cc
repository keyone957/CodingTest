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
vector<pair<int,int>> adj[1001];
int n, m;
bool isVisited[1001];
/*
노드 n 
거리를 알고싶은 노드 쌍의 개수 m

*/

int bfs(int start, int end)
{
    fill(isVisited, isVisited + 1001, false);
    int cost=0;
    queue<pair<int, int>> q;
    q.push({ start,0 });
    isVisited[start] = true;
    while (!q.empty())
    {
        pair<int, int> cur = q.front(); 
        q.pop();
        int curNode = cur.first;
        int cost = cur.second;
        if (cur.first == end)
        {
            return cost;
        }
        for (int i = 0; i < adj[curNode].size(); i++)
        {
            int nextNode = adj[curNode][i].first;
            int nextNodeCost = adj[curNode][i].second;
            if (!isVisited[nextNode])
            {
                isVisited[nextNode] = true;
                q.push({ nextNode,cost + nextNodeCost });
            }
        }
        

    }
    //return cost;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n - 1; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        adj[start].push_back({ end,cost });
        adj[end].push_back({ start,cost });
    }

    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        cout << bfs(start, end) << '\n';
    }
}