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
int n;
int removeNode;
vector<int> adj[51];
int parent[51];
int answer = 0;
void bfs(int cur)
{
    queue<int> q;
    q.push(cur);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        int childCount=0;
        for (int i = 0; i < adj[cur].size(); i++)
        {
            
            int next = adj[cur][i];
            //if (parent[cur] == next) continue;
            if (next == removeNode) continue;
            childCount++;
            parent[next] = cur;
            q.push(next);
        }
        if (childCount == 0)
        {
            answer++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    int rootNode=0;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        if (input != -1)
        {
            adj[input].push_back(i);
        }
        else
        {
            rootNode = i;
        }
        
    }
    cin >> removeNode;
    if (rootNode == removeNode)
    {
        cout << 0;
        return 0;
    }
    bfs(rootNode);

    cout << answer ;
}