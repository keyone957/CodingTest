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
각 위치에서 왼쪽으로 레이저를 쏜다 했을 때 자신 보다 높은 곳에 레이저를 송신함
이제 현재 탑에서 레이저 수신을 받는 위치를 출력
만일 레이저 신호를 수신하지 않으면 0출력

*/
int n;
int tower[500001];
pair<int, int> tinfo;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> tower[i];
    }
    stack<pair<int,int>> s;
    for (int i = 1; i <= n; i++)
    {
        while (!s.empty()&&s.top().first<tower[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            cout << 0 << ' ';
        }
        else
        {
            cout << s.top().second<<' ';
        }
        s.push({ tower[i],i });
    }
}