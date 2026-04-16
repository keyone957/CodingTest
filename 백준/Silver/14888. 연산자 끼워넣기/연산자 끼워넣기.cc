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
+ - * /
*/
int op[4];
int arr[12];
int minValue = 1e9;
int maxValue = -1e9;
int n;
int opCnt = 0;
void dfs(int count, int cur)
{
    if (count == opCnt+1)
    {
        minValue = min(minValue, cur);
        maxValue = max(maxValue, cur);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (op[i] > 0)
        {
            op[i]--;
            int next;
            if (i == 0) next = cur + arr[count];
            else if (i == 1) next = cur - arr[count];
            else if (i == 2) next = cur * arr[count];
            else next = cur / arr[count];
            dfs(count + 1, next);
            op[i]++;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> op[i];
        opCnt += op[i];
    }
    dfs(1, arr[0]);
    cout << maxValue << '\n' << minValue;
}