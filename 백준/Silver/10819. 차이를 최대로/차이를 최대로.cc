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
int N;
vector<int> arr;
vector<int> arr2;//현재까지 만든 순열을 담을 곳
vector<bool> visited;
int curSum=0;
int answerSum=-1;
void dfs(int cur)
{
    if (cur == N)
    {
        answerSum = max(answerSum, curSum);
        return;
    }
    for (int i = 0; i < N; i++)
    {
        if(visited[i]) continue;

        int add = 0;
        if (cur > 0)
        {
            add = abs(arr2[cur - 1] - arr[i]);
        }

        // 선택
        visited[i] = true;
        arr2[cur] = arr[i];
        curSum += add;

        dfs(cur + 1);

        // 복구
        curSum -= add;
        visited[i] = false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    arr.resize(N);
    visited.resize(N);
    arr2.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    dfs(0);
    cout << answerSum << '\n';
}