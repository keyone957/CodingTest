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
#include<cstring>
using namespace std;
int n, m;
vector<int> linkedArr[10001];
int visitedCnt[10001];

void bfs(int startNode)
{
    bool isVisited[10001] = {false};
    queue<int> q;
    q.push({ startNode });
    isVisited[startNode] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < linkedArr[cur].size(); i++)
        {
            int next = linkedArr[cur][i];
            if (!isVisited[next])
            {
                q.push({ next });
                isVisited[next] = true;
                visitedCnt[startNode]++;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        linkedArr[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        bfs(i);
    }
    int maxCnt = -1;
    for (int i = 1; i <= n; i++)
    {
        maxCnt = max(maxCnt, visitedCnt[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (maxCnt == visitedCnt[i])
        {
            cout << i << ' ';
        }
    }
}