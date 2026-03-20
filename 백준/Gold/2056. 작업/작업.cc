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
/*
수행작업 n개 각 작업마다 걸리는 시간 

입력
해당 노드가 작업을 끝마치는 시간 , 선행작업의 개수 , 선행관계에 있는 작업들의 번호
*/
int n;
int indegree[10001];
vector<int> adj[10001];
int cost[10001];
int answer[10001];//현재 작업까지 왔을때 최소 작업시간?
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int time, firstCnt;//작업 시간, 선행관계에 있는 작업들의 개수
        cin >> time >> firstCnt;
        cost[i] = time;
        answer[i] = time;
        while (firstCnt--)
        {
            int end;
            cin >> end;
            adj[end].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < adj[cur].size(); i++)
        {
            int next = adj[cur][i];
            indegree[next]--;
            answer[next] = max(answer[next], cost[next] + answer[cur]);
            if (indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
    //cout << answer[n];
    int cnt = -1;
    for (int i = 1; i <= n; i++)
    {
        cnt = max(cnt, answer[i]);
    }
    cout << cnt;
}