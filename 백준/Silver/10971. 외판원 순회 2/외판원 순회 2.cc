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
using namespace std;
int w[11][11];
bool visited[11];
int answer = 1e9f;
int N;
void dfs(int cur, int count, int dist)
{
    if (dist >= answer)
    {
        return;
    }
    if (count == N)
    {
        if (w[cur][0] > 0)
        {
            answer = min(answer, dist+ w[cur][0]);
        }
        return;
    }
    for (int next = 0; next < N; next++)
    {
        if (!visited[next] && w[cur][next] > 0)
        {
            visited[next] = true;
            dfs(next, count + 1, dist + w[cur][next]);
            visited[next] = false;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //int count;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> w[i][j];
        }
    }
    visited[0] = true;
    dfs(0, 1, 0);
    cout << answer;
}
 