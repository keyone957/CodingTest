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
/*
난이도 순서.
1번 문제를 풀고 나면 4번 문제가 쉽게 풀림

1. n개의 문제는 모두 풀어야함
2. 먼저 푸는 것이 좋은 문제를 반드시 먼저 풀어야함
3. 가능하면 쉬운 문제부터 풀어야함

*/
using namespace std;
int n, m;
vector<int> linkedArr[32001];
int indegree[32001];
priority_queue<int,vector<int>,greater<int>> pq;
vector<int> result;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        linkedArr[start].push_back(end);
        indegree[end]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            pq.push(i);
        }
    }
    while (!pq.empty())
    {
        int cur = pq.top();
        pq.pop();
        result.push_back(cur);
        for (int i = 0; i < linkedArr[cur].size(); i++)
        {
            int next = linkedArr[cur][i];
            indegree[next]--;
            if (indegree[next] == 0)
            {
                //result.push_back(next);
                pq.push(next);
            }
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i]<<' ';
    }
}