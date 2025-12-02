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
/*

n,m
00 만나면 입력 끝
트리는 사이클이 없음
간선이 (정점-1)개
6 3
1 2
2 3
3 4
6 5
1 2
2 3
3 4
4 5
5 6
6 6
1 2
2 3
1 3
4 5
5 6
6 4
0 0
*/
using namespace std;
int parent[501];
bool isVisited[501];
vector<int> adj[501];
int testCase = 0;
void clear(int n)
{
    fill(parent, parent + n + 1, 0);
    fill(isVisited, isVisited + n + 1, false);
    for (int i = 1; i <=n; i++)
    {
        adj[i].clear();
    }
}
bool bfs(int node)
{
    bool isTree = true;
    queue<int> q;
    q.push(node);
    isVisited[node] = true;
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            if (parent[cur] == next) continue;
            if (isVisited[next])
            {
                isTree = false;
                continue;
            }
            q.push(next);
            parent[next] = cur;
            isVisited[next] = true;
        }
    }
    return isTree;
}
void answer(int count)
{
    cout << "Case " << testCase << ": ";
    if (count == 0)
    {
        cout << "No trees." << "\n";
    }
    else if (count == 1)
    {
        cout << "There is one tree." << "\n";
    }
    else
    {
        cout << "A forest of " << count << " trees." << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1)
    {
        int n, m;
        cin >> n >> m;
        int count = 0;
        if (n == 0 && m == 0)
        {
            break;
        }
        clear(n);
        testCase++;
        for (int i = 0; i < m; i++)
        {
            int start, end;
            cin >> start >> end;
            adj[start].push_back(end);
            adj[end].push_back(start);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!isVisited[i])
            {
                if (bfs(i) == true)
                {
                    count++;
                }
            }
        }
        answer(count);
    }
}