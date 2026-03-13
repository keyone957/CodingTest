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
int a, b;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> a >> b;
    queue<pair<long long , int>> q;
    q.push({ a,1 });//현재 수, 연산횟수
    while (!q.empty())
    {
        pair<long long , int> cur = q.front();
        q.pop();
        if (cur.first == b)
        {
            cout << cur.second ;
            return 0;
        }
        if ((cur.first) * 2 <= b)
        {
            q.push({ cur.first * 2,cur.second + 1 });
        }
        if((cur.first*10)+1<=b)
        {
            q.push({ cur.first * 10 + 1,cur.second + 1 });
        }
    }
    cout << -1;
}