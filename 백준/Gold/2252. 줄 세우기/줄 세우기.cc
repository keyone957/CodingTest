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
int indegree[32001];
vector<int> input[32001];
queue<int> q;
vector<int>result;
int n, m;
/*
번호 a가  b 앞에 서야한다는 의미
*/
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >>n >> m;
    for (int i = 0; i < m; i++)
    {
        int start, end;
        cin >> start >> end;
        input[start].push_back(end);
        indegree[end]++;
    }
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
        result.push_back(cur);
        for (int i = 0; i < input[cur].size(); i++)
        {
            int next = input[cur][i];
            indegree[next]--;
            if (indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i]<<' ';
    }
}