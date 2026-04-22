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
int n;
int sour[11];
int bitter[11];
int answer = 1e9;
/*
신맛 -> 사용한 재료들의 신맛의 곱
쓴맛 -> 사용한 재료들의 합
*/
void func(int a,int curSour,int curBitter)
{
    if (a == n)
    {
        if (curBitter != 0)
        {
            int result = abs(curBitter - curSour);
            answer = min(answer, result);
            return;
        }
        else
        {
            return;
        }
    }
    
   
    func(a + 1, curSour * sour[a], curBitter + bitter[a]);
    func(a + 1, curSour, curBitter);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> sour[i] >> bitter[i];
    }
    func(0, 1, 0);
    cout << answer;
}