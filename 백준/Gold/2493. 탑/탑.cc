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
/*
6 9 5 7 4 <-
왼쪽 방향으로 레이저 신호 발사

*/
stack<pair<int,int>> tower;//높이, 타워 index
int answer[500000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {   
        int input;
        cin >> input;
        int index=0;
        while (!tower.empty()&&tower.top().first < input)
        {
            index++;
            tower.pop();
        }
        if (tower.empty())
        {
            answer[i] = 0;
        }
        else
        {
            answer[i] = tower.top().second + 1;
        }
        tower.push({ input,i });

    }
    for (int i = 0; i < n; i++)
    {
        cout << answer[i] << ' ';
    }
}