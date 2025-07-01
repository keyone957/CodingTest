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
using namespace std;
vector<vector<int>> linkedArr; 
vector<bool> visited;
vector<int> dist;
vector<int> answerArr;
void bfs(int startNode)
{
    queue<int> Q;
    Q.push(startNode);
    visited[startNode] = true;
    dist[startNode] = 0;
    while (!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        for (int i = 0; i < linkedArr[cur].size(); i++)
        {
            int next = linkedArr[cur][i];
            if (!visited[next])
            {
                Q.push(next);
                visited[next] = true;
                dist[next] = dist[cur] + 1;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i < dist.size(); i++)
    {
        sum += dist[i];
    }
    answerArr[startNode] = sum;

}
void clear()
{
    fill(visited.begin(), visited.end(), false);
    fill(dist.begin(), dist.end(), 0);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    linkedArr.resize(N + 1);
    visited.resize(N + 1);
    dist.resize(N + 1);
    answerArr.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int start, end;
        cin >> start >> end;
        linkedArr[start].push_back(end);
        linkedArr[end].push_back(start);
    }
    for (int i = 1; i <= N; i++)
    {
        bfs(i);
        clear();
    }
    int minScore = *min_element(answerArr.begin() + 1, answerArr.end());
    for (int i = 1; i <= N; i++)
    {
        if (answerArr[i] == minScore)
        {
            cout << i << endl;
            return 0;
        }
    }
}