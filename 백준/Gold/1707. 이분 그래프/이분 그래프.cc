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
vector<int> adj[20001];
int isVisited[20001];
/*
이분 그래프
->각 노드를 두개의 그룹으로 나눌 수 있고
인접한 노드가 서로 다른 집합에 속할때

일단 사이클이 발생하지 않으면 무조건 이분 그래프가 가능함

사이클이 발생했을때도 가능한 경우는 있음
-> 사이클이 발생했을때 사이클을 이루고 있는 간선의 개수가 짝수개 일때는 가능함./

dfs도중 이미 방문한 노드가 나와 같은 집합이면 그거는 이제 이분 그랲이 아님

모든 노드에서 dfs돌리는이유
-> 이 그래프는 다 연결되어있는게 아닐 수도 있음.

*/
int k;
void clear(int size)
{
    fill(isVisited, isVisited + size + 1, -1);
    for (int i = 0; i <= size; i++)
    {
        adj[i].clear();
    }
}

bool bfs(int startNode)
{
    queue<int> q;
    q.push(startNode);
    isVisited[startNode] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            if (isVisited[next] == -1)
            {
                isVisited[next] = 1 - isVisited[cur];
                q.push(next);
            }
            else if(isVisited[next]==isVisited[cur])//이미 방문했는데 같은 그룹이면 이분 그래프 성립 X
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> k;
    while (k--)
    {
        int v,e;
        cin >> v >> e;
        clear(v);
        for (int i = 0; i < e; i++)
        {
            int start, end;
            cin >> start >> end;
            adj[start].push_back(end);
            adj[end].push_back(start);
        }
        bool isGraph = true;
        for (int i = 1; i <= v; i++)
        {
            if (isVisited[i] == -1)
            {
                if (!bfs(i))
                {
                    isGraph = false;
                    break;
                }
            }
        }
        if (isGraph)
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }
}