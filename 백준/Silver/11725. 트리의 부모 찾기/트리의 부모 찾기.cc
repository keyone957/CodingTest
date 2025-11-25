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
vector<int> arr[100001];
vector<int> parent;
int n;
void bfs(int cur)
{
    queue<int> q;
    q.push(cur);
    //parent[cur] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
       
        for (int i = 0; i < arr[cur].size(); i++)
        {
            int next = arr[cur][i];
            if (parent[cur] == next) continue;
            q.push(next);
            parent[next] = cur;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    parent.resize(n + 1);
    for (int i = 0; i < n-1; i++)
    {
        int start, end;
        cin >> start >> end;
        arr[start].push_back(end);
        arr[end].push_back(start);
    }
    bfs(1);
    for (int i = 2; i <= n; i++)
    {
        cout << parent[i]<<'\n';
    }
}