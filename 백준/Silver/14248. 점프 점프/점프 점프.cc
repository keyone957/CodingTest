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
int n,s;
bool visit[100001];
int arr[100001];
int answer = 1;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cin >> s;
    queue<int> q;
    q.push({ s });
    visit[s] = true;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        int plusNext=cur+arr[cur];
        int minusNext=cur-arr[cur];
        if (plusNext<=n&&!visit[plusNext])
        {
            q.push(plusNext);
            visit[plusNext] = true;
            answer++;
        }
        if (minusNext > 0 && !visit[minusNext])
        {
            q.push(minusNext);
            visit[minusNext]=true;
            answer++;
        }
    }
    cout << answer;
}