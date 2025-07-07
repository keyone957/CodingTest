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
int arr[100001];
int dist[100001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    queue<int> q;
    q.push(N);
    dist[N] = 1;//시작 1로 초기화(방문처리)
    while (!q.empty())
    {
        int cur = q.front(); q.pop();
        if (cur == K)
        {
            cout << dist[cur] - 1;
            return 0;
        }
        if (cur - 1 >= 0 && !dist[cur - 1]) {
            dist[cur - 1] = dist[cur] + 1;
            q.push(cur - 1);
        }
        if (cur + 1 <= 100000 && !dist[cur + 1]) {
            dist[cur + 1] = dist[cur] + 1;
            q.push(cur + 1);
        }
        if (cur * 2 <= 100000 && !dist[cur * 2]) {
            dist[cur * 2] = dist[cur] + 1;
            q.push(cur * 2);
        }
    }
}